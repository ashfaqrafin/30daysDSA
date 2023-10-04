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

    int n, limit;
    cin >> n >> limit;

    map<int, pair<int, int>> helper;
    int a, b;
    vi dp(limit + 1);
    rep(i, 0, n)
    {
        cin >> a >> b;
        helper[i] = {a, b};
        dp[a] = b;
    }

    repa(i, dp)
    {
        cout << i << " ";
    }
    cout << endl;

    repe(i, 1, n)
    {
        repe(j, 1, limit)
        {
            if (j >= helper[i - 1].first)
            {
                dp[j] = max(helper[i - 1].second + dp[j - helper[i - 1].first], dp[j]);
            }
        }
    }

    cout << dp[limit] << endl;

    return 0;
}
