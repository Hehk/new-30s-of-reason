module React = {
  let eleOfStr = ReasonReact.stringToElement;  
  let eleOfArr = ReasonReact.arrayToElement;
  let eleOfList = x => x |> Belt.List.toArray |> eleOfArr;
  let makeCls = (x) => Belt.List.reduceU(x, "", [@bs] (a, b) => a ++ " " ++ b);
};

module Snippets = {
  module Decode = {
    open! Json.Decode;

    let fileMap = json => json |> field("fileMap", dict(dict(string)));
  };
  let summaryJson : Js.Json.t = [%bs.raw {| require('../snippets/summary.json') |}]; 
  let getSnippets = () => summaryJson |> Decode.fileMap;
};

Js.log(Snippets.getSnippets());
