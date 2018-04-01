open Utils.React;

type link = {
  text: string,
  href: string,
};

let component = ReasonReact.statelessComponent("Header");

module Styles = {
  let wrapper = ["w-100", "pa3", "ph5-ns", "b--light-gray", "bb"];
  let pageFrame = ["w-100", "mw8", "center", "f4", "sans-serif"];
  let link = ["link", "dim", "dark-gray"];
  let smallLink = ["ml4", "dark-gray", ...link];
  let linkList = ["fr"];
};

let prefix = "Header";

module Wrapper = (val comp(~cls=Styles.wrapper, ~tag="header", prefix ++ ".Wrapper"));

module PageFrame = (val comp(~cls=Styles.pageFrame, ~tag="header", prefix ++ ".PageFrame"));

module LinkList = (val comp(~cls=Styles.linkList, ~tag="div", prefix ++ ".LinkList"));

let make = (~links, _children) => {
  ...component,
  render: _self =>
    <Wrapper>
      <PageFrame>
        <a className=(c(Styles.link)) href="#" title="Home"> (eleOfStr("30s of Reason")) </a>
        <LinkList>
          (
            links
            |> Belt.List.map(_, ({href, text}) =>
                 <a className=(c(Styles.smallLink)) key=href href title="About"> (eleOfStr(text)) </a>
               )
            |> eleOfList
          )
        </LinkList>
      </PageFrame>
    </Wrapper>,
};
