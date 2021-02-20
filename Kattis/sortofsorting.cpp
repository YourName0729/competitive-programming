//
// https://open.kattis.com/problems/sortofsorting
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define INF 2000000000

#define MOD 1000000007

using ll = long long;

using namespace std;

int n;
vector<string> vec;

int w(char c) {
    if ('A' <= c && c <= 'Z')   return c - 'A';
    return c - 'a' + 26;
}
bool cmp(const string& s1, const string& s2) {
    if (w(s1[0]) < w(s2[0]))    return true;
    if (w(s1[0]) > w(s2[0]))    return false;
    if (w(s1[1]) < w(s2[1]))    return true;
    if (w(s1[1]) > w(s2[1]))    return false;
    return false;
}

int main() {
    fast;

    while (cin >> n && n != 0) {
        vec.clear();
        For (i, n) {
            string tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        stable_sort(vec.begin(), vec.end(), cmp);
        For (i, n) {
            cout << vec[i] << '\n';
        }
        cout << '\n';    
    }   

    return 0;
}
