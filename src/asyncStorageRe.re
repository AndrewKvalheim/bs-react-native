let to_opt = (x) => Js.Promise.resolve(Js.Null_undefined.to_opt(x));

let map_cb = (cb, err: Js.Null.t(Js.Exn.t), value) =>
  cb(Js.Null.to_opt(err), Js.Null_undefined.to_opt(value));

let map_cb_multi = (cb, err: Js.Null.t(array(Js.Exn.t)), value) =>
  cb(Js.Null.to_opt(err), Js.Null_undefined.to_opt(value));

let map_cb_err_only = (cb, err: Js.Null.t(Js.Exn.t)) => cb(Js.Null.to_opt(err));

let map_cb_multi_err_only = (cb, err: Js.Null.t(array(Js.Exn.t))) => cb(Js.Null.to_opt(err));

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external _getItem :
  (string, Js.Undefined.t(((Js.Null.t(Js.Exn.t), Js.Null_undefined.t(string)) => unit))) =>
  Js.Promise.t(Js.Null_undefined.t(string)) =
  "getItem";

let getItem = (key, ~callback=?, ()) =>
  switch callback {
  | None => Js.Promise.then_(to_opt, _getItem(key, Js.undefined))
  | Some(cb) => Js.Promise.then_(to_opt, _getItem(key, Js.Undefined.return(map_cb(cb))))
  };

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external _setItem :
  (string, string, Js.Undefined.t((Js.Null.t(Js.Exn.t) => unit))) => Js.Promise.t(unit) =
  "setItem";

let setItem = (key, value, ~callback=?, ()) =>
  switch callback {
  | None => _setItem(key, value, Js.undefined)
  | Some(cb) => _setItem(key, value, Js.Undefined.return(map_cb_err_only(cb)))
  };

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external _removeItem :
  (string, Js.Undefined.t((Js.Null.t(Js.Exn.t) => unit))) => Js.Promise.t(unit) =
  "removeItem";

let removeItem = (key, ~callback=?, ()) =>
  switch callback {
  | None => _removeItem(key, Js.undefined)
  | Some(cb) => _removeItem(key, Js.Undefined.return(map_cb_err_only(cb)))
  };

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external _mergeItem :
  (string, string, Js.Undefined.t((Js.Null.t(Js.Exn.t) => unit))) => Js.Promise.t(unit) =
  "mergeItem";

let mergeItem = (key, value, ~callback=?, ()) =>
  switch callback {
  | None => _mergeItem(key, value, Js.undefined)
  | Some(cb) => _mergeItem(key, value, Js.Undefined.return(map_cb_err_only(cb)))
  };

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external _clear : Js.Undefined.t((Js.Null.t(Js.Exn.t) => unit)) => Js.Promise.t(unit) =
  "clear";

let clear = (~callback=?, ()) =>
  switch callback {
  | None => _clear(Js.undefined)
  | Some(cb) => _clear(Js.Undefined.return(map_cb_err_only(cb)))
  };

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external _getAllKeys :
  Js.Undefined.t(((Js.Null.t(Js.Exn.t), Js.Null_undefined.t(array(string))) => unit)) =>
  Js.Promise.t(Js.Null_undefined.t(array(string))) =
  "getAllKeys";

let getAllKeys = (~callback=?, ()) =>
  switch callback {
  | None => Js.Promise.then_(to_opt, _getAllKeys(Js.undefined))
  | Some(cb) => Js.Promise.then_(to_opt, _getAllKeys(Js.Undefined.return(map_cb(cb))))
  };

[@bs.scope "AsyncStorage"] [@bs.module "react-native"] external flushGetRequests : unit => unit =
  "";

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external _multiGet :
  (
    array(string),
    Js.Undefined.t(
      ((Js.Null.t(array(Js.Exn.t)), Js.Null_undefined.t(array(array(string)))) => unit)
    )
  ) =>
  Js.Promise.t(Js.Null_undefined.t(array(array(string)))) =
  "multiGet";

let multiGet = (keys, ~callback=?, ()) =>
  switch callback {
  | None => Js.Promise.then_(to_opt, _multiGet(keys, Js.undefined))
  | Some(cb) => Js.Promise.then_(to_opt, _multiGet(keys, Js.Undefined.return(map_cb_multi(cb))))
  };

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external _multiSet :
  (array(array(string)), Js.Undefined.t((Js.Null.t(array(Js.Exn.t)) => unit))) =>
  Js.Promise.t(unit) =
  "multiSet";

let multiSet = (keyValues, ~callback=?, ()) => {
  let combine = ((key, value)) => [|key, value|];
  switch callback {
  | None => _multiSet(Array.map(combine, keyValues), Js.undefined)
  | Some(cb) =>
    _multiSet(Array.map(combine, keyValues), Js.Undefined.return(map_cb_multi_err_only(cb)))
  }
};

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external _multiRemove :
  (array(string), Js.Undefined.t((Js.Null.t(array(Js.Exn.t)) => unit))) => Js.Promise.t(unit) =
  "multiRemove";

let multiRemove = (keys, ~callback=?, ()) =>
  switch callback {
  | None => _multiRemove(keys, Js.undefined)
  | Some(cb) => _multiRemove(keys, Js.Undefined.return(map_cb_multi_err_only(cb)))
  };

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external _multiMerge :
  (array(array(string)), Js.Undefined.t((Js.Null.t(array(Js.Exn.t)) => unit))) =>
  Js.Promise.t(unit) =
  "multiMerge";

let multiMerge = (keyValues, ~callback=?, ()) => {
  let combine = ((key, value)) => [|key, value|];
  switch callback {
  | None => _multiMerge(Array.map(combine, keyValues), Js.undefined)
  | Some(cb) =>
    _multiMerge(Array.map(combine, keyValues), Js.Undefined.return(map_cb_multi_err_only(cb)))
  }
};
