let component = ReasonReact.statelessComponent("TodoList");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <ul className="todo-list">
      <TodoItem completed=false text="testing" onDestroy=((_e) => Js.log("fired")) />
      <TodoItem completed=false text="second" onDestroy=((_e) => Js.log("fired")) />
    </ul>
};