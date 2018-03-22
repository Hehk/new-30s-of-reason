open Utils.React;

let component = ReasonReact.statelessComponent("Sidebar");

module Styles = {
  let wrapper = ["bg-light-gray", "fl", "w5", "vh-100"];
};

let make = _children => {
  ...component,
  render: _self => <div className=(makeCls(Styles.wrapper))> (eleOfStr("sidebar")) </div>
};
