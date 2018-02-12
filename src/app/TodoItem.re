let component = ReasonReact.statelessComponent("TodoItem");

let make = (~completed, ~text, ~onDestroy,_children) => {
    ...component, 
    render: (_self) => {
    <li className=(completed ? "completed": "")>
          <div className="view">
            <input className="toggle" _type="checkbox" checked=Js.Boolean.to_js_boolean(completed) />
            <label> (ReasonReact.stringToElement(text)) </label>
            <button className="destroy" onClick=onDestroy></button>
          </div>
          <input className="edit" value="Create a TodoMVC template" />
        </li>
    }
}