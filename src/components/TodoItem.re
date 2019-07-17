open Types;
open Utils;

[@react.component]
let make = (~todo, ~onToggle, ~onDelete, ~onEditStart, ~onEditDone, _) => {
  <div className={todo.completed == true ? "todo checked" : "todo"}>
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