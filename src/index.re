[%%bs.raw {| require("./index.css") |}];

let renderForRoute = (element) => ReactDOMRe.renderToElementWithId(element, "root");

let router = DirectorRe.makeRouter({"/": "root", "/repos/:language": "repos"});

let handlers = {
  "root": () => renderForRoute(<App router />),
  "repos": (language: string) => renderForRoute(<RepoList language router />)
};

DirectorRe.configure(router, {"html5history": true, "resource": handlers});

DirectorRe.init(router, "/");
