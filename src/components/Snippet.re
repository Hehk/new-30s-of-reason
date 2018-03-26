open Utils.React;

open Types;

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
      <ul className=(makeCls(Styles.tagList))>
        (
          Belt.List.map(snippet.tags, tag => <li className=(makeCls(Styles.tag)) key=tag> (eleOfStr(tag)) </li>)
          |> eleOfList
        )
      </ul>
    </li>
};
