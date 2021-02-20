//
// https://open.kattis.com/problems/bijele
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
    int arr[6];
    int cmp[6] = {1, 1, 2, 2, 2, 8};

    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < 6; i++) {
        cout << cmp[i] - arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}
