open Types;
open Utils;

[@react.component]
let make = (~todo, ~onToggle) => {
  <div className={todo.completed == true ? "todo checked" : "todo"}>
    <input
      type_="checkbox"
      onClick={__x => onToggle()}
      checked={todo.completed}
    />
    {str(todo.title)}
  </div>;
};