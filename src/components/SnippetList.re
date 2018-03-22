open Snippet;

open Utils.React;

let component = ReasonReact.statelessComponent("SnippetList");

let make = (~snippets, _children) => {
  ...component,
  render: _self =>
    <ol> (eleOfList(Belt.List.mapU(snippets, [@bs] snippet => <Snippet snippet key=snippet.id />))) </ol>
};
