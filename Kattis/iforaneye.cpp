// string_processing
// https://open.kattis.com/problems/iforaneye
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

string arr[] = {"at", "and", "are", "bee", "bea", "be", "one", "owe", "oh", "won", "why", "eye", "four", "for", "two", "too", "to", "sea", "see", "you"};
char to[] =  {  '@',  '&',   'r',   'b',   'b',   'b',  '1',   'o',   'o',  '1',   'y',   'i',   '4',    '4',   '2',   '2',   '2',  'c',   'c',   'u'};

bool upper(char c) {
    return ('A' <= c && c <= 'Z');
}

char to_upper(char c) {
    if ('a' <= c && c <= 'z')   return c - 'a' + 'A';
    return c;
}

bool match(string& s, int i, int j) {
    if (i + arr[j].length() - 1 >= s.length())  return false;
    For (k, arr[j].length()) {
        if (s[i + k] + upper(s[i + k]) * ('a' - 'A') != arr[j][k])  return false;
    }
    return 1;
}

void trim(string& s) {
    for (int i = 0; i < s.length(); i++) {
        bool flg = 0;
        For (j, 20) {
            if (match(s, i, j)) {
                flg = 1;
                cout << (upper(s[i])? to_upper(to[j]) : to[j]);
                i += arr[j].length() - 1;
                break;
            }
        }
        if (!flg)   cout << s[i];
    }
}


int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    getchar();
    while (n--) {
        string s;
        stringstream ss;
        getline(cin, s);
        ss << s;
        while (ss >> s) {
            trim(s);
            cout << ' ';
        }
        cout << '\n';
    }
    

    return 0;
}