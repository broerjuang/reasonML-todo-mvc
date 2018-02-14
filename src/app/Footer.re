open TodoType;

let component = ReasonReact.statelessComponent("Footer");

let make = (~itemLeft, ~clearCompletedTodos, ~onShowTodo, ~showTodo, _children) => {
  ...component,
  render: (_self) =>
    <footer className="footer">
      <span className="todo-count">
        <strong> (ReasonReact.stringToElement((itemLeft |> string_of_int) ++ " ")) </strong>
        (ReasonReact.stringToElement("item left"))
      </span>
      <ul className="filters">
        <li>
          <a
            className=(showTodo === All ? "selected" : "")
            style=(ReactDOMRe.Style.make(~cursor="pointer", ()))
            onClick=((_e) => onShowTodo(All))>
            (ReasonReact.stringToElement("All"))
          </a>
        </li>
        <li>
          <a
            className=(showTodo === Active ? "selected" : "")
            style=(ReactDOMRe.Style.make(~cursor="pointer", ()))
            onClick=((_e) => onShowTodo(Active))>
            (ReasonReact.stringToElement("Active"))
          </a>
        </li>
        <li>
          <a
            className=(showTodo === Completed ? "selected" : "")
            style=(ReactDOMRe.Style.make(~cursor="pointer", ()))
            onClick=((_e) => onShowTodo(Completed))>
            (ReasonReact.stringToElement("Completed"))
          </a>
        </li>
      </ul>
      <button className="clear-completed" onClick=clearCompletedTodos>
        (ReasonReact.stringToElement("Clear completed"))
      </button>
    </footer>
};