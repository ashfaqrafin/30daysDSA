#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

bool cmp(range &a, range &b)
{
    if (a.left == b.left)
    {
        return a.right > b.right;
    }
    return a.left < b.left;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<range> ranges(n);
    vector<int> contained(n);
    vector<int> contains(n);
    ordered_set<pair<int, int>> rightBoundaries;

    rep(i, 0, n)
    {
        cin >> ranges[i].left;
        cin >> ranges[i].right;
        ranges[i].index = i;
    }

    sort(ranges.begin(), ranges.end(), cmp);

    rep(i, 0, n)
    {
        rightBoundaries.insert({ranges[i].right, -i});
        contained[ranges[i].index] =
            rightBoundaries.size() - rightBoundaries.order_of_key({ranges[i].right, -i}) - 1;
    }

    rightBoundaries.clear();
    repn(i, n - 1, 0)
    {
        rightBoundaries.insert({ranges[i].right, -i});
        contains[ranges[i].index] = rightBoundaries.order_of_key({ranges[i].right, -i});
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
}
