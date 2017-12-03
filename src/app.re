let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("App");

let make = (~router, _children) => {
  ...component,
  render: (_self) => {
    let goto = (path, event) => {
      ReactEventRe.Mouse.preventDefault(event);
      DirectorRe.setRoute(router, path)
    };
    <ul className="List of Repos">
      <li> <a href="#" onClick=(goto("/reasonml"))> (se("ReasonML")) </a> </li>
      <li> <a href="#" onClick=(goto("ruby"))> (se("Ruby")) </a> </li>
    </ul>
  }
};
