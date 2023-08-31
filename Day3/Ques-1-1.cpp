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

struct range
{
    int left, right, index;
};

signed main(void)
{
    int n;
    cin >> n;

    vector<range> arr(n);
    int x, y;

    rep(i, 0, n)
    {
        cin >> x >> y;
        arr[i].left = x;
        arr[i].right = y;
        arr[i].index = i;
    }

    sort(all(arr), [&](range a, range b)
         {
if(a.left==b.left)return a.right>b.right;
return a.left<b.left; });

    vi contained(n);
    vi contains(n);

    int maxr = 0;
    int minr = INT_MAX;
    rep(i, 0, n)
    {
        if (arr[i].right <= maxr)
        {
            contained[arr[i].index] = 1;
        }
        maxr = max(maxr, arr[i].right);
    }

    repn(i, n - 1, 0)
    {
        if (arr[i].right >= minr)
        {
            contains[arr[i].index] = 1;
        }
        minr = min(minr, arr[i].right);
    }

    repa(i, contains)
    {
        cout << i << " ";
    }
    cout << endl;
    repa(i, contained)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
