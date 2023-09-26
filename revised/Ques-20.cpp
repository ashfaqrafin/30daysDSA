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

struct day
{
    int t, c, p;
};

bool cmp(day a, day b)
{
    if (a.t != b.t)
        return a.t < b.t;
    return a.c > b.c;
}

signed main(void)
{

    // cout.precision(10);
    // cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, l, r, now = 0, ans = 0;
    cin >> n;
    vector<day> C;
    priority_queue<int, vector<int>, greater<int>> Q;
    vi R(n);
    rep(i, 0, n)
    {
        cin >> l >> r;
        C.pb({l, 1, i + 1});
        C.pb({r, -1, i + 1});
        Q.push(i + 1);
    }
    sort(all(C), cmp);
    repa(d, C)
    {
        if (d.c > 0)
        {
            R[d.p - 1] = Q.top();
            Q.pop();
        }
        else
        {
            Q.push(R[d.p - 1]);
        }
        now += d.c;
        ans = max(ans, now);
    }
    cout << ans << endl;
    repa(i, R)
    {
        cout << i << " ";
    }

    return 0;
}