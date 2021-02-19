//
// https://open.kattis.com/problems/chartingprogress
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
string arr[110];
int cnt[110];

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);

    do {
        int n = 0, m;
        while (getline(cin, arr[n])) {
            if (arr[n] != "")   n++;
            else break;
        }
        if (n == 0) break;
        m = arr[0].length();

        For (i, n) {
            int cnt2 = 0;
            For (j, m) {
                if (arr[i][j] == '*') cnt2++;
            }
            cnt[i] = cnt2;
        }

        int pre = m;
        For (i, n) {
            pre -= cnt[i];
            For (j, pre)    cout << '.';
            For (j, cnt[i]) cout << '*';
            For (j, m - pre - cnt[i]) cout << '.';
            cout << '\n';
        }
        cout << '\n';
        
    } while (true);
    

    return 0;
}