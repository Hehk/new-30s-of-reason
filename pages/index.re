open Utils.React;

[%bs.raw {|require('tachyons/css/tachyons.css')|}];

let component = ReasonReact.statelessComponent("Page.Index");

let make = _children => {...component, render: _self => <App />};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
