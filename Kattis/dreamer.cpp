//
// https://open.kattis.com/problems/dreamer
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

int arr[8];
int ear[8];

void fetch(int a[], int& d, int& m, int& y) {
    d = a[0] * 10 + a[1];
    m = a[2] * 10 + a[3];
    y = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7];
}

bool leap(int y) {
    if (y % 400 == 0)   return 1;
    if (y % 100 == 0)   return 0;
    if (y % 4 == 0) return 1;
    return 0;
}

bool legal() {
    int d, m, y;
    fetch(arr, d, m, y);
    if (y < 2000 || m > 12 || d > 31 || m == 0 || d == 0)   return false;
    if (m == 2) {
        if (leap(y))    return d <= 29;
        return d <= 28;
    }
    else if (m <= 7) {
        return d <= (30 + m % 2);
    }
    else {
        return d <= (30 + (m + 1) % 2);
    }
}

bool earlier() {
    int ed, em, ey, cd, cm, cy;
    fetch(ear, ed, em, ey);
    fetch(arr, cd, cm, cy);
    if (ey != cy)   return cy < ey;
    if (em != cm)   return cm < em;
    if (ed != cd)   return cd < ed;
    return false;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    
    Forcase {
        For (i, 8) {
            char c;
            cin >> c;
            arr[i] = c - '0';
        }
        sort(arr, arr + 8);

        
        int cnt = 0, ans = 0;
        bool fst = true;
        do {
            if (legal()) {
                cnt++;
                if (fst || earlier()) {
                    For (i, 8)  ear[i] = arr[i];
                }
                fst = false;
            }
            ans++;
        } while (next_permutation(arr, arr + 8));

        cout << cnt << ' ';

        if (cnt != 0) {
            cout << ear[0] << ear[1] << ' ';
            cout << ear[2] << ear[3] << ' ';
            For (i, 4) {
                cout << ear[i + 4];
            }
        }

        
        cout << '\n';
    }

    return 0;
}