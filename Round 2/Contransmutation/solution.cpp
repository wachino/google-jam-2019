#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <vector>
#include <functional>

using namespace std;

const long long MOD = 1000000007LL;
const long long INF = -2LL;

long long computePathsFrom(long long *dp, const pair<int, int> *metals, const bool *reachable, const int &node, const int &M)
{
  bool *inCurrentPath = new bool[M];
  for (int i = 0; i < M; i++)
  {
    inCurrentPath[i] = false;
  }

  std::function<long long int(int)> computePathsFromAux;
  computePathsFromAux = [&](int n) -> long long int {
    if (dp[n] >= 0 || dp[n] == INF)
    {
      return dp[n];
    }
    if (!reachable[n])
    {
      dp[n] = 0;
      return dp[n];
    }
    if (inCurrentPath[n])
    {
      dp[n] = INF;
      return dp[n];
    }
    inCurrentPath[n] = true;
    long long a = computePathsFromAux(metals[n].first);
    long long b = computePathsFromAux(metals[n].second);

    long long ret;
    if (a == INF || b == INF)
    {
      ret = INF;
    }
    else
    {
      ret = a + b;
      if (ret > MOD + 2)
      {
        ret = ret % MOD;
      }
    }
    inCurrentPath[n] = false;
    dp[n] = ret;
    return dp[n];
  };

  long long ret = computePathsFromAux(node);
  delete[] inCurrentPath;
  return ret;
}

void checkReachable(bool *reachable, const vector<int> *traspose, int node)
{
  if (reachable[node])
  {
    return;
  }

  reachable[node] = true;
  for (int i = 0; i < (int)traspose[node].size(); i++)
  {
    checkReachable(reachable, traspose, traspose[node][i]);
  }
}

int main()
{
  int T, M, a, b;
  pair<int, int> *metals;
  long long *amount;
  vector<int> *traspose;
  bool *reachable;
  long long *dp;
  cin >> T;
  for (int t = 0; t < T; t++)
  {
    cin >> M;
    metals = new pair<int, int>[M];
    amount = new long long[M];
    traspose = new vector<int>[M];
    reachable = new bool[M];
    dp = new long long[M];
    for (int i = 0; i < M; i++)
    {
      cin >> a >> b;
      metals[i] = make_pair(a - 1, b - 1);
      traspose[metals[i].first].push_back(i);
      traspose[metals[i].second].push_back(i);
      dp[i] = -1LL;
    }

    dp[0] = 1LL;

    for (int i = 0; i < M; i++)
    {
      reachable[i] = false;
      cin >> amount[i];
    }

    checkReachable(reachable, traspose, 0);

    for (int i = 1; i < M; i++)
    {
      computePathsFrom(dp, metals, reachable, i, M);
    }

    if (dp[metals[0].first] == INF ||
        dp[metals[0].second] == INF ||
        dp[metals[0].first] + dp[metals[0].second] >= 2LL)
    {
      for (int i = 0; i < M; i++)
      {
        if (reachable[i])
        {
          dp[i] = INF;
        }
      }
    }

    bool bounded = true;
    long long sol = 0;

    for (int i = 0; i < M; i++)
    {
      if (!bounded)
      {
        continue;
      }
      if (amount[i] > 0)
      {
        if (dp[i] == INF)
        {
          bounded = false;
        }
        else
        {
          sol = (sol + (amount[i] * dp[i])) % MOD;
        }
      }
    }
    if (bounded)
    {
      cout << "Case #" << t + 1 << ": " << sol % MOD << endl;
    }
    else
    {
      cout << "Case #" << t + 1 << ": UNBOUNDED" << endl;
    }

    delete[] metals;
    delete[] amount;
    delete[] traspose;
    delete[] reachable;
    delete[] dp;
  }
  return 0;
}