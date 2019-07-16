open Types;

let valueFromEvent = (evt): string => evt->ReactEvent.Form.target##value;

[@react.component]
let make = (~onSubmit) => {
  let (text, setText) = React.useReducer((_, newText) => newText, "");
  <input
    value=text
    type_="text"
    placeholder="Write something to do"
    onChange={evt => setText(valueFromEvent(evt))}
    onKeyDown={evt =>
      if (ReactEvent.Keyboard.key(evt) == "Enter") {
        onSubmit(text);
        setText("");
      }
    }
  />;
};