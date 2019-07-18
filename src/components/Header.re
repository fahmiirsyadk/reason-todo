open Utils;

module Styles = {
  let header =
    Css.(
      style([
        width(`auto),
        fontWeight(`bold),
        textAlign(`center),
        padding2(~v=px(10), ~h=`zero),
        fontSize(rem(1.2)),
      ])
    );
};

[@react.component]
let make = (~title) =>
  <header className=Styles.header> {str(title)} </header>;