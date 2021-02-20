//
// https://open.kattis.com/problems/pokerhand
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin>>__t;while(__t--)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int arr[14];

int main() {
    fast;

    string s[5];
    For (i, 5) {
        cin >> s[i];
    }

    For (i, 5) {
        char c = s[i][0];
        if (c == 'A') {
            arr[1]++;
        } else if (c == 'J') {
            arr[11]++;
        } else if (c == 'T') {
            arr[10]++;
        } else if (c == 'Q') {
            arr[12]++;
        } else if (c == 'K') {
            arr[13]++;
        } else {
            arr[c - '0']++;
        }
    }

    int mx = 0;
    for (int i = 1; i < 14; i++) {
        mx = max(mx, arr[i]);
    }

    cout << mx << '\n';
    
    return 0;
}
