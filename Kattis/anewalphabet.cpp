#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

string sym[26] = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "\'][\'", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};

int main() {
    fast;

    string s;
    getline(cin, s);

    For (i, s.length()) {
        if ('a' <= s[i] && s[i] <= 'z') {
            cout << sym[s[i] - 'a'];
        } else if ('A' <= s[i] && s[i] <= 'Z') {
            cout << sym[s[i] - 'A'];
        } else {
            cout << s[i];
        }
    }
    cout << '\n';

    return 0;
}//
// https://open.kattis.com/problems/anewalphabet
