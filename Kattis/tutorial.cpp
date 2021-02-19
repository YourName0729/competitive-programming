//
// https://open.kattis.com/problems/tutorial
#include <iostream>
#include <cmath>

using namespace std;

bool go(bool a) {
    if (a) {
        cout << "AC\n";
    } else {
        cout << "TLE\n";
    }
    return a;
}

bool t2(long long m, long long n) {
    long long sum = 1;
    for (int i = 1; i <= n; i++) {
        sum *= 2;

        if (m < sum) {
            return false;
        }
    }
    return true;
}

bool t1(long long m, long long n) {
    long long sum = 1;
    for (int i = 1; i <= n; i++) {
        sum *= i;

        if (m < sum) {
            return false;
        }
    }
    return true;
}

int main() {
    long long m, n;
    int t;

    cin >> m >> n >> t;
    if (t == 7) {
        go(m >= n);
    } else if (t == 6) {
        go(m >= n * log2(double(n)));
    } else if (t == 5) {
        go(m >= n * n);
    } else if (t == 4) {
        go(m >= n * n && m >= n * n * n);
    } else if (t == 3) {
        go(m >= n * n && m >= n * n * n && m >= n * n * n * n);
    } else if (t == 2) {
        go(t2(m, n));
    } else if (t == 1) {
        go(t1(m, n));
    }

    return 0;
}