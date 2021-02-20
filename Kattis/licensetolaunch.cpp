//
// https://open.kattis.com/problems/licensetolaunch
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

int a[100010];

int main() {
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[ans] > a[i]) {
            ans = i;
        }
    }
    cout << ans << '\n';

    return 0;
}
