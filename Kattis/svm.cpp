// https://open.kattis.com/problems/svm
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
vector<double> w, q;
double b;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    w.resize(n);
    for (int i = 0; i < n; ++i) cin >> w[i];
    cin >> b;
    
    double nor = sqrt(inner_product(w.begin(), w.end(), w.begin(), 0.0));

    q.resize(n);
    while (cin >> q[0]) {
        for (int i = 0; i < n - 1; ++i) cin >> q[i + 1];

        cout << fixed << setprecision(16) << (inner_product(w.begin(), w.end(), q.begin(), 0.0) + b) / nor << '\n';
    }

    return 0;
}