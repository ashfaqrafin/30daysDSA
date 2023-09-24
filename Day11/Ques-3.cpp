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

bool isPossible(vi &given, int &k, int max_sum)
{
    int cur_sum = 0, count = 0;

    repa(i, given)
    {
        if (i > max_sum)
            return false;

        if (cur_sum + i > max_sum)
        {
            count++;
            cur_sum = 0;
        }
        cur_sum += i;
    }

    if (cur_sum > 0)
        count++;
    return count <= k;
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

    int left = 1, right = (2e5 * 1e9);

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (isPossible(given, k, mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << left << endl;

    return 0;
}

