//
// https://open.kattis.com/problems/whatdoesthefoxsay
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <deque>
#include <numeric>
#include <iomanip>

#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;
using namespace std;

const ll INF = 1000000010;
const ll MOD = 1000000007;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string arr[110];
bool vst[110];

int main() {
    //fast();

    forcase {
        string s;
        stringstream ss;
        getline(cin, s);
        ss << s;

        int n = 0;
        while (ss >> s) {
            arr[n] = s;
            n++;
        }

        For (i, n) {
            vst[i] = false;
        }

        while (true) {
            getline(cin, s);
            if (s == "what does the fox say?")  break;
            stringstream ss2;
            ss2 << s;
            string tmp, sound;
            ss2 >> tmp >> tmp >> sound;
            For (i, n) {
                if (arr[i] == sound) {
                    vst[i] = true;
                }
            }
        }

        For (i, n) {
            if (!vst[i]) {
                cout << arr[i] << ' ';
            }
        }
        cout << '\n';
        // cout << n << '\n';
        // For (i, n) {
        //     cout << arr[i] << vst[i] << '\n';
        // }
    }

    return 0;
}