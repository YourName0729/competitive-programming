// https://open.kattis.com/problems/subway
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

size_t rotl(size_t x, int c) {
    return x << c | x >> (64 - c);
}

string reorder(const string& s, int l, int r) {
    vector<string> vec;
    int cnt = 0;
    int prv = l;
    for (int i = l; i <= r; ++i) {
        cnt -= s[i] - '0' + s[i] - '0' - 1;
        if (cnt == 0) { 
            vec.push_back(reorder(s, prv + 1, i - 1));
            prv = i + 1;
        }
    }

    sort(vec.begin(), vec.end());

    string re;
    for (auto& v : vec) {
        re += '0' + v + '1';
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string a, b;

    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << (reorder(a, 0, a.length() - 1) == reorder(b, 0, b.length() - 1)? "same" : "different") << '\n';
    }

    return 0;
}