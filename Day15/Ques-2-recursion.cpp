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

int recursion(vi &length, vi &price, int n, int limit)
{

    if (n < 0 or limit == 0)
    {
        return 0;
    }

    if (length[n] > limit)
    {
        return recursion(length, price, n - 1, limit);
    }

    return max(price[n] + recursion(length, price, n, limit - length[n]), recursion(length, price, n - 1, limit));
}

signed main(void)
{

    // cout.precision(10);
    // cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, limit;
    cin >> n >> limit;

    vi length(n), price(n);

    repa(i, length) cin >> i;
    repa(i, price) cin >> i;

    cout << recursion(length, price, n - 1, limit) << endl;

    return 0;
}
