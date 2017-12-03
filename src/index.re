[%%bs.raw {| require("./index.css") |}];

let renderForRoute = (element) => ReactDOMRe.renderToElementWithId(element, "root");

let router =
  DirectorRe.makeRouter({
    "/": () => renderForRoute(<App />),
    "/reasonml": () => renderForRoute(<RepoList language="reasonml" />),
    "/ruby": () => renderForRoute(<RepoList language="ruby" />)
  });

DirectorRe.init(router, "/");
