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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<pair<int, int>> v(n);
    rep(i, 0, n)
    {
        int xx;
        cin >> xx;
        a[i] = xx;
        v[i] = {xx, i + 1};
    }
    sort(all(v));
    rep(i, 0, n)
    {
        int low = 0, hi = n - 1;
        while (low < hi)
        {
            if (v[low].second == i + 1)
                low++;
            else if (v[hi].second == i + 1)
                hi--;
            else if (v[low].first + v[hi].first + a[i] > x)
                hi--;
            else if (v[low].first + v[hi].first + a[i] < x)
                low++;
            else
            {
                cout << v[low].second << " " << i + 1 << " " << v[hi].second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}