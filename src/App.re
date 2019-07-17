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
  | ToggleItem(int)
  | DeleteItem(int)
  | StartEditingItem(int)
  | FinishEditingItem(int, string);

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
        | DeleteItem(id) =>
          let todos = List.filter(todo => todo.id != id, state.todos);
          {todos: todos};
        | StartEditingItem(id) =>
          let todos =
            List.map(
              todo =>
                todo.id == id
                  ? {...todo, edit: true} : {...todo, edit: false},
              state.todos,
            );
          {todos: todos};
        | FinishEditingItem(id, text) =>
          let todos =
            List.map(
              todo =>
                todo.id == id ? {...todo, edit: false, title: text} : todo,
              state.todos,
            );
          {todos: todos};
        },
      {todos: [{id: 0, title: "something", completed: true, edit: false}]},
    );

  let itemLength = List.length(todos);

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
               onDelete={() => dispatch(DeleteItem(todo.id))}
               onEditStart={() => dispatch(StartEditingItem(todo.id))}
               onEditDone={text =>
                 dispatch(FinishEditingItem(todo.id, text))
               }
               todo
             />,
           todos,
         )
         |> Array.of_list
         |> React.array}
      </div>
      <Footer itemLength />
    </div>
  </div>;
};