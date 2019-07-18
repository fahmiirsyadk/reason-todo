open Types;
open Utils;
open Css;

module Styles = {
  let todo = disabled =>
    style([
      fontStyle(disabled ? `italic : `normal),
      color(disabled ? grey : black),
      textDecoration(disabled ? `lineThrough : `none),
    ]);
};

[@react.component]
let make = (~todo, ~onToggle, ~onDelete, ~onEditStart, ~onEditDone, _) => {
  <div className={Styles.todo(todo.completed)}>
    <input
      type_="checkbox"
      onChange={__x => onToggle()}
      checked={todo.completed}
    />
    {todo.edit
       ? <EditTodo
           initialText={todo.title}
           onSubmit={text => onEditDone(text)}
         />
       : <label onClick={_ => onEditStart()}> {str(todo.title)} </label>}
    <button onClick={_ => onDelete()}> {str("Delete")} </button>
  </div>;
};