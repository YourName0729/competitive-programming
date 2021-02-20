//
// https://open.kattis.com/problems/tripletexting
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> m;

int main()
{
    string s;
    cin >> s;
    int n = s.length() / 3;
    for (int i = 0; i < s.length() / 3; i++) {
        m.clear();
        m[s[i]]++;
        m[s[i + n]]++;
        m[s[i + 2 * n]]++;
        
        for (auto p : m) {
            if (p.second >= 2) {
                cout << p.first;
                break;
            }
        }
    }
    cout << '\n';

    return 0;
}
