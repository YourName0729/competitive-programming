// DFS connected_component binary_search
// https://open.kattis.com/problems/arcticnetwork
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

int n, s;
int xs[510], ys[510];
bool vst[510];

double dist(int i, int j) {
    double x = xs[i] - xs[j], y = ys[i] - ys[j];
    return sqrt(x * x + y * y);
}

void dfs(int cur, double d) {
    vst[cur] = 1;
    For (i, n) {
        if (!vst[i] && dist(cur, i) <= d) {
            dfs(i, d);
        }
    }
}

int cpn(double d) {
    For (i, n)  vst[i] = 0;
    int re = 0;
    For (i, n) {
        if (!vst[i]) {
            dfs(i, d);
            re++;
        }
    }
    return re;
}

bool ok(double d) {
    return cpn(d) <= s;
}

double bs() {
    double l = 0, r = 0;
    For (i, n) {
        For (j, n) {
            r = max(r, dist(i, j));
        }
    }

    while (r - l > 0.000001) {
        double mid = (l + r) / 2;
        if (ok(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> s >> n;
        For (i, n) {
            cin >> xs[i] >> ys[i];
        }
        cout << fixed << setprecision(2) << bs() << '\n';
    }
    
    return 0;
}