open Utils;

[@react.component]
let make = (~itemLength) => {
  let format =
    str(
      string_of_int(itemLength) ++ " item" ++ (itemLength <= 1 ? "" : "s"),
    );
  <footer> format </footer>;
};