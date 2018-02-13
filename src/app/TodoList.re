let component = ReasonReact.statelessComponent("TodoList");

let make = (~todos, _children) => {
  ...component,
  render: (_self) => {
    Js.log2("todos", todos);
    let renderedTodo =
      todos
      |> List.map(
           (todo) => <TodoItem text=todo.text completed=false onDestroy=((_e) => Js.log("test")) />
         )
      |> Array.of_list
      |> ReasonReact.arrayToElement;
    <ul className="todo-list"> renderedTodo </ul>
  }
};