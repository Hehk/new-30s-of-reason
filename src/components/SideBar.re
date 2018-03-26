open Utils.React;

open Snippets;

let component = ReasonReact.statelessComponent("Sidebar");

module Styles = {
  let wrapper = ["bg-light-gray", "fl", "w5", "vh-100", "list", "pa0", "ma0"];
};

/* This will eventually form a tree of modules that can be used for searching */
let moduleTree = get();
Js.log(moduleTree);

let make = _children => {
  ...component,
  render: _self =>
    <ol className=(c(Styles.wrapper))>
      (Belt.Array.map(moduleTree, snippet => <li key=snippet.id> (eleOfStr(switch (Belt.List.head(snippet.modules)) {
        | None => "";
        | Some(x) => x; 
        })) </li>) |> eleOfArr)
    </ol>
};
