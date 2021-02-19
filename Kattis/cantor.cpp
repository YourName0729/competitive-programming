//
// https://open.kattis.com/problems/cantor
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    while (getline(cin, s) && s != "END") {
        stringstream ss;
        //double d;
        double d;
        ss << s;
        ss >> d;

        if (d == 1 || d == 0) {
            cout << "MEMBER\n";
        }
        else {
            int x = 0;
            For (i, 6) {
                x *= 10;
                if (i + 2 < s.length()) {
                    x += s[i + 2] - '0';
                }
            }
            //cout << x << "!\n";
            
            set<int> st;
            while (1) {
                if (st.count(x)) {
                    cout << "MEMBER\n";
                    break;
                }
                st.insert(x);
                x *= 3;
                if (x / 1000000 == 1) {
                    cout << "NON-MEMBER\n";
                    break;
                }
                x %= 1000000;
            }
        }
    }

    return 0;
}