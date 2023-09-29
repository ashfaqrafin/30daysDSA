#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    int n, k;
    cin >> n >> k;

    vi given(n);
    repa(i, given) cin >> i;

    ordered_set<pii> window;

    rep(i, 0, k)
    {
        window.insert({given[i], i});
    }
    cout << window.find_by_order((k - 1) / 2)->first << " ";
    int p = 0;
    rep(i, k, n)
    {
        window.erase({given[p], p});
        window.insert({given[i], i});
        cout << window.find_by_order((k - 1) / 2)->first << " ";
        p++;
    }
    cout << endl;

    return 0;
}
