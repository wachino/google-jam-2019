#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <vector>
#include <functional>

using namespace std;

const long long MOD = 1000000007LL;

long long pancakes[1000001];
long long sum[1000001];
int idx[1000001];

pair<int, pair<int, long long>> xIntervals[1000001];
pair<int, pair<int, long long>> yIntervals[1000001];

int main()
{
  int T, S;
  int l, r;
  long long tmp, xp, yp, sol;
  cin >> T;
  for (int t = 0; t < T; t++)
  {
    cin >> S;
    tmp = 0;
    sol = 0;
    for (int i = 0; i < S; i++)
    {
      cin >> pancakes[i];
      tmp = (tmp + pancakes[i]) % MOD;
      sum[i] = tmp;
      idx[i] = i;
      xIntervals[i] = make_pair(-1, make_pair(-1, 0));
      yIntervals[i] = make_pair(-1, make_pair(-1, 0));
    }
    sort(idx, idx + S, [](int idA, int idB) { return pancakes[idA] < pancakes[idB]; });

    for (int i = 0; i < S; i++)
    {
      int id = idx[i];

      l = (id == 0 || xIntervals[id - 1].first == -1) ? id : xIntervals[id - 1].first;

      r = (id == S - 1 || xIntervals[id + 1].second.first == -1) ? id : xIntervals[id + 1].second.first;
      long long xi = id == 0 ? id : (xIntervals[id - 1].second.second * (r - id + 1)) % MOD;

      xIntervals[l].first = l;
      xIntervals[l].second.first = r;

      xIntervals[r].first = l;
      xIntervals[r].second.first = r;

      xp = ((xIntervals[r].second.second + xIntervals[l].second.second) % MOD +
            ((id - l + 1) * (pancakes[id] * (r - id) - (sum[r] - sum[id])) % MOD) %
                MOD) %
           MOD;

      xIntervals[l].second.second = xp;
      xIntervals[r].second.second = xp;
      xIntervals[id].second.second = xp;

      l = (id == 0 || yIntervals[id - 1].first == -1) ? id : yIntervals[id - 1].first;
      r = (id == S - 1 || yIntervals[id + 1].second.first == -1) ? id : yIntervals[id + 1].second.first;

      long long yi = id == S - 1 ? 0 : (yIntervals[id + 1].second.second * (id - l + 1)) % MOD;
      sol = (sol + (xi + yi)) % MOD;

      yIntervals[l].first = l;
      yIntervals[l].second.first = r;

      yIntervals[r].first = l;
      yIntervals[r].second.first = r;
      long si = (id == 0) ? 0 : sum[id - 1];
      long sl = (l == 0) ? 0 : sum[l - 1];
      yp = ((yIntervals[r].second.second + yIntervals[l].second.second) % MOD +
            ((r - id + 1) * (pancakes[id] * (id - l) - (si - sl)) % MOD) %
                MOD) %
           MOD;

      yIntervals[l].second.second = yp;
      yIntervals[r].second.second = yp;
      yIntervals[id].second.second = yp;
    }

    cout << "Case #" << t + 1 << ": " << sol << endl;
  }
  return 0;
}