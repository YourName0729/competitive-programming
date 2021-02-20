//
// https://open.kattis.com/problems/bela
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
char d;

int dom[] = {0, 0, 14, 10, 20, 3,4, 11};
int ndom[] = {0,0,0,10,2,3,4,11};

int id(char c) {
    switch (c) {
        case '7': return 0;
        case '8': return 1;
        case '9': return 2;
        case 'T': return 3;
        case 'J': return 4;
        case 'Q': return 5;
        case 'K': return 6;
        case 'A': return 7;
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> d;
    int sum = 0;
    For (i, n * 4) {
        char c, s;
        cin >> c >> s;
        if (s == d) {
            sum += dom[id(c)];
        }
        else {
            sum += ndom[id(c)];
        }
    }

    cout << sum << '\n';
    

    return 0;
}
