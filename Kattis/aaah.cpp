//
// https://open.kattis.com/problems/aaah
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin>>__t;for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int aaa(string& s) {
    int re = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a')
            re++;
    }
    return re;
}

int main() {
    fast;

    string a, b;
    cin >> a >> b;
    int c = aaa(a), d = aaa(b);
    if (c < d) {
        cout << "no\n";
    } else {
        cout << "go\n";
    }

    return 0;
}
