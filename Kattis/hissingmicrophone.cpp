//
// https://open.kattis.com/problems/hissingmicrophone
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
    
    string s;
    cin >> s;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 's' && s[i + 1] == 's') {
            cout << "hiss\n";
            return 0;
        }
    }
    cout << "no hiss\n";
    

    return 0;
}
