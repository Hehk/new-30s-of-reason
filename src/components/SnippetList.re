open Snippets;

open Utils.React;

module Snippet = {
  module Styles = {
    let tag = ["bg-light-red", "di", "mr1", "pa1", "br1", "white"];
    let tagList = ["list", "pa0"];
  };
  let component = ReasonReact.statelessComponent("Snippet");
  let make = (~snippet, _children) => {
    ...component,
    render: _self =>
      <li>
        <h2> (eleOfStr(snippet.title)) </h2>
        <p> (eleOfStr(snippet.description)) </p>
        <code> (eleOfStr(snippet.code.re)) </code>
        <ul className=(c(Styles.tagList))>
          (
            Belt.List.map(snippet.tags, tag =>
              <li className=(c(Styles.tag)) key=tag> (eleOfStr(tag)) </li>
            )
            |> eleOfList
          )
        </ul>
      </li>
  };
};

let component = ReasonReact.statelessComponent("SnippetList");

module Styles = {
  let list = ["list", "pa0", "w-100", "mw8", "center"];
};

let make = _children => {
  ...component,
  render: _self =>
    <ol className=(c(Styles.list))>
      (eleOfArr(Belt.Array.map(get(), snippet => <Snippet snippet key=snippet.id />)))
    </ol>
};
