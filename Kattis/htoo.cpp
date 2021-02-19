//
// https://open.kattis.com/problems/htoo
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

struct D {
    int a[26] = {0};
};

D decode(string& s) {
    D re;
    int i = 0;
    while (i < s.length()) {
        //cout << s[i] << '\n';
        if (i + 1 == s.length() || s[i + 1] > '9' || s[i + 1] < '0') {
            re.a[s[i] - 'A']++;
            i++;
        }
        else {
            int d = 0;
            int j = i + 1;
            while (j < s.length() && s[j] <= '9' && s[j] >= '0') {
                d *= 10;
                d += s[j] - '0';
                j++;
            }
            re.a[s[i] - 'A'] += d;
            i = j;
        }
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    int d;
    cin >> s >> d;
    D a = decode(s);
    For (i, 26) {
        a.a[i] *= d;
    }

    cin >> s;
    D b = decode(s);

    int ans = -1;
    For (i, 26) {
        if (b.a[i] != 0) {
            if (ans == -1 || a.a[i] / b.a[i] < ans) {
                ans = a.a[i] / b.a[i];
            }
        }
    }

    cout << ans << '\n';

    return 0;
}