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
#define all(container) begin(container), end(container)
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

    int n, m, diff;
    cin >> n >> m >> diff;

    vi applicants(n), appartments(m);

    repa(i, applicants)
    {
        cin >> i;
    }
    repa(i, appartments)
    {
        cin >> i;
    }

    sort(all(applicants));
    sort(all(appartments));

    int ans = 0;

    int i = 0, j = 0;

    while (i < n and j < m)
    {
        if (abs(applicants[i] - appartments[j]) <= diff)
        {
            ans++;
            i++;
            j++;
        }
        else
        {
            if (applicants[i] - appartments[j] > diff)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}