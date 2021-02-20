//
// https://open.kattis.com/problems/encodedmessage
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

char c[110][110];
string s;

int srt(int d) {
    for (int i = 0; i < 110; i++) {
        if (i * i == d)
            return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        int w = srt(s.length());

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < w; j++) {
                c[i][j] = s[i * w + j];
            }
        }

        for (int i = w - 1; i >= 0; i--) {
            for (int j = 0; j < w; j++) {
                cout << c[j][i];
            }
        }
        cout << '\n';
    }

    return 0;
}
