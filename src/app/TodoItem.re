open TodoType;

let component = ReasonReact.statelessComponent("TodoItem");

let make = (~todo, ~onToggle, ~onDelete, _children) => {
    ...component, 
    render: (_self) => {
    <li className=(todo.completed ? "completed": "") >
          <div className="view">
            <input className="toggle" _type="checkbox"
             checked=Js.Boolean.to_js_boolean(todo.completed) 
             onClick=(_e => onToggle(todo.id)) />
            <label> (ReasonReact.stringToElement(todo.text)) </label>
            <button className="destroy" onClick=((_e) => onDelete(todo.id))></button>
          </div>
          <input className="edit" value="Create a TodoMVC template" />
        </li>
    }
}