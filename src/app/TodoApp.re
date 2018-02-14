open TodoType;

type id = int;

type text = string;

type state = {
  todos: list(todo),
  currentTodo: option(string),
  showTodo: show
};

type action =
  | InputTodo(text)
  | SubmitTodo
  | ToggleAll
  | ToggleTodoById(id)
  | DeleteTodo(id)
  | ClearCompleted
  | ShowTodo(show);

let getValueFromEvent = (event) => ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value;

let defaultValueFromOption = (defaultValue, xs) =>
  switch xs {
  | Some(x) => x
  | None => defaultValue
  };

let inputTodo = (event) => InputTodo(getValueFromEvent(event));

let handleSubmit = (event) => {
  ReactEventRe.Form.preventDefault(event);
  SubmitTodo
};

let handleDelete = (id) => DeleteTodo(id);

let handleToggleAll = (_e) => ToggleAll;

let component = ReasonReact.reducerComponent("TodoApp");

let make = (_children) => {
  ...component,
  initialState: () => {todos: [], currentTodo: None, showTodo: All},
  reducer: (action, state) =>
    switch action {
    | InputTodo(newTodoText) => ReasonReact.Update({...state, currentTodo: Some(newTodoText)})
    | SubmitTodo =>
      switch state.currentTodo {
      | Some(text) =>
        let newTodo = {id: List.length(state.todos) + 1, text, completed: false};
        ReasonReact.Update({
          ...state,
          todos: List.append(state.todos, [newTodo]),
          currentTodo: None
        })
      | None => ReasonReact.NoUpdate
      }
    | ToggleAll =>
      let newTodos = state.todos |> List.map((todo) => {...todo, completed: ! todo.completed});
      ReasonReact.Update({...state, todos: newTodos})
    | ToggleTodoById(id) =>
      let newTodos =
        state.todos
        |> List.map((todo) => todo.id === id ? {...todo, completed: ! todo.completed} : todo);
      ReasonReact.Update({...state, todos: newTodos})
    | DeleteTodo(id) =>
      let newTodos = state.todos |> List.filter((todo) => todo.id !== id);
      ReasonReact.Update({...state, todos: newTodos})
    | ClearCompleted =>
      let newTodos = state.todos |> List.filter((todo) => ! todo.completed);
      ReasonReact.Update({...state, todos: newTodos})
    | ShowTodo(show) => ReasonReact.Update({...state, showTodo: show})
    },
  render: ({state, send, reduce}) => {
    /* let handleDelete = (id) => send(DeleteTodo(id)); */
    let toggleTodo = (id) => send(ToggleTodoById(id));
    let itemLeft = state.todos |> List.filter((todo) => ! todo.completed) |> List.length;
    let clearCompletedTodos = (_e) => send(ClearCompleted);
    <section className="todoapp">
      <header className="header">
        <h1> (ReasonReact.stringToElement("todos")) </h1>
        <form onSubmit=(reduce(handleSubmit))>
          <input
            className="new-todo"
            value=(defaultValueFromOption("", state.currentTodo))
            onChange=(reduce(inputTodo))
            placeholder="What needs to be done?"
            autoFocus=(Js.Boolean.to_js_boolean(true))
          />
        </form>
      </header>
      <section className="main">
        <ToggleAll onToggleAll=(reduce(handleToggleAll)) />
        <TodoList
          todos=state.todos
          onToggle=toggleTodo
          onDelete=(reduce(handleDelete))
          showTodo=state.showTodo
        />
      </section>
      <Footer
        itemLeft
        clearCompletedTodos
        onShowTodo=((show) => send(ShowTodo(show)))
        showTodo=state.showTodo
      />
    </section>
  }
};