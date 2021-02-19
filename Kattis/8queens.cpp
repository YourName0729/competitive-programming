// implement
// https://open.kattis.com/problems/8queens
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

char tb[8][8];
int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

bool ok(int x, int y) {
    For (i, 8) {
        int nx = x + dx[i], ny = y + dy[i];
        while (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
            if (tb[nx][ny] == '*') {
                return false;
            }
            nx += dx[i];
            ny += dy[i];
        }
    }
    return true;
}

bool valid() {
    int q = 0;
    For (i, 8) {
        For (j, 8) {
            if (tb[i][j] == '*')    q++;
            if (tb[i][j] == '*' && !ok(i, j)) {
                return false;
            }
        }
    }
    return q == 8;
}

int main() {
    //fast;

    For (i, 8) {
        For (j, 8) {
            cin >> tb[i][j];
        }
    }

    if (valid()) {
        cout << "valid\n";
    } else {
        cout << "invalid\n";
    }

    return 0;
}