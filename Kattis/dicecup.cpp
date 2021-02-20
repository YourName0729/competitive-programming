//
// https://open.kattis.com/problems/dicecup
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

int v[45];

int main() {
    
    int a, b;
    cin >> a >> b;

    for (int i = min(a, b) + 1; i <= max(a, b) + 1; i++) {
        cout << i << '\n';
    }
    

    return 0;
}
