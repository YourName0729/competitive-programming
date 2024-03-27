// https://open.kattis.com/problems/letterwheels
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

bool xy[5010]; // can i-shifted x match y
bool yz[5010]; // can i-shifted y match z
bool xz[5010]; // can i-shifted x match z

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string x, y, z;
    cin >> x >> y >> z;

    int n = x.length();
    for (int i = 0; i < n; ++i) {
        xy[i] = xz[i] = yz[i] = true;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            xy[i] &= x[(i + j) % n] != y[j];
            yz[i] &= y[(i + j) % n] != z[j];
            xz[i] &= x[(i + j) % n] != z[j];
        }
    }

    int ans = MOD;
    for (int i = 0; i < n; ++i) {
        // shift x by i
        for (int j = 0; j < n; ++j) {
            // shift y by j
            if (xy[(i - j + n) % n] && xz[i] && yz[j]) {
                // cout << i << ' ' << j << '\n';
                vector<int> vec = {max(i, j), max(n - i, n - j), min(i, n - i) + min(j, n - j)};
                int v = *min_element(vec.begin(), vec.end());
                ans = min(ans, v);
            }
        }
    }

    cout << (ans == MOD? -1: ans) << '\n';

    return 0;
}