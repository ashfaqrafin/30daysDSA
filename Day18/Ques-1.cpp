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

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<string>> dp(s1.length() + 1, vector<string>(s2.length() + 1));

    repe(i, 0, s1.length())
    {
        repe(j, 0, s2.length())
        {
            if (i == 0 or j == 0)
                dp[i][j] = "";
            else if (s1[i - 1] == s2[j - 1] and i != j)
            {
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j].length() > dp[i][j - 1].length()) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    cout << dp[s1.length()][s2.length()] << endl;

    return 0;
}
