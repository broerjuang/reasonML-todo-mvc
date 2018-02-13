let component = ReasonReact.statelessComponent("ToggleAll");

let make = (~onToggleAll, _children) => {
  ...component,
  render: (_self) =>
    <div>
      <input id="toggle-all" className="toggle-all" _type="checkbox" onClick=onToggleAll />
      <label htmlFor="toggle-all"> (ReasonReact.stringToElement("Mark all as complete")) </label>
    </div>
};