module React = {
  let eleOfStr = ReasonReact.stringToElement;
  let eleOfArr = ReasonReact.arrayToElement;
  let eleOfList = x => x |> Belt.List.toArray |> eleOfArr;
  let makeCls = x => Belt.List.reduce(x, "", (a, b) => a ++ " " ++ b);
};

module Snippets = {
  module Decode = {
    open! Json.Decode;
    let fileMap = json => json |> field("fileMap", dict(dict(string)));
  };
  let summaryJson: Js.Json.t = [%bs.raw {| require('../snippets/summary.json') |}];
  let optionToString = opt =>
    switch opt {
    | Some(x) => x
    | None => ""
    };
  let convertRawToSnippet = value =>
    Types.{
      code: {
        re: "",
        js: "",
        test: ""
      },
      id: optionToString(Js.Dict.get(value, "base")),
      title: optionToString(Js.Dict.get(value, "title")),
      tags: [],
      description: "",
      notes: []
    };
  let getSnippets = () =>
    Belt.Array.map(summaryJson |> Decode.fileMap |> Js.Dict.values, convertRawToSnippet);
};

Js.log(Snippets.getSnippets());
