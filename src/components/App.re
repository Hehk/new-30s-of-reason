open Header;

open Snippet;

open Utils.React;

let component = ReasonReact.statelessComponent("App");

let links = [{href: "about", text: "About"}, {href: "https://github.com/30s-of-reason", text: "Github"}];

let snippets = [
  {
    code: {
      re: "Belt.List.map",
      js: "",
      test: ""
    },
    id: "0",
    title: "map",
    tags: [],
    description: "does cool shit",
    notes: []
  },
  {
    code: {
      re: "Belt.List.reduce",
      js: "",
      test: ""
    },
    id: "1",
    title: "reduce",
    tags: [],
    description: "i hope this works",
    notes: []
  }
];

module Style = {
  let wrapper = ["flex", "items-start"];
  let main = ["w-100"];
};

let make = _children => {
  ...component,
  render: _self =>
    <div className=(makeCls(Style.wrapper))>
      <SideBar />
      <div className=(makeCls(Style.main))>
        <Header links />
        <SnippetList snippets />
      </div>
    </div>
};
