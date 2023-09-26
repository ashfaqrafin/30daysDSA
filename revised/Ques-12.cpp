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
#define repc(variable, start, end, increment) for (int variable = start; variable < end; increment)
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

    vi given(n);
    vi index(n + 2);
    index[n + 1] = INT_MAX;

    rep(i, 0, n)
    {
        cin >> given[i];
        index[given[i]] = i;
    }

    int ans = 1;
    rep(i, 1, n + 1)
    {
        if (index[i] < index[i - 1])
        {
            ans++;
        }
    }

    int x, y, valueX, valueY;

    set<pair<int, int>> helper;

    while (k--)
    {
        cin >> x >> y;
        x--;
        y--;

        valueX = given[x];
        valueY = given[y];

        helper.insert({valueX, valueX + 1});
        helper.insert({valueX - 1, valueX});
        helper.insert({valueY, valueY + 1});
        helper.insert({valueY - 1, valueY});
        repa(i, helper)
        {
            ans -= (index[i.first] > index[i.second]);
        }
        swap(given[x], given[y]);
        index[given[x]] = x;
        index[given[y]] = y;
        repa(i, helper)
        {
            ans += (index[i.first] > index[i.second]);
        }
        helper.clear();

        cout << ans << endl;
    }

    return 0;
}