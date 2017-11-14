let getItem:
  (string, ~callback: (option(Js.Exn.t), option(string)) => unit=?, unit) =>
  Js.Promise.t(option(string));

let setItem: (string, string, ~callback: option(Js.Exn.t) => unit=?, unit) => Js.Promise.t(unit);

let removeItem: (string, ~callback: option(Js.Exn.t) => unit=?, unit) => Js.Promise.t(unit);

let mergeItem: (string, string, ~callback: option(Js.Exn.t) => unit=?, unit) => Js.Promise.t(unit);

let clear: (~callback: option(Js.Exn.t) => unit=?, unit) => Js.Promise.t(unit);

let getAllKeys:
  (~callback: (option(Js.Exn.t), option(array(string))) => unit=?, unit) =>
  Js.Promise.t(option(array(string)));

[@bs.scope "AsyncStorage"] [@bs.module "react-native"] external flushGetRequests : unit => unit =
  "";

let multiGet:
  (
    array(string),
    ~callback: (option(array(Js.Exn.t)), option(array(array(string)))) => unit=?,
    unit
  ) =>
  Js.Promise.t(option(array(array(string))));

let multiSet:
  (array((string, string)), ~callback: option(array(Js.Exn.t)) => unit=?, unit) =>
  Js.Promise.t(unit);

let multiRemove:
  (array(string), ~callback: option(array(Js.Exn.t)) => unit=?, unit) => Js.Promise.t(unit);

let multiMerge:
  (array((string, string)), ~callback: option(array(Js.Exn.t)) => unit=?, unit) =>
  Js.Promise.t(unit);
