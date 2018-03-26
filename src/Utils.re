open Types;

module React = {
  let eleOfStr = ReasonReact.stringToElement;
  let eleOfArr = ReasonReact.arrayToElement;
  let eleOfList = x => x |> Belt.List.toArray |> eleOfArr;
  let makeCls = x => Belt.List.reduce(x, "", (a, b) => a ++ " " ++ b);
};

module Snippets = {
  module Decode = {
    open! Json.Decode;
    let defaultString = opt =>
      switch opt {
      | Some(x) => x
      | None => ""
      };
    let getTags = opt =>
      switch opt {
      | Some(x) => Belt.List.map(Js.String.split(",", x) |> Belt.List.fromArray, Js.String.trim) 
      | None => []
      };
    let convertRawToSnippet = value =>
      Js.Dict.{
        code: {
          re: "",
          js: "",
          test: ""
        },
        id: defaultString(get(value, "base")),
        title: defaultString(get(value, "title")),
        tags: getTags(get(value, "tags")),
        description: "",
        notes: []
      };
    let fileMap = json => json |> field("fileMap", dict(dict(string)));
  };
  let summaryJson: Js.Json.t = [%bs.raw {| require('../snippets/summary.json') |}];
  /* Setup as a simple cache to prevent repeated file reads */
  let snippets = ref(None);
  let getSnippets = () =>
    switch snippets^ {
    | None =>
      let newSnippets = Belt.Array.map(summaryJson |> Decode.fileMap |> Js.Dict.values, Decode.convertRawToSnippet);
      snippets := Some(newSnippets);
      newSnippets;
    | Some(x) => x
    };
};
