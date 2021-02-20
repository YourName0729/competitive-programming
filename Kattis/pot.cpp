//
// https://open.kattis.com/problems/pot
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

long long Pow(int e, int p) {
    if (p == 0) return 1;
    return e * Pow(e, p - 1);
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        ans += Pow(d / 10, d % 10);
    }
    cout << ans << '\n';
    

    return 0;
}
