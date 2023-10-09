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

struct dimensions
{
    int h, l, w;
};

bool com(dimensions &a, dimensions &b)
{
    return a.l * a.w > b.l * b.w;
}

signed main(void)
{

    // cout.precision(10);
    // cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<dimensions> arr(3 * n);

    int a, b, c;
    int index = 0;
    rep(i, 0, n)
    {
        cin >> a >> b >> c;

        arr[index].h = a;
        arr[index].w = max(b, c);
        arr[index].l = min(b, c);
        index += 1;

        arr[index].h = b;
        arr[index].w = max(a, c);
        arr[index].l = min(a, c);
        index += 1;

        arr[index].h = c;
        arr[index].w = max(b, a);
        arr[index].l = min(b, a);
        index += 1;
    }

    sort(all(arr), com);

    vi dp(3 * n);
    rep(i, 0, 3 * n)
    {
        dp[i] = arr[i].h;
    }

    rep(i, 1, 3 * n)
    {
        rep(j, 0, i)
        {
            if (arr[i].w < arr[j].w and arr[i].l < arr[j].l and dp[i] < dp[j] + arr[i].h)
            {
                dp[i] = dp[j] + arr[i].h;
            }
        }
    }

    repa(i, dp)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
