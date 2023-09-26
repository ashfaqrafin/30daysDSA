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

    int n, target;
    cin >> n >> target;

    vector<pair<int, int>> values(n);

    int x;
    rep(i, 0, n)
    {
        cin >> x;
        values[i] = {x, i + 1};
    }

    sort(all(values));

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        if (values[left].first + values[right].first > target)
        {
            right--;
        }
        else if (values[left].first + values[right].first < target)
        {
            left++;
        }
        else
        {
            cout << values[left].second << " " << values[right].second << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}