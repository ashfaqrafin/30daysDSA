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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> given(n, vector<int>(m)), dp(n, vector<int>(m));
    repa(i, given)
    {
        repa(j, i)
        {
            cin >> j;
        }
    }

    dp[0][0] = given[0][0];
    rep(i, 1, n)
    {
        dp[i][0] = dp[i - 1][0] + given[i][0];
    }
    rep(i, 1, m)
    {
        dp[0][i] = dp[0][i - 1] + given[0][i];
    }

    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            dp[i][j] = given[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    repa(i, dp)
    {
        repa(j, i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
