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

    vi profit(n), weight(n);

    repa(i, weight) cin >> i;
    repa(i, profit) cin >> i;

    vector<vector<int>> dp(n + 1, vi(limit + 1));

    repe(i, 0, n)
    {
        repe(j, 0, limit)
        {
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }
            else if (weight[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
        }
    }

    cout << dp[n][limit] << endl;

    return 0;
}
