let str = React.string;
let container =
  ReactDOMRe.Style.make(
    ~width="500px",
    ~padding="10px 15px",
    ~backgroundColor="white",
    ~margin="10px auto",
    ~border="1px solid grey",
    ~borderRadius="3px",
    (),
  );

[@react.component]
let make = () =>
  <div style=container> {str("Hello this is todo list")} </div>;