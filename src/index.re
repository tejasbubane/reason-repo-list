[%%bs.raw {| require("./index.css") |}];

type route =
  | Home
  | Repo(string);

let router = DirectorRe.makeRouter({"/": "root", "/repos/:language": "repos"});

let renderForRoute = (route) => {
  let component =
    switch route {
    | Home => <App router />
    | Repo(language) => <RepoList language />
    };
  ReactDOMRe.renderToElementWithId(component, "root")
};

let handlers = {
  "root": () => renderForRoute(Home),
  "repos": (language: string) => renderForRoute(Repo(language))
};

DirectorRe.configure(router, {"html5history": true, "resource": handlers});

DirectorRe.init(router, "/");
