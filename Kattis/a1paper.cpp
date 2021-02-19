//
// https://open.kattis.com/problems/a1paper
#include <iostream>
//#include <deque>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

long long n, a[1010];
double sqrt2;

double len(int cur, long long need, double w) {
    if (cur == n)   throw "";
    if (a[cur] >= need) return need * (w + w / sqrt2);
    return len(cur + 1, (need - a[cur]) * 2, w / sqrt2) + a[cur] * (w + w / sqrt2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    cin >> n;
    n--;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sqrt2 = pow(2, 0.5);
    
    try {
        cout << fixed << len(0, 2, pow(2, -3/4.0)) - pow(2, -3/4.0) - pow(2, -5/4.0) * 2;
    } catch (const char* cs) {
        cout << "impossible";
    }

    
    return 0;
} 