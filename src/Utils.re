module React = {
  let eleOfStr = ReasonReact.stringToElement;  
  let eleOfArr = ReasonReact.arrayToElement;
  let eleOfList = x => x |> Belt.List.toArray |> eleOfArr;
  let makeCls = (x) => Belt.List.reduceU(x, "", [@bs] (a, b) => a ++ " " ++ b);
};
