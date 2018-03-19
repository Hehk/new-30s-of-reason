open Utils.React;

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
    render: _self => <div>(eleOfStr("hello world"))</div>
};
