//
// https://open.kattis.com/problems/grassseed
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

int main() {
    
    double c;
    int n;
    double a, b, ans = 0;

    cin >> c >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ans += a * b;
    }
    cout << fixed << c * ans << '\n';

    return 0;
}
