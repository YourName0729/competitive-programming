//
// https://open.kattis.com/problems/allaboutthatbase
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int d(char c) {
    if ('0' <= c && c <= '9')    return c - '0';
    return c - 'a' + 10;
}
char c(int a) {
    if (a < 10) return '0' + a;
    return 'a' + (a - 10);
}

string sym(long long d, int base) {
    string re;

    while (d) {
        re = c(d % base) + re;
        d /= base;
    }

    return re;
}

bool valid(string& s, long long base) {
    if (base == 1) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '1')    return false;
        }
        return true;
    } else {
        for (int i = 0; i < s.length(); i++) {
            if (d(s[i]) >= base) {
                return false;
            }
        }
        return true;
    }
    
}

long long num(string& s, int base) {
    long long re = 0, p = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        //cout << s[i] << ' ' << d(s[i]) << '\n';
        re += d(s[i]) * p;
        p *= base;
    }
    return re;
}

int main() {
    
    int n;
    cin >> n;
    getchar();

    while (n--) {
        string s;
        stringstream ss;
        getline(cin, s);
        ss << s;

        string sx, sy, sans, sop, tmp;
        ss >> sx >> sop >> sy >> tmp >> sans;
        vector<int> val;
        //cout << num(sx, 16) << ' ' << num(sy, 16) << '\n';
        for (int i = 1; i <= 36; i++) {
            if (valid(sx, i) && valid(sy, i) && valid(sans, i))  {
                bool ok = false;
                
                if (sop == "+") {
                    ok = num(sx, i) + num(sy, i) == num(sans, i);
                } else if (sop == "-") {
                    ok = num(sx, i) - num(sy, i) == num(sans, i);
                } else if (sop == "*") {
                    ok = num(sx, i) * num(sy, i) == num(sans, i);
                } else if (sop == "/") {
                    if (num(sx, i) % num(sy, i) == 0) {
                        ok = num(sx, i) / num(sy, i) == num(sans, i);
                    }
                }

                if (ok) {
                    val.push_back(i);
                }
            }
        }

        if (val.empty()) {
            cout << "invalid\n";
        } else {
            for (int i = 0; i < val.size(); i++) {
                if (val[i] == 36) {
                    cout << "0";
                } else {
                    cout << c(val[i]);
                }
            }
            cout << '\n';
        }

    }

    return 0;
}