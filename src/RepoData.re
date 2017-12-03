type repo = {
  full_name: string,
  stargazers_count: int,
  watchers_count: int,
  html_url: string
};

let parseRepoJson = (json: Js.Json.t) : repo =>
  Json.Decode.{
    full_name: json |> field("full_name", string),
    stargazers_count: json |> field("stargazers_count", int),
    watchers_count: json |> field("watchers_count", int),
    html_url: json |> field("html_url", string)
  };

let parseResponseJson = (json) =>
  json |> Json.Decode.field("items", Json.Decode.array(parseRepoJson));

let repoUrl = (language) =>
  "https://api.github.com/search/repositories?q=topic:"
  ++ language
  ++ "&type=Repositories&sort=stars";

let fetchRepos = (language) =>
  Js.Promise.(
    Bs_fetch.fetch(repoUrl(language))
    |> then_(Bs_fetch.Response.text)
    |> then_((jsonText) => resolve(parseResponseJson(Js.Json.parseExn(jsonText))))
  );
