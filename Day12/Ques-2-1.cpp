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
#include <unordered_set>
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

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> given(n);
    rep(i, 0, n)
    {
        cin >> given[i].first >> given[i].second;
    }

    sort(all(given), [&](pii &a, pii &b)
         { return a.second < b.second; });

    multiset<int> helper;
    rep(i, 0, k)
    {
        helper.insert(0);
    }
    int ans = 0;

    rep(i, 0, n)
    {
        auto it = helper.upper_bound(given[i].first);
        if (it == helper.begin())
            continue;

        helper.erase(--it);
        helper.insert(given[i].second);
        ans++;
    }
    cout << ans << endl;

    return 0;
}

