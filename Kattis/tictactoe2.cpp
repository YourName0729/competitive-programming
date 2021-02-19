// dp
// https://open.kattis.com/problems/tictactoe2
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

char a[3][3];
bool vst[20000];

int encode() {
    int re = 0;
    For (i, 3) {
        For (j, 3) {
            re *= 3;
            if (a[i][j] == 'O') re += 1;
            if (a[i][j] == 'X') re += 2;
        }
    }
    return re;
}

void decode(int d) {
    for (int i = 2; i >= 0; i--) {
        for (int j = 2; j >= 0; j--) {
            int x = d % 3;
            if (x == 0) a[i][j] = '.';
            if (x == 1) a[i][j] = 'O';
            if (x == 2) a[i][j] = 'X';
            d /= 3;
        }
    }
}


int lines() {
    int re = 0;
    For (i, 3) {
        if (a[i][0] != '.' && a[i][0] == a[i][1] && a[i][1] == a[i][2]) re++;
        if (a[0][i] != '.' && a[0][i] == a[1][i] && a[1][i] == a[2][i]) re++;
    }

    if (a[0][0] != '.' && a[0][0] == a[1][1] && a[1][1] == a[2][2]) re++;
    if (a[0][2] != '.' && a[0][2] == a[1][1] && a[1][1] == a[2][0]) re++;
    return re;
}

int xs() {
    int re = 0;
    For (i, 3) For (j, 3)
        if (a[i][j] == 'X') re++;
    return re;
}

int os() {
    int re = 0;
    For (i, 3) For (j, 3)
        if (a[i][j] == 'O') re++;
    return re;
}

void dfs(int c) {
    if (vst[c]) return;
    vst[c] = true;
    decode(c);
    if (lines() == 1)   return;
    
    For (i, 3) {
        For (j, 3) {
            if (a[i][j] == '.') {
                if (xs() == os()) {
                    a[i][j] = 'X';
                }
                else {
                    a[i][j] = 'O';
                }
                dfs(encode());
                a[i][j] = '.';
            }
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);

    dfs(0);

    Forcase {
        int xs = 0, os = 0;

        For (i, 3) {
            For (j, 3) {
                cin >> a[i][j];
                if (a[i][j] == 'O') os++;
                if (a[i][j] == 'X') xs++;
            }
        }

        if (vst[encode()]) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    

    return 0;
}