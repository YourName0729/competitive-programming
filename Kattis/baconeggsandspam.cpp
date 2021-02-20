// 
// https://open.kattis.com/problems/baconeggsandspam
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

map<string, vector<string>> m;

int main() {
    int n;
    string s, name, food;

    while (cin >> n && n != 0) {
        getchar();

        string s;

        for (int i = 0; i < n; i++) {
            stringstream ss;
            getline(cin, s);
            ss << s;
            ss >> name;
            while (ss >> food) {
                m[food].push_back(name);
            }
        }


        for (map<string, vector<string>>::iterator it = m.begin(); it != m.end(); it++) {
            cout << it->first << ' ';
            sort(it->second.begin(), it->second.end());
            for (int i = 0; i < it->second.size(); i++) {
                cout << it->second[i] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';

        m.clear();
    }

    return 0;
}