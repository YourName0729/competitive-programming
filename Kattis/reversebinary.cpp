//
// https://open.kattis.com/problems/reversebinary
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    while (n) {
        ans *= 2;
        ans += n % 2;
        n /= 2;
    }

    cout << ans << '\n';

    return 0;
}
