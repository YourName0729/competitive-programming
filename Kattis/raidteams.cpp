// sorting_and_searching
// https://open.kattis.com/problems/raidteams
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-9;

int n;
pair<ll, int> a1[100010], a2[100010], a3[100010];
string as[100010];
bool vst[100010];

bool cmp(pair<ll, int> a, pair<ll, int> b) {
    if (a.first == b.first)   return as[a.second] < as[b.second];
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        cin >> as[i] >> a1[i].first >> a2[i].first >> a3[i].first;
        a1[i].second = a2[i].second = a3[i].second = i;
    }
    sort(a1, a1 + n, cmp);
    sort(a2, a2 + n, cmp);
    sort(a3, a3 + n, cmp);

    // For (i, n) {
    //     cout << as[a1[i].second] << ' ' << as[a2[i].second] << ' ' << as[a3[i].second] << '\n';
    // }

    int a = 0, b = 0, c = 0;
    while (1) {
        while (a < n && vst[a1[a].second]) a++;
        if (a == n) break;
        vst[a1[a].second] = 1;
        while (b < n && vst[a2[b].second]) b++;
        if (b == n) break;
        vst[a2[b].second] = 1;
        while (c < n && vst[a3[c].second]) c++;
        if (c == n) break;
        vst[a3[c].second] = 1;
        vector<string> ans = {as[a1[a].second], as[a2[b].second], as[a3[c].second]};
        sort(ans.begin(), ans.end());
        For (i, 3) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        //cout << as[a1[a].second] << ' ' << as[a2[b].second] << ' ' << as[a3[c].second] << '\n';
    }

    return 0;
}