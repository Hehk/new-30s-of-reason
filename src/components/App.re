open Header;

let component = ReasonReact.statelessComponent("App");

let links = [
  {href: "about", text: "About"},
  {href: "https://github.com/30s-of-reason", text: "Github"}
];

let make = _children => {...component, render: _self => <Fragment> <Header links /> </Fragment>};
