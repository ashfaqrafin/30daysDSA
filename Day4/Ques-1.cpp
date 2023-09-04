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

    int n;
    cin >> n;
    vi remaning(n);

    iota(all(remaning), 1);

    while (remaning.size() > 1)
    {
        vi curRem;
        rep(i, 0, remaning.size())
        {
            if (i & 1)
            {
                cout << remaning[i] << " ";
            }
            else
            {
                curRem.pb(remaning[i]);
            }
        }

        if (remaning.size() & 1)
        {
            int starter = remaning.back();
            remaning.clear();
            curRem.pop_back();
            remaning.pb(starter);
            repa(i, curRem)
            {
                remaning.pb(i);
            }
        }
        else
        {
            remaning = curRem;
        }
    }

    cout << remaning[0] << endl;

    return 0;
}

