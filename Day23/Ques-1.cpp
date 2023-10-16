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

int retangle(vector<vector<int>> &given, int row)
{
    stack<int> helper;
    int n = given[row].size();

    vi left(n), right(n), ans(n);

    rep(i, 0, n)
    {
        if (helper.empty())
        {
            left[i] = 0;
            helper.push(i);
        }
        else
        {
            while (!helper.empty() and given[row][i] <= given[row][helper.top()])
                helper.pop();

            left[i] = (helper.empty()) ? 0 : helper.top() + 1;
            helper.push(i);
        }
    }
    helper = stack<int>();
    repn(i, n - 1, 0)
    {
        if (helper.empty())
        {
            right[i] = n - 1;
            helper.push(i);
        }
        else
        {
            while (!helper.empty() and given[row][i] <= given[row][helper.top()])
                helper.pop();
            right[i] = (helper.empty()) ? n - 1 : helper.top() - 1;
            helper.push(i);
        }
    }

    rep(i, 0, n)
    {
        ans[i] = (right[i] - left[i] + 1) * given[row][i];
    }
    return *max_element(all(ans));
}

signed main(void)
{

    // cout.precision(10);
    // cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int row, col;
    cin >> row >> col;
    vector<vector<int>> given(row, vector<int>(col));

    repa(i, given)
    {
        repa(j, i)
        {
            cin >> j;
        }
    }

    rep(i, 1, row)
    {
        rep(j, 0, col)
        {
            if (given[i][j])
            {
                given[i][j] += given[i - 1][j];
            }
        }
    }

    rep(i, 0, row)
    {
        cout << retangle(given, i) << endl;
    }

    return 0;
}
