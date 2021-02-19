//
// https://open.kattis.com/problems/dasort
#include <iostream>
//#include <deque>
#include <algorithm>
//#include <cmath>
#include <vector>
#include <stack>

using namespace std;

int n, a[1010];
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int t, th;
    cin >> t;
    while (t--) {
        while (!stk.empty())    stk.pop();
        
        cin >> th >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            
            while (!stk.empty() && stk.top() > a[i])    stk.pop();
            stk.push(a[i]);
        }
        
        sort(a, a + n);
        
        while (!stk.empty() && stk.top() > a[stk.size() - 1])   stk.pop();
        
        cout << th << ' ' << n - stk.size() << '\n';
    }

    
    return 0;
} 