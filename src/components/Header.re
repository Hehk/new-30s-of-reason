open Utils.React;

type link = {
  text: string,
  href: string
};

let component = ReasonReact.statelessComponent("Header");

module Styles = {
  let wrapper = ["w-100", "pa3", "ph5-ns", "b--light-gray", "bb"];
  let pageFrame = ["w-100", "mw8", "center", "f4", "sans-serif"];
  let link = ["link", "dim", "dark-gray"];
  let smallLink = ["ml4", "dark-gray", ...link];
  let linkList = ["fr"];
};

let make = (~links, _children) => {
  ...component,
  render: _self =>
    <header className=(makeCls(Styles.wrapper))>
      <nav className=(makeCls(Styles.pageFrame))>
        <a className=(makeCls(Styles.link)) href="#" title="Home"> (eleOfStr("30s of Reason")) </a>
        <div className=(makeCls(Styles.linkList))>
          (
            eleOfList(
              Belt.List.map(links, ({href, text}) =>
                <a className=(makeCls(Styles.smallLink)) key=href href title="About"> (eleOfStr(text)) </a>
              )
            )
          )
        </div>
      </nav>
    </header>
};
