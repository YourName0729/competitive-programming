// https://open.kattis.com/problems/cake
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 2147483647;

int p, q, n;
vector<ar<int, 2>> arr;

struct line {
    int x;
    vector<int> ys;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> p >> q >> n;
    For (i, n) {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }

    sort(arr.begin(), arr.end());

    vector<line> vec;
    for (auto [x, y] : arr) {
        if (vec.empty() || vec.back().x != x) vec.push_back({x, vector<int>({y})});
        else vec.back().ys.push_back(y);
    }

    for (int i = 0; i < vec.size(); ++i) {
        int x = vec[i].x;
        for (int j = 0; j < vec[i].ys.size(); ++j) {
            int y = vec[i].ys[j];

            cout << (i == 0? 1 : vec[i - 1].x + 1) << ' ';
            cout << (j == 0? 1 : vec[i].ys[j - 1] + 1) << ' ';
            cout << (i == vec.size() - 1? p : x) << ' ';
            cout << (j == vec[i].ys.size() - 1? q : y) << '\n';
        }
    }
    cout << "0\n";

    return 0;
}