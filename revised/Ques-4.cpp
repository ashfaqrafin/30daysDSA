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
#define all(container) begin(container), end(container)
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

    int n, m;
    cin >> n >> m;
    multiset<int> a;
    int ni, mi;

    rep(i, 0, n)
    {
        cin >> ni;
        a.insert(ni);
    }

    rep(i, 0, m)
    {
        cin >> mi;

        auto it = a.upper_bound(mi);
        if (it == a.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *(--it) << endl;
            a.erase(it);
        }
    }

    return 0;
}
