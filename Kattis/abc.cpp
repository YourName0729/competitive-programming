//
// https://open.kattis.com/problems/abc
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin>>__t;for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int a[3];
string s;

string c = "ABC";

int main() {
    fast;

    cin >> a[0] >> a[1] >> a[2];
    cin >> s;

    sort(a, a + 3);
    For (i, 3) {
        For (j, 3) {
            if (s[i] == c[j]) {
                cout << a[j] << ' ';
            }
        }
    }
    cout << '\n';

    return 0;
}