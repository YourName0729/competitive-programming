//
// https://open.kattis.com/problems/detaileddifferences
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
    string a, b;
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << a << '\n' << b << '\n';
        for (int i = 0; i < a.length(); i++) {
            cout << (a[i] == b[i]? '.' : '*');
        }
        cout << "\n\n";
    }


    return 0;
}
