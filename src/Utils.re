module React = {
  let eleOfStr = ReasonReact.stringToElement;
  let eleOfArr = ReasonReact.arrayToElement;
  let eleOfList = x => x |> Belt.List.toArray |> eleOfArr;
  let c = cls => cls |> Belt.List.reduce(_, "", (a, b) => a ++ " " ++ b);
  module type Component = {
    open ReasonReact;
    let component: componentSpec(stateless, stateless, noRetainedProps, noRetainedProps, actionless);
    let make:
      array(reactElement) =>
      componentSpec(stateless, stateless, noRetainedProps, noRetainedProps, actionless);
  };
  let comp = (~cls, ~tag, displayName) : (module Component) =>
    (module
     {
       let component = ReasonReact.statelessComponent(displayName);
       let make = children => {
         ...component,
         render: _self => ReasonReact.createDomElement(tag, ~props={"className": c(cls)}, children)
       };
     });
};
