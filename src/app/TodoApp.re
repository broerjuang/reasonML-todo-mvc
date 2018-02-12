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
        <label htmlFor="toggle-all"> (ReasonReact.stringToElement("Mark all as complete")) </label>
        <TodoList />
      </section>
      <Footer />
    </section>
};