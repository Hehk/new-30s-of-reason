module React = {
  let eleOfStr = ReasonReact.stringToElement;
  let eleOfArr = ReasonReact.arrayToElement;
  let eleOfList = x => x |> Belt.List.toArray |> eleOfArr;
  let c = cls => cls |> Belt.List.reduce(_, "", (a, b) => a ++ " " ++ b);
};
