let se = ReasonReact.stringToElement;

type state = {repoData: option(array(RepoData.repo))};

type action =
  | Loaded(array(RepoData.repo));

let component = ReasonReact.reducerComponent("RepoList");

let make = (~language, _children) => {
  ...component,
  initialState: () => {repoData: None},
  didMount: (self) => {
    let handleRepoLoad = self.reduce((repos) => Loaded(repos));
    Js.Promise.(
      RepoData.fetchRepos(language)
      |> then_(
           (repos) => {
             handleRepoLoad(repos);
             resolve()
           }
         )
      |> ignore
    );
    ReasonReact.NoUpdate
  },
  reducer: (action, _state) =>
    switch action {
    | Loaded(loadedRepo) => ReasonReact.Update({repoData: Some(loadedRepo)})
    },
  render: (self) => {
    let repoItems =
      switch self.state.repoData {
      | Some(repos) =>
        ReasonReact.arrayToElement(
          Array.map((repo: RepoData.repo) => <RepoItem key=(string_of_int(repo.id)) repo />, repos)
        )
      | None => se("Loading...")
      };
    <div className="App">
      <GithubCorner />
      <h1> (se("Reason Projects")) </h1>
      <ul> repoItems </ul>
    </div>
  }
};
