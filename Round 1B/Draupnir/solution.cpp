#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int T, W;
  cin >> T >> W;
  for (int t = 0; t < T; t++)
  {
    long long int r1, r2, r3, r4, r5, r6, ans;
    cout << 200 << endl;
    cin >> ans;
    r4 = ans >> 50;
    r5 = (ans - (r4 << 50)) >> 40;
    r6 = (ans - (r4 << 50) - (r5 << 40)) >> 33;
    cout << 56 << endl;
    cin >> ans;
    ans -= ((r4 << 14) + (r5 << 11) + (r6 << 9));
    r1 = ans >> 56;
    r2 = (ans - (r1 << 56)) >> 28;
    r3 = (ans - (r1 << 56) - (r2 << 28)) >> 18;

    cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << " " << r6 << endl;
    cin >> ans;
    if (ans == -1)
    {
      return -1;
    }
  }
  return 0;
}