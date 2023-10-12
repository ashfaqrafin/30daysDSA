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

    vector<vector<int>> given(n + 1, vector<int>(m + 1)), dp(n + 1, vector<int>(m + 1));
    repa(i, given)
    {
        repa(j, i)
        {
            cin >> j;
        }
    }

    bool flag = false;
    repe(i, 0, n)
    {
        if (flag or given[i][0])
        {
            flag = true;
            dp[i][0] = 0;
        }
        else
        {
            dp[i][0] = 1;
        }
    }
    flag = false;
    repe(i, 0, m)
    {
        if (flag or given[0][i])
        {
            flag = true;
            dp[0][i] = 0;
        }
        else
        {
            dp[0][i] = 1;
        }
    }

    repe(i, 1, n)
    {
        repe(j, 1, m)
        {
            if (given[i][j])
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
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
