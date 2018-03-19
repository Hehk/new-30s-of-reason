open Utils.React;

let component = ReasonReact.statelessComponent("Page.Index");

let make = _children => {...component, render: _self => <div> (eleOfStr("hello World")) </div>};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
