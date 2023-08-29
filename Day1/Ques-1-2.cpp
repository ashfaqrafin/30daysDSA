#include <iostream>
#include <set>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#include <math.h>
#include <cmath>
#include <cstdint>
#include <bit>
#include <bitset>
#include <numeric>
using namespace std;

const int N = 200007;
const int INF = 1e9;
const int mod = 1e9 + 7;

#define int long long
#define double long double
#define pb push_back
#define all(container) container.begin(), container.end()
// loop
#define rep(variable, start, end) for (int variable = start; variable < end; variable++)
#define repe(variable, start, end) for (int variable = start; variable <= end; variable++)
#define repn(variable, start, end) for (int variable = start; variable >= end; variable--)
#define repa(variable, container) for (auto &variable : container)
// vector
#define vi vector<int>
#define vc vector<char>
// pair
#define pii pair<int, int>

signed main(void)
{
    // cout.precision(10);
    // cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    vi lights(n);
    set<int> road{0, x};
    rep(i, 0, n)
    {
        cin >> lights[i];
        road.insert(lights[i]);
    }

    int max_gap = 0;
    int prev = 0;

    repa(i, road)
    {
        max_gap = max(max_gap, i - prev);
        prev = i;
    }

    vi ans(n);
    ans[n - 1] = max_gap;

    for (int i = n - 1; i > 0; i--)
    {
        road.erase(lights[i]);

        auto hi = road.upper_bound(lights[i]);
        int cur = *hi - *(--hi);

        max_gap = max(max_gap, cur);
        ans[i - 1] = max_gap;
    }

    repa(i, ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
