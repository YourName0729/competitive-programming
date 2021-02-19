// number_theory
// https://open.kattis.com/problems/bestrational
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int M;
double x;

int bestp(int q) {
    double xq = x * q;
    int p1 = xq;
    if (p1 == M)    return p1;
    double dif1 = abs(x - p1 / (double)q);
    double dif2 = abs(x - (p1 + 1) / (double)q);
    if (dif1 < dif2)    return p1;
    return p1 + 1;
}

int gcd(int a, int b) {
    if(b) while((a %= b) && (b %= a));
    return a + b;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int tt;
        cin >> tt;
        cin >> M >> x;

        int ansq, ansp;
        double ansdif;

        ansq = 1, ansp = bestp(1), ansdif = abs(x - bestp(1));

        for (int i = 1; i <= M; i++) {
            int q = i, p = bestp(i);
            
            double dif = abs(x - p / (double)q);
            //cout << "q, p " << q << ' ' << p << ' ' << dif << '\n';
            if (dif < ansdif) {
                ansq = q, ansp = p;
                ansdif = dif;
            }
        }

        int d = gcd(ansq, ansp);
        cout << tt << ' ' << ansp / d << '/' << ansq / d << '\n';

    }

    return 0;
}