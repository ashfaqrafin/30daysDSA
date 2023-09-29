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

struct s
{
    int sum, i, j;
};

bool cmp(s &a, s &b)
{
    return a.sum < b.sum;
}

s S[1000004];

signed main(void)
{

    // cout.precision(10);
    // cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    int count = 0;

    vi given(n);
    repa(i, given)
    {
        cin >> i;
    }
    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            S[count++] = {given[i] + given[j], i, j};
        }
    }

    sort(S, S + count, cmp);

    int p = count - 1;
    rep(i, 0, p)
    {
        while (S[i].sum + S[p].sum > target)
            p--;
        while (S[i].sum + S[p].sum == target and (S[i].i == S[p].i || S[i].i == S[p].j || S[i].j == S[p].i || S[i].j == S[p].j))
            p--;
        if (S[i].sum + S[p].sum == target)
        {
            cout << S[i].i + 1 << " " << S[i].j + 1 << " " << S[p].i + 1 << " " << S[p].j + 1 << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
