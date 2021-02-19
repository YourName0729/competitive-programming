// implement
// https://open.kattis.com/problems/basicprogramming1
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

int n, t;
ll arr[200010];
bool v[200010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t;
    For (i, n) {
        cin >> arr[i];
    }

    if (t == 1) {
        cout << "7";
    }
    else if (t == 2) {
        if (arr[0] > arr[1]) {
            cout << "Bigger";
        }
        else if (arr[0] == arr[1]) {
            cout << "Equal";
        }
        else {
            cout << "Smaller";
        }
    }
    else if (t == 3) {
        sort(arr, arr + 3);
        cout << arr[1];
    }
    else if (t == 4) {
        ll s = 0;
        For (i, n) {
            s += arr[i];
        }
        cout << s;
    }
    else if (t == 5) {
        ll s = 0;
        For (i, n) {
            if (arr[i] % 2 == 0) {
                s += arr[i];
            }
        }
        cout << s;
    }
    else if (t == 6) {
        For (i, n) {
            cout << (char)(arr[i] % 26 + 'a');
        }
    }
    else {
        int i = 0;
        while (1) {
            if (arr[i] >= n) {
                cout << "out";
                break;
            }
            v[i] = 1;
            i = arr[i];
            if (v[i]) {
                cout << "Cyclic";
                break;
            }
            if (i == n - 1) {
                cout << "Done";
                break;
            }
        }
    }

    return 0;
}