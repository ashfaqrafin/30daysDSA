#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n, sum = 0, lng = 0, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        sum += t;
        lng = max(lng, t);
    }
    if (lng * 2 < sum)
        cout << sum;
    else
        cout << 2 * lng;
    return 0;
}