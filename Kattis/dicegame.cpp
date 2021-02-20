//
// https://open.kattis.com/problems/dicegame
#include <iostream>

using namespace std;

int a[4][2];
int sum[4];
int dis[4];

int f(int d) {
    return d * (d + 1) / 2;
}

int main() {
    
    for (int i = 0; i < 4; i++) {
        cin >> a[i][0] >> a[i][1];
        dis[i] = a[i][1] - a[i][0] + 1;
        sum[i] = f(a[i][1]) - f(a[i][0] - 1);
    }

    int all = dis[0] * dis[1] * dis[2] * dis[3];

    int e = all / dis[0] * sum[0] + all / dis[1] * sum[1];
    int g = all / dis[2] * sum[2] + all / dis[3] * sum[3];
    if (e > g) {
        cout << "Gunnar\n";
    } else if (e < g) {
        cout << "Emma\n";
    } else {
        cout << "Tie\n";
    }

    return 0;
}
