//
// https://open.kattis.com/problems/bachetsgame
#include <iostream>
#include <string>
#include <map>
#include <vector>

#define For(i, n) for (int i = 0; i < n; i++)

using namespace std;

int w[1000010];
int num[21];
int n, m;

bool win(int cur) {
    if (w[cur] != -1) return w[cur] == 1;
    
    For (i, m) {
        if (cur >= num[i] && !win(cur - num[i])) {
            w[cur] = 1;
            return true;
        }
    }
    
    w[cur] = 0;
    return false;
}

int main() {
    
    while (cin >> n) {
        For (i, n + 1) {
            w[i] = -1;
        }
        
        cin >> m;
        For (i, m) {
            cin >> num[i];
        }
        
        w[0] = 0;
        For (i, m) {
            w[num[i]] = 1;
        }
        
        
        if (win(n)) {
            cout << "Stan wins\n";
        } else {
            cout << "Ollie wins\n";
        }
    }

    return 0;
}