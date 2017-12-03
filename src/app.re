let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <ul className="List of Repos">
      <li> <a href="#/reasonml"> (se("ReasonML")) </a> </li>
      <li> <a href="#/ruby"> (se("Ruby")) </a> </li>
    </ul>
};
