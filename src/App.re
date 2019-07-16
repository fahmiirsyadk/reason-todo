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

type action =
  | AddItem(string)
  | ToggleItem(int)
  | StartEditingItem(int)
  | FinishEditingItem(int, string);

let lastId = ref(0);
let newItem = (~text as title) => {
  lastId := lastId^ + 1;
  {id: lastId^, title, completed: false, edit: false};
};

[@react.component]
let make = () =>
   let ({todos}, dispatch) = React.useReducer((state, action) => 
      switch action {
      | AddItem() => pattern
      | ToggleItem() => pattern
      | StartEditingItem() => pattern
      | FinishEditingItem() => pattern
      };
   );
  <div style=container>
    <Header title="My todo" />
    <div style=main>
      <div> {str("nothing")} </div>
      <footer> {str("0 item")} </footer>
    </div>
  </div>;