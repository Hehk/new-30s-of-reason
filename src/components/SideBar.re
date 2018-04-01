open Utils.React;

open Snippets;

let component = ReasonReact.statelessComponent("Sidebar");

module Styles = {
  let wrapper = [
    "bg-light-gray",
    "fl",
    "w5",
    "vh-100",
    "list",
    "pa0",
    "ma0",
  ];
};

/* This will eventually form a tree of modules that can be used for searching */
let moduleTree = get();

module Wrapper = (
  val comp(~cls=Styles.wrapper, ~tag="ol", "SideBar.Wrapper")
);

let make = _children => {
  ...component,
  render: _self =>
    <Wrapper>
      (
        moduleTree
        |> Belt.Array.map(_, snippet =>
             <li key=snippet.id>
               (
                 eleOfStr(
                   switch (Belt.List.head(snippet.modules)) {
                   | None => ""
                   | Some(x) => x
                   },
                 )
               )
             </li>
           )
        |> eleOfArr
      )
    </Wrapper>,
};
