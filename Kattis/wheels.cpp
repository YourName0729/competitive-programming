// DFS
// https://open.kattis.com/problems/wheels
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
ar<int, 5> arr[1010];

bool near(int i, int j) {
    int dx = arr[i][0] - arr[j][0];
    int dy = arr[i][1] - arr[j][1];
    int r = arr[i][2] + arr[j][2];
    return dx * dx + dy * dy == r * r;
}

void trim(int& p, int& q) {
    if (q == 0) return;
    if (q < 0) {
        q *= -1, p *= -1;
    }

    int g = __gcd(abs(p), q);
    p /= g, q /= g;
}

void dfs(int cur) {
    For (i, n) {
        if (arr[i][4] == 0 && near(cur, i)) {
            arr[i][3] = -1 * arr[cur][3] * arr[cur][2];
            arr[i][4] = arr[cur][4] * arr[i][2];
            trim(arr[i][3], arr[i][4]);
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    Forcase {
        cin >> n;
        For (i, n) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
            arr[i][4] = 0;
        }

        arr[0][3] = arr[0][4] = 1;
        dfs(0);

        For (i, n) {
            if (arr[i][4] == 0) {
                cout << "not moving\n";
            }
            else {
                cout << abs(arr[i][3]);
                if (arr[i][4] != 1)
                    cout << '/' << arr[i][4];
                cout << ' ';
                cout << (arr[i][3] > 0? "clockwise" : "counterclockwise") << '\n';
            }
        }
    }
 
    return 0;
}