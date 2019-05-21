#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

const long long MOD = 1000000007LL;
const long long INF = -2LL;

long long computePathsFrom(long long *dp, pair<int, int> *metals, const bool *reachable, const int node, const int M)
{
  bool *inCurrentPath = new bool[M];
  for (int i = 0; i < M; i++)
  {
    inCurrentPath[i] = false;
  }

  stack<int> stack;
  stack.push(node);
  inCurrentPath[node] = true;
  while (!stack.empty())
  {
    int n = stack.top();
    if (dp[n] >= 0 || dp[n] == INF)
    {
      inCurrentPath[n] = false;
      stack.pop();
      continue;
    }
    else if (!reachable[n])
    {
      dp[n] = 0;
      inCurrentPath[n] = false;
      stack.pop();
      continue;
    }

    long long a = dp[metals[n].first];
    long long b = dp[metals[n].second];
    if (a == -1)
    {
      if (inCurrentPath[metals[n].first])
      {
        dp[metals[n].first] = INF;
      }
      else
      {
        inCurrentPath[metals[n].first] = true;

        stack.push(metals[n].first);
      }
      continue;
    }
    if (b == -1)
    {
      if (inCurrentPath[metals[n].second])
      {
        dp[metals[n].second] = INF;
      }
      else
      {
        inCurrentPath[metals[n].second] = true;
        stack.push(metals[n].second);
      }
      continue;
    }
    if (a == -1 || b == -1)
    {
      continue;
    }

    long long tmp;
    if (a == INF || b == INF)
    {
      tmp = INF;
    }
    else
    {
      tmp = a + b;
      if (tmp > MOD + 2LL)
      {
        tmp = tmp % MOD;
      }
    }
    dp[n] = tmp;
  }
  delete[] inCurrentPath;
  return dp[node];
}

void checkReachable(bool *reachable, const vector<int> *traspose, int node)
{
  queue<int> queue;
  queue.push(node);
  while (!queue.empty())
  {
    int next = queue.front();
    queue.pop();
    if (!reachable[next])
    {
      reachable[next] = true;
      for (int i = 0; i < (int)traspose[next].size(); i++)
      {
        queue.push(traspose[next][i]);
      }
    }
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
      reachable[i] = false;
    }

    dp[0] = 1LL;

    for (int i = 0; i < M; i++)
    {
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