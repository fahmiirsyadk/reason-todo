open Utils;
open Types;

let container =
  styl(
    ~width="500px",
    ~overflow="hidden",
    ~backgroundColor="white",
    ~margin="10px auto",
    ~borderRadius="3px",
    (),
  );

let main = styl(~padding="10px 15px", ());

type state = {todos: list(todo)};
type action =
  | AddItem(string)
  | ToggleItem(int);
//   | StartEditingItem(int)
//   | FinishEditingItem(int, string);

let lastId = ref(0);
let newItem = (~text as title) => {
  lastId := lastId^ + 1;
  {id: lastId^, title, completed: false, edit: false};
};

[@react.component]
let make = () => {
  let ({todos}, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | AddItem(text) => {todos: [newItem(text), ...state.todos]}
        | ToggleItem(id) =>
          let todos =
            List.map(
              todo =>
                todo.id == id ? {...todo, completed: !todo.completed} : todo,
              state.todos,
            );
          {todos: todos};
        },
      {todos: [{id: 0, title: "something", completed: true, edit: false}]},
    );

  let itemLength = List.length(todos);
  let numTodos =
    switch (itemLength) {
    | 0 => " todo"
    | 1 => " todo"
    | _ => " todos"
    };

  <div style=container>
    <Header title="My todo" />
    <div style=main>
      <AddTodoInput onSubmit={text => dispatch(AddItem(text))} />
      <div>
        {List.map(
           todo =>
             <TodoItem
               key={string_of_int(todo.id)}
               onToggle={() => dispatch(ToggleItem(todo.id))}
               todo
             />,
           todos,
         )
         |> Array.of_list
         |> React.array}
      </div>
      <footer> {str("0 item")} </footer>
    </div>
  </div>;
};