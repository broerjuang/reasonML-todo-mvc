open TodoType;

let component = ReasonReact.statelessComponent("TodoList");

let make = (~todos: list(todo), ~showTodo, ~onToggle, ~onDelete, _children) => {
  ...component,
  render: (_self) => {
    let renderedTodo =
      todos
      |> List.filter(
           (todo) =>
             switch showTodo {
             | All => true
             | Completed => todo.completed === true
             | Active => todo.completed === false
             }
         )
      |> List.map((todo) => <TodoItem key=(string_of_int(todo.id)) todo onToggle onDelete />)
      |> Array.of_list
      |> ReasonReact.arrayToElement;
    <ul className="todo-list"> renderedTodo </ul>
  }
};