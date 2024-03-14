// https://open.kattis.com/problems/ladice
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
int p[300010];
bool vst[300010] = {0};

int f(int u) {
    if (p[u] == u) return u;
    return p[u] = f(p[u]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int l;
    cin >> n >> l;
    for (int i = 0; i < l; ++i) p[i] = i;

    int u, v;
    for (int i = 0; i < n; ++i) {
        cin >> u >> v, --u, --v;
        //cout << " - " << f(u) << ' ' << f(v) << '\n';
        int x = f(u), y = f(v);

        if (x == y) {
            if (vst[x])    cout << "SMECE\n";
            else {
                vst[x] = true;
                cout << "LADICA\n";
            }
        }
        else {
            if (vst[x] && vst[y])  cout << "SMECE\n";
            else {
                vst[x] |= vst[y];
                p[y] = x;
                cout << "LADICA\n";
            }
            
        }
    }

    return 0;
}