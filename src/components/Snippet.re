open Utils.React;

type code = {
  re: string,
  js: string,
  test: string
};

type t = {
  code,
  title: string,
  tags: list(string),
  description: string,
  notes: list(string),
  id: string
};

let component = ReasonReact.statelessComponent("Snippet");

let make = (~snippet, _children) => {
  ...component,
  render: _self =>
    <li>
      <h2> (eleOfStr(snippet.title)) </h2>
      <p> (eleOfStr(snippet.description)) </p>
      <code> (eleOfStr(snippet.code.re)) </code>
    </li>
};
