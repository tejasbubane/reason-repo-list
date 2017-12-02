let component = ReasonReact.statelessComponent("RepoItem");

let se = ReasonReact.stringToElement;

let make = (~repo: RepoData.repo, _children) => {
  ...component,
  render: (_self) =>
    <li className="repo-item">
      <a href=repo.html_url className="repo-name" target="_blank"> (se(repo.full_name)) </a>
      <span className="repo-count"> (se("Stars: " ++ string_of_int(repo.stargazers_count))) </span>
      <span className="repo-count">
        (se("Watching: " ++ string_of_int(repo.watchers_count)))
      </span>
    </li>
};
