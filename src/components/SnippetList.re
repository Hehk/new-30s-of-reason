open Snippets;

open Utils.React;

module Snippet = {
  module Styles = {
    let tag = ["bg-light-red", "di", "mr1", "pa1", "br1", "white"];
    let tagList = ["list", "pa0"];
    let title = ["normal", "mt0", "f4"];
    let snippet = ["pv3", "mv2"];
  };
  let component = ReasonReact.statelessComponent("Snippet");
  let make = (~snippet, _children) => {
    ...component,
    render: _self =>
      <li className=(c(Styles.snippet))>
        <h2 className=(c(Styles.title))> (eleOfStr(snippet.title)) </h2>
        <p> (eleOfStr(snippet.description)) </p>
        <code> (eleOfStr(snippet.code.re)) </code>
        <ul className=(c(Styles.tagList))>
          (
            snippet.tags
            |> Belt.List.map(_, tag => <li className=(c(Styles.tag)) key=tag> (eleOfStr(tag)) </li>)
            |> eleOfList
          )
        </ul>
      </li>,
  };
};

let component = ReasonReact.statelessComponent("SnippetList");

module Styles = {
  let wrapper = ["w-100", "ph5-ns"];
  let list = ["list", "pa0", "mw8", "center", "mv0"];
};

let make = _children => {
  ...component,
  render: _self =>
    <main className=(c(Styles.wrapper))>
      <ol className=(c(Styles.list))>
        (get() |> Belt.Array.map(_, snippet => <Snippet snippet key=snippet.id />) |> eleOfArr)
      </ol>
    </main>,
};
