open Header;

open Utils.React;

let component = ReasonReact.statelessComponent("App");

let links = [{href: "about", text: "About"}, {href: "https://github.com/30s-of-reason", text: "Github"}];

module Style = {
  let wrapper = ["flex", "items-start", "sans-serif"];
  let main = ["w-100"];
};

let prefix = "App";

module Wrapper = (val comp(~cls=Style.wrapper, ~tag="div", prefix ++ ".Wrapper"));

module Main = (val comp(~cls=Style.main, ~tag="div", prefix ++ ".Main"));

let make = _children => {
  ...component,
  render: _self => <Wrapper> <SideBar /> <Main> <Header links /> <SnippetList /> </Main> </Wrapper>,
};
