void dfs(int u, vector<vector<int>> &c_g, vector<int> &visit)
{
  if (visit[u] == 1)
    return;
  visit[u] = 1;
  for (int i = 0; i < c_g[u].size(); i++) {
    dfs(c_g[u][i], c_g, visit);
  }
  return;
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road,
                       vector<vector<int>> cities) {
  vector<vector<int>> city_graph(n);
  vector<int> city_visit(n, 0);
  vector<int> city_chk(n, 0);

  for (auto it : cities) {
    city_graph[it[0]-1].push_back(it[1]-1);
    city_graph[it[1]-1].push_back(it[0]-1);
  }

  int cycleCount = 0;

  for (int i = 0; i < n; i++) {
    if (city_visit[i] == 0) {
      cycleCount++;
      dfs(i, city_graph, city_visit);
    }
  }

  if (c_lib <= c_road) {
    return (long)n * (long)c_lib;
  } else {
    return (((long)n - (long)cycleCount) * (long)c_road) + ((long)cycleCount * (long)c_lib);
  }
}