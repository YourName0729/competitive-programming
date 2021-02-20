//
// https://open.kattis.com/problems/tri
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin>>__t;for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int a, b, c;

void print(string s) {
    printf(s.c_str(), a, b, c);
}

void go() {
    if (a == b + c) {
        print("%d=%d+%d\n");
    } else if (a == b - c) {
        print("%d=%d-%d\n");
    } else if (a == b * c) {
        print("%d=%d*%d\n");
    } else if (b % c == 0 && a == b / c) {
        print("%d=%d/%d\n");
    } else if (a + b == c) {
        print("%d+%d=%d\n");
    } else if (a - b == c) {
        print("%d-%d=%d\n");
    } else if (a * b == c) {
        print("%d*%d=%d\n");
    } else if (a % b == 0 && a / b == c) {
        print("%d/%d=%d\n");
    }
}

int main() {
    fast;


    cin >> a >> b >> c;
    go();

    return 0;
}
