//
// https://open.kattis.com/problems/kemija08
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin>>__t;while(__t--)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int arr[14];

bool m(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    fast;

    string s;
    getline(cin, s);
    
    string ans;
    For (i, s.length()) {
        ans += s[i];
        if (m(s[i])) {
            i += 2;
        }
    }

    cout << ans << '\n';

    return 0;
}
