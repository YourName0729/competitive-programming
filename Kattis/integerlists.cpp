// implement
// https://open.kattis.com/problems/integerlists
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

int n;
int arr[100010];


int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        bool rev = 0;
        string q;
        cin >> q;
        cin >> n;
        char c;
        cin >> c;
        For (i, n) {
            cin >> arr[i]; 
            if (i != n - 1) cin >> c;
        }
        cin >> c;

        int l = 0, r = n - 1;
        For (i, q.length()) {
            if (q[i] == 'R') {
                rev = !rev;
            }
            else {
                if (rev) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }

        if (r < l - 1) {
            cout << "error\n";
        }
        else {
            if (rev) {
                cout << '[';
                for (int i = r; i >= l; i--) {
                    cout << arr[i];
                    if (i != l) {
                        cout << ',';
                    }
                }
                cout << ']';
            }
            else {
                cout << '[';
                for (int i = l; i <= r; i++) {
                    cout << arr[i];
                    if (i != r) {
                        cout << ',';
                    }
                }
                cout << ']';
            }
            cout << '\n';
        }
    }

    return 0;
}