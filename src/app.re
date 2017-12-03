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
      <li> <a href="#" onClick=(goto("repos/reasonml"))> (se("ReasonML")) </a> </li>
      <li> <a href="#" onClick=(goto("repos/ruby"))> (se("Ruby")) </a> </li>
      <li> <a href="#" onClick=(goto("repos/javascript"))> (se("Javascript")) </a> </li>
      <li> <a href="#" onClick=(goto("repos/python"))> (se("Python")) </a> </li>
      <li> <a href="#" onClick=(goto("repos/erlang"))> (se("Erlang")) </a> </li>
      <li> <a href="#" onClick=(goto("repos/elixir"))> (se("Elixir")) </a> </li>
      <li> <a href="#" onClick=(goto("repos/rust"))> (se("Rust")) </a> </li>
      <li> <a href="#" onClick=(goto("repos/go"))> (se("GoLang")) </a> </li>
    </ul>
  }
};
