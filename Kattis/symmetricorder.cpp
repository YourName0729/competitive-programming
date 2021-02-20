//
// https://open.kattis.com/problems/symmetricorder
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>

#define Forcase int T; cin>>T; for(int t = 1; t <= T; t++)
#define Forever while(true)

using namespace std;

string s[20];

int main() {
    int n, cnt = 0;
    while (cin >> n && n != 0) {
        cnt++;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        cout << "SET " << cnt << '\n';
        for (int i = 0; i < n; i += 2) {
            cout << s[i] << '\n';
        }
        for (int i = n / 2 * 2 - 1; i >= 0; i -= 2) {
            cout << s[i] << '\n';
        }
        
    }

    return 0;
}
