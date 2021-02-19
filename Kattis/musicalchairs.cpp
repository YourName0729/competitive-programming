// simulation
// https://open.kattis.com/problems/musicalchairs
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define Show(a,n) For(i,n) cout << a[i] << ' ';cout << '\n';
#define ll long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n;
int arr[10010], nxt[10010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    For (i, n) {
        cin >> arr[i];
        //arr[i] %= n;
        nxt[i] = i + 1;
    }
    nxt[n - 1] = 0;

    int cur = 0, rem = n;
    while (nxt[cur] != cur) {
        //cout << "at " << cur << '\n';
        int itr = (arr[cur] - 2) % rem;
        //cout << arr[cur] - 2 << ' ' << itr << '\n';
        For (i, itr) {
            //cout << "go one to " << nxt[cur] << '\n';
            cur = nxt[cur];
        }
        //cout << "kill " << nxt[cur] << '\n';
        rem--;
        nxt[cur] = nxt[nxt[cur]];
        cur = nxt[cur];
        //cout << "go one step " << cur << '\n';
    }

    cout << cur + 1 << '\n';

    return 0;
}