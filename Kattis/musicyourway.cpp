//
// https://open.kattis.com/problems/musicyourway
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

int n, m, q;
vector<string> atb;
vector<vector<string>> vec;
int idx;

bool cmp(vector<string> a, vector<string> b) {
    return a[idx] < b[idx];
}


int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    getline(cin, s);
    stringstream ss;
    ss << s;
    while (ss >> s) {
        atb.push_back(s);
    }

    m = atb.size();

    cin >> n;
    For (i, n) {
        vector<string> song;
        For (j, m) {
            cin >> s;
            song.push_back(s);
        }
        vec.push_back(song);
    }
    
    cin >> q;
    For (i, q) {
        cin >> s;
        For (j, atb.size()) {
            if (s == atb[j]) {
                idx = j;
                stable_sort(vec.begin(), vec.end(), cmp);
            }
        }

        For (j, atb.size()) {
            cout << atb[j] << ' ';
        }
        cout << '\n';
        For (j, n) {
            For (k, m) {
                cout << vec[j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}