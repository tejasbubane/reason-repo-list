[%%bs.raw {| require("./index.css") |}];

let renderForRoute = (element) => ReactDOMRe.renderToElementWithId(element, "root");

let router = DirectorRe.makeRouter({"/": "root", "/reasonml": "reasonml", "/ruby": "ruby"});

let handlers = {
  "root": () => renderForRoute(<App router />),
  "reasonml": () => renderForRoute(<RepoList language="reasonml" router />),
  "ruby": () => renderForRoute(<RepoList language="ruby" router />)
};

DirectorRe.configure(router, {"html5history": true, "resource": handlers});

DirectorRe.init(router, "/");
