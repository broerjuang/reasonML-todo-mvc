open TodoType;

type id = int;

type text = string;

type state = {
  todos: list(todo),
  currentTodo: option(text),
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

let component = ReasonReact.reducerComponent("TodoApp");

let make = (_children) => {
  /* Aux Function */
  let getValueFromEvent = (event) => ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value;
  let defaultValueFromOption = (defaultValue, xs) =>
    switch xs {
    | Some(x) => x
    | None => defaultValue
    };
  /* Handler  function */
  let inputTodo = (event) => InputTodo(getValueFromEvent(event));
  let handleSubmit = (event) => {
    ReactEventRe.Form.preventDefault(event);
    SubmitTodo
  };
  let handleDelete = (id) => DeleteTodo(id);
  let handleToggleAll = (_e) => ToggleAll;
  let handleToggleTodo = (id) => ToggleTodoById(id);
  let handleClearCompletedTodo = (_event) => ClearCompleted;
  let handleShowTodo = (show) => ShowTodo(show);
  let remainingTodo = (todos) => todos |> List.filter((todo) => ! todo.completed) |> List.length;
  /* Updater helpers */
  let createNewTodo = (text) => {id: Random.int(100), text, completed: false};
  let toggleAllTodos = List.map((todo) => {...todo, completed: ! todo.completed});
  let toggleTodoById = (id) =>
    List.map((todo) => todo.id === id ? {...todo, completed: ! todo.completed} : todo);
  let clearCompletedTodos = List.filter((todo) => ! todo.completed);
  let deleteTodoById = (id) => List.filter((todo) => todo.id !== id);
  {
    ...component,
    initialState: () => {todos: [], currentTodo: None, showTodo: All},
    reducer: (action, state) =>
      switch action {
      | InputTodo(newTodoText) => ReasonReact.Update({...state, currentTodo: Some(newTodoText)})
      | SubmitTodo =>
        switch state.currentTodo {
        | Some(text) =>
          ReasonReact.Update({
            ...state,
            todos: [createNewTodo(text), ...state.todos],
            currentTodo: None
          })
        | None => ReasonReact.NoUpdate
        }
      | ToggleAll => ReasonReact.Update({...state, todos: toggleAllTodos(state.todos)})
      | ToggleTodoById(id) =>
        ReasonReact.Update({...state, todos: toggleTodoById(id, state.todos)})
      | DeleteTodo(id) => ReasonReact.Update({...state, todos: deleteTodoById(id, state.todos)})
      | ClearCompleted => ReasonReact.Update({...state, todos: clearCompletedTodos(state.todos)})
      | ShowTodo(show) => ReasonReact.Update({...state, showTodo: show})
      },
    render: ({state, reduce}) =>
      <section className="todoapp">
        <header className="header">
          <h1> (ReasonReact.stringToElement("todos")) </h1>
          <form onSubmit=(reduce(handleSubmit))>
            <input
              _type="text"
              className="new-todo"
              value=(defaultValueFromOption("", state.currentTodo))
              onChange=(reduce(inputTodo))
              placeholder="What needs to be done?"
              autoFocus=Js.true_
            />
          </form>
        </header>
        <section className="main">
          <ToggleAll onToggleAll=(reduce(handleToggleAll)) />
          <TodoList
            todos=state.todos
            onToggle=(reduce(handleToggleTodo))
            onDelete=(reduce(handleDelete))
            showTodo=state.showTodo
          />
        </section>
        <Footer
          itemLeft=(remainingTodo(state.todos))
          clearCompletedTodos=(reduce(handleClearCompletedTodo))
          onShowTodo=(reduce(handleShowTodo))
          showTodo=state.showTodo
        />
      </section>
  }
};