open Utils;

let header =
  styl(
    ~width="inherit",
    ~fontWeight="bold",
    ~textAlign="center",
    ~padding="10px 0",
    ~fontSize="1.2rem",
    (),
  );

[@react.component]
let make = (~title) => <header style=header> {str(title)} </header>;