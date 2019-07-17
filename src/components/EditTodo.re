let valueFromEvent = (evt): string => evt->ReactEvent.Form.target##value;

type state = {text: string};

[@react.component]
let make = (~initialText, ~onSubmit, _) => {
  let (text, setText) =
    React.useReducer((_, newText) => newText, initialText);

  <input
    value=text
    type_="text"
    placeholder="Todo description"
    onChange={evt => setText(valueFromEvent(evt))}
    onKeyDown={evt =>
      if (ReactEvent.Keyboard.key(evt) == "Enter") {
        onSubmit(text);
        setText("");
      } else if (ReactEvent.Keyboard.key(evt) == "Escape") {
        onSubmit(initialText);
        setText("");
      }
    }
  />;
};