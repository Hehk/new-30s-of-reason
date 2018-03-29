open Snippets;

open Utils.React;

module Snippet = {
  module Styles = {
    let tag = ["bg-light-red", "di", "mr1", "pa1", "br1", "white"];
    let tagList = ["list", "pa0"];
    let title = ["normal", "mt0", "f4"];
    let snippet = ["pv3", "mv2"];
  };
  let prefix = "Snippet";
  module Title = (val comp(~cls=Styles.title, ~tag="h2", prefix ++ ".Title"));
  module Tag = (val comp(~cls=Styles.tag, ~tag="li", prefix ++ ".Tag"));
  module TagList = (val comp(~cls=Styles.tagList, ~tag="ul", prefix ++ ".TagList"));
  module Wrapper = (val comp(~cls=Styles.snippet, ~tag="li", prefix ++ ".Wrapper"));
  let component = ReasonReact.statelessComponent("Snippet");
  let make = (~snippet, _children) => {
    ...component,
    render: _self =>
      <Wrapper>
        <Title> (eleOfStr(snippet.title)) </Title>
        <p> (eleOfStr(snippet.description)) </p>
        <code> (eleOfStr(snippet.code.re)) </code>
        <TagList>
          (
            snippet.tags
            |> Belt.List.map(_, tag => <Tag key=tag> (eleOfStr(tag)) </Tag>)
            |> eleOfList
          )
        </TagList>
      </Wrapper>,
  };
};

let component = ReasonReact.statelessComponent("SnippetList");

module Styles = {
  let wrapper = ["w-100", "ph5-ns"];
  let list = ["list", "pa0", "mw8", "center", "mv0"];
};

let prefix = "SnippetList";

module Wrapper = (val comp(~cls=Styles.wrapper, ~tag="main", prefix ++ ".Wrapper"));

module List = (val comp(~cls=Styles.list, ~tag="ol", prefix ++ ".List"));

let make = _children => {
  ...component,
  render: _self =>
    <Wrapper>
      <List>
        (get() |> Belt.Array.map(_, snippet => <Snippet snippet key=snippet.id />) |> eleOfArr)
      </List>
    </Wrapper>,
};
