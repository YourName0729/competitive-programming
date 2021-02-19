//
// https://open.kattis.com/problems/towering
#include <iostream>
//#include <deque>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

int a[7];
bool c[7];
int t1, t2;

void go(int cur) {
    if (cur == 7) {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            sum += (c[i] ? a[i] : 0);
            if (c[i])   cnt++;
        }
        if (cnt != 3)   return;
        //cout << "sum = " << sum << '\n';
        if (sum == t1)  throw 0;
        
        return; 
    }
    go(cur + 1);
    c[cur] = true;
    go(cur + 1);
    c[cur] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    for (int i = 0; i < 6; i++) c[i] = false;
    for (int i = 0; i < 6; i++) cin >> a[i];
    cin >> t1 >> t2;

    sort(a, a + 6);

    try {
        go(0);
    } catch (int b) {
        for (int i = 5; i >= 0; i--)
            if (c[i])   cout << a[i] << ' ';
        for (int i = 5; i >= 0; i--) 
            if (!c[i])  cout << a[i] << ' ';
        
        cout << '\n';
    }
    

    
    return 0;
} 