//
// https://open.kattis.com/problems/aboveaverage
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

int n;
double arr[1010];

int main() {
    //fast();

    forcase {
        cin >> n;
        double sum = 0;
        For (i, n) {
            cin >> arr[i];
            sum += arr[i];
        }

        double avg = sum / n;
        int ans = 0;
        For (i, n) {
            if (arr[i] > avg) {
                ans++;
            }
        }

        double flo = round(double(ans) * 100000 / n);

        cout << fixed << setprecision(3) << flo / 1000 << "%\n";
    }

    return 0;
}