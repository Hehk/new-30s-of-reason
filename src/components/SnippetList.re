open Types;

open Utils.React;

let component = ReasonReact.statelessComponent("SnippetList");

let make = (_children) => {
  ...component,
  render: _self =>
    <ol>
      (
        eleOfArr(
          Belt.Array.mapU(Utils.Snippets.getSnippets(),
            [@bs] (snippet => <Snippet snippet key=snippet.id />)
          )
        )
      )
    </ol>
};
