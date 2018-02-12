let component = ReasonReact.statelessComponent("TodoApp");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <section className="todoapp">
      <header className="header">
        <h1> (ReasonReact.stringToElement("todos")) </h1>
        <input
          className="new-todo"
          placeholder="What needs to be done?"
          autoFocus=(Js.Boolean.to_js_boolean(true))
        />
      </header>
      <section className="main">
        <input id="toggle-all" className="toggle-all" _type="checkbox" />
      </section>
      <ul className="todo-list">
        <li className="completed">
          <div className="view">
            <input className="toggle" _type="checkbox" checked=Js.Boolean.to_js_boolean(true) />
            <label> (ReasonReact.stringToElement("taste javascript")) </label>
            <button className="destroy"></button>
          </div>
          <input className="edit" value="Create a TodoMVC template" />
        </li>
        <li>
          <div className="view">
            <input className="toggle" _type="checkbox" checked=Js.Boolean.to_js_boolean(false) />
            <label> (ReasonReact.stringToElement("taste javascript")) </label>
            <button className="destroy"></button>
          </div>
          <input className="edit" value="Create a TodoMVC template" />
        </li>
      </ul>

      			<footer className="footer">
        <span className="todo-count"> <strong>(ReasonReact.stringToElement("0 "))</strong> (ReasonReact.stringToElement("item left"))</span>
        
				 <ul className="filters">
					<li>
						<a className="selected" href="#/">(ReasonReact.stringToElement("All"))</a>
					</li>
					<li>
						<a href="#/active">(ReasonReact.stringToElement("Active"))</a>
					</li>
					<li>
						<a href="#/completed">(ReasonReact.stringToElement("Completed"))</a>
					</li>
				</ul>
				<button className="clear-completed">(ReasonReact.stringToElement("Clear completed"))</button>
			</footer>
    </section>
};