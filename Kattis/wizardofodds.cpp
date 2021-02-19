//
// https://open.kattis.com/problems/wizardofodds
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

int n, k;
string sn, sk;

bool one() {
    For (i, sn.length() - 1) {
        if (sn[i] != '0')   return 0;
    }
    return sn[sn.length() - 1] == '1';
}

void div() {
    int prv = 0;
    For (i, sn.length()) {
        if ((sn[i] - '0') % 2 != 0) {
            sn[i] = (sn[i] - '0' + prv * 10) / 2 + '0';
            prv = 1;
        }
        else {
            sn[i] = (sn[i] - '0' + prv * 10) / 2 + '0';
            prv = 0;
        }
    }
    if (prv) {
        sn.back()++;
    }
    for (int i = sn.length() - 1; i >= 0; i--) {
        if (sn[i] > '9') {
            sn[i] = '0';
            sn[i - 1]++;
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> sn >> sk;
    if (sk.length() > 3) {
        cout << "Your wish is granted!\n";
        return 0;
    }

    k = stoi(sk);
    
    For (i, k) {
        div();
        //cout << "sn " << sn << '\n';

        if (one()) {
            cout << "Your wish is granted!\n";
            return 0;
        }
    }
    cout << "You will become a flying monkey!\n";

    return 0;
}