//
// https://open.kattis.com/problems/weakvertices
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

int n;
bool d[21][21];
bool is[21];

void go(int cur) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][cur] && d[j][cur] && d[i][j]) {
                is[i] = true;
                is[j] = true;
                is[cur] = true;
                return;
            }
        }
    }
}

int main() {
    
    while (cin >> n && n != -1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp;
                cin >> tmp;
                d[i][j] = (tmp == 1);
            }
        }

        for (int i = 0; i < n; i++) {
            is[i] = false;
        }

        for (int i = 0; i < n; i++) {
            if (is[i])  continue;

            go(i);
        }

        for (int i = 0; i < n; i++) {
            if (!is[i]) {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
