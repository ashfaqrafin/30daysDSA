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

void ins(multiset<int> &low, multiset<int> &up, int val, int k)
{
    if (val > *low.rbegin())
    {
        up.insert(val);
        if (up.size() > k / 2)
        {
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    }
    else
    {
        low.insert(val);
        if (low.size() > (k + 1) / 2)
        {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void era(multiset<int> &low, multiset<int> &up, int val)
{
    if (low.find(val) != low.end())
    {
        low.erase(low.find(val));
    }
    else
    {
        up.erase(up.find(val));
    }
    if (low.empty())
    {
        low.insert(*up.begin());
        up.erase(up.find(*up.begin()));
    }
}

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
    repa(i, given) cin >> i;

    multiset<int> low, up;
    low.insert(given[0]);
    rep(i, 1, k)
    {
        ins(low, up, given[i], k);
    }
    cout << *low.rbegin() << " ";
    rep(i, k, n)
    {
        if (k == 1)
        {
            ins(low, up, given[i], k);
            era(low, up, given[i - k]);
        }
        else
        {
            era(low, up, given[i - k]);
            ins(low, up, given[i], k);
        }
        cout << *low.rbegin() << " ";
    }
    cout << endl;

    return 0;
}