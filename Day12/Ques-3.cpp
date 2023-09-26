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

    int n, a, b;
    cin >> n >> a >> b;

    vi given(n + 1);

    repe(i, 1, n)
    {
        cin >> given[i];
        given[i] += given[i - 1];
    }

    multiset<int> helper;
    repe(i, a, b)
    {
        helper.insert(given[i]);
    }
    int maxSum = -1e18;
    repe(i, 1, n - a + 1)
    {
        maxSum = max(maxSum, *helper.rbegin() - given[i - 1]);
        helper.erase(helper.find(given[i + a - 1]));
        if (i + b <= n)
            helper.insert(given[i + b]);
    }
    cout << maxSum << endl;

    return 0;
}

