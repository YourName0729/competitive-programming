// https://open.kattis.com/problems/han
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

int n;
int bs = 0;
int cnt[26] = {0};
int prvk = 0, dir = 1, idx = 0;

void update(int k) {
    int step = k - prvk;
    bs += step / 26;
    step %= 26;

    for (int j = 0; j < step; ++j) {
        //cout << "write " << idx << '\n';
        ++cnt[idx];
        idx = (idx + dir + 26) % 26;
    }

    prvk = k;
}


int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    int k;
    char c;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s[0] == 'U') {
            cin >> k >> c;

            update(k);

            cout << cnt[c - 'a'] + bs << '\n';
        }
        else {
            cin >> k;
            update(k);
            idx = (idx - dir - dir + 26) % 26;
            dir = -dir;
        }
    }

    return 0;
}