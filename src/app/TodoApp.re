type todo = {
  id: int,
  text: string,
  completed: bool
};

type todos = list(todo);

type state = {
  todos,
  currentTodo: option(string)
};

type action =
  | InputTodo(string)
  | SubmitTodo;

let component = ReasonReact.reducerComponent("TodoApp");

let make = (_children) => {
  ...component,
  initialState: () => {todos: [{id: 1, text: "testing", completed: false}], currentTodo: None},
  reducer: (action, state) =>
    switch action {
    | InputTodo(newTodoText) => ReasonReact.Update({...state, currentTodo: Some(newTodoText)})
    | SubmitTodo => ReasonReact.NoUpdate
    },
  render: ({state, send}) => {
    Js.log(state);
    <section className="todoapp">
      <header className="header">
        <h1> (ReasonReact.stringToElement("todos")) </h1>
        <input
          className="new-todo"
          onChange=(
            (e) => {
              let value =
                ReactEventRe.Form.target(e)
                |> ReactDOMRe.domElementToObj
                |> ((result) => result##value);
              send(InputTodo(value))
            }
          )
          placeholder="What needs to be done?"
          autoFocus=(Js.Boolean.to_js_boolean(true))
        />
      </header>
      <section className="main">
        <ToggleAll onToggleAll=((_e) => Js.log("toggleAll")) />
        <TodoList todos=state.todos />
      </section>
      <Footer />
    </section>
  }
};