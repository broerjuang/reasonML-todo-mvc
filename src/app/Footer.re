let component = ReasonReact.statelessComponent("Footer");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <footer className="footer">
      <span className="todo-count">
        <strong> (ReasonReact.stringToElement("0 ")) </strong>
        (ReasonReact.stringToElement("item left"))
      </span>
      <ul className="filters">
        <li> <a className="selected" href="#/"> (ReasonReact.stringToElement("All")) </a> </li>
        <li> <a href="#/active"> (ReasonReact.stringToElement("Active")) </a> </li>
        <li> <a href="#/completed"> (ReasonReact.stringToElement("Completed")) </a> </li>
      </ul>
      <button className="clear-completed">
        (ReasonReact.stringToElement("Clear completed"))
      </button>
    </footer>
};