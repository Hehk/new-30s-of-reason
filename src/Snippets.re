type code = {
  re: string,
  js: string,
  test: string
};

type t = {
  code,
  title: string,
  tags: list(string),
  modules: list(string),
  description: string,
  notes: list(string),
  id: string
};

module Decode = {
  open! Json.Decode;
  let defaultString = opt =>
    switch opt {
    | Some(x) => x
    | None => ""
    };
  let getList = opt =>
    switch opt {
    | Some(x) => Belt.List.map(Js.String.split(",", x) |> Belt.List.fromArray, Js.String.trim)
    | None => []
    };
  let convertRawToSnippet = value => {
    let get = Js.Dict.get(value);
    {
      code: {
        re: "",
        js: "",
        test: ""
      },
      id: defaultString(get("base")),
      title: defaultString(get("title")),
      tags: getList(get("tags")),
      modules: getList(get("modules")),
      description: "",
      notes: []
    };
  };
  let fileMap = json => json |> field("fileMap", dict(dict(string)));
};

let summaryJson: Js.Json.t = [%bs.raw {| require('../snippets/summary.json') |}];

/* Setup as a simple cache to prevent repeated file reads */
let snippetCache = ref(None);

let load = () => Belt.Array.map(summaryJson |> Decode.fileMap |> Js.Dict.values, Decode.convertRawToSnippet);

let get = () =>
  switch snippetCache^ {
  | None =>
    let snippets = load();
    snippetCache := Some(snippets);
    snippets;
  | Some(x) => x
  };
