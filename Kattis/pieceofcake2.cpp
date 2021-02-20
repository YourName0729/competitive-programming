//
// https://open.kattis.com/problems/pieceofcake2
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
    int n, a, b;
    cin >> n >> a >> b;
    a = max(a, n - a);
    b = max(b, n - b);

    cout << 4 * a * b << '\n';

    return 0;
}
