//
// https://open.kattis.com/problems/iwannabe
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#define For(i, n) for (int i = 0; i < n; i++)

using namespace std;
using ll = long long;

struct P {
    ll idx, val;
};

int n, k;
P a[1010], b[1010], c[1010];
map<int, int> m;

bool cmp(P a, P b) {
    return a.val < b.val;
}

int main() {
    cin >> n >> k;
    For (i, n) {
        cin >> a[i].val >> b[i].val >> c[i].val;
        a[i].idx = b[i].idx = c[i].idx = i;
    }
    
    sort(a, a + n, cmp);
    sort(b, b + n, cmp);
    sort(c, c + n, cmp);
    
    For (i, k) {
        m[a[n - i - 1].idx]++;
        m[b[n - i - 1].idx]++;
        m[c[n - i - 1].idx]++;
    }
    
    cout << m.size() << '\n';
    

    return 0;
}