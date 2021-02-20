//
// https://open.kattis.com/problems/batterup
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
    
    int n, cnt = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp >= 0) {
            cnt++;
            sum += tmp;
        }
    }

    cout << fixed << sum / double(cnt) << '\n';

    return 0;
}
