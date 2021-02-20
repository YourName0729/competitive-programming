//
// https://open.kattis.com/problems/oddmanout
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>

#define Forcase int T; cin>>T; for(int t = 1; t <= T; t++)
#define Forever while(true)

using namespace std;

int n;
int a[1010];

int ans() {
    for (int i = 0; i < n + 1; i += 2) {
        if (a[i] != a[i + 1]) {
            return a[i];
        }
    }
    if (a[n - 1] != a[n - 2]) {
        return a[n - 1];
    }
    return 0;
}

int main() {
    
    Forcase {
        
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        cout << "Case #" << t << ": " << ans() << '\n';
        
    }

    return 0;
}
