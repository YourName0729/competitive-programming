//
// https://open.kattis.com/problems/icpcawards
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

map<string, bool> m;

int main() {
    
    int n, cnt = 0;
    cin >> n;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (m[s1])  continue;
        if (cnt == 12)   break;

        cnt++;
        m[s1] = true;
        cout << s1 << ' ' << s2 << '\n';
    }

    return 0;
}
