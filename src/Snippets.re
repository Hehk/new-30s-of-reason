type code = {
  re: string,
  js: string,
  test: string,
};

type t = {
  code,
  title: string,
  tags: list(string),
  modules: list(string),
  description: string,
  notes: list(string),
  id: string,
};

module Decode = {
  type rawSnippetFile = {
    tags: string,
    modules: string,
    bodyContent: string,
    bodyHtml: string,
    title: string,
  };
  open! Json.Decode;
  let defaultString = opt =>
    switch (opt) {
    | Some(x) => x
    | None => ""
    };
  let getList = opt =>
    switch (opt) {
    | Some(x) => Js.String.split(",", x) |> Belt.List.fromArray |> Belt.List.map(_, Js.String.trim)
    | None => []
    };
  let convertRawToSnippet = value => {
    let get = Js.Dict.get(value);
    {
      code: {
        re: "",
        js: "",
        test: "",
      },
      id: defaultString(get("base")),
      title: defaultString(get("title")),
      tags: getList(get("tags")),
      modules: getList(get("modules")),
      description: "",
      notes: [],
    };
  };
  let fileMap = json => json |> field("fileMap", dict(dict(string)));
  let snippetFile = json => {
    tags: json |> field("tags", string),
    modules: json |> field("modules", string),
    bodyContent: json |> field("bodyContent", string),
    bodyHtml: json |> field("bodyHtml", string),
    title: json |> field("title", string),
  };
};

let summaryJson: Js.Json.t = [%bs.raw {| require('../snippets/summary.json') |}];

/* Setup as a simple cache to prevent repeated file reads */
let snippetCache = ref(None);

let load = () => summaryJson |> Decode.fileMap |> Js.Dict.values |> Belt.Array.map(_, Decode.convertRawToSnippet);

let get = () =>
  switch (snippetCache^) {
  | None =>
    let snippets = load();
    snippetCache := Some(snippets);
    snippets;
  | Some(x) => x
  };
