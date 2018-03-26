open Header;

open Utils.React;

let component = ReasonReact.statelessComponent("App");

let links = [
  {href: "about", text: "About"},
  {href: "https://github.com/30s-of-reason", text: "Github"}
];

module Style = {
  let wrapper = ["flex", "items-start", "sans-serif"];
  let main = ["w-100"];
};

let make = _children => {
  ...component,
  render: _self =>
    <div className=(c(Style.wrapper))>
      <SideBar />
      <div className=(c(Style.main))>
        <Header links />
        <SnippetList />
      </div>
    </div>
};
