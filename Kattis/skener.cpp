//
// https://open.kattis.com/problems/skener
#include <iostream>

using namespace std;

char arr[100][100];

int main() {
    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < r; i++) {

        for (int l = 0; l < zr; l++) {
            for (int j = 0; j < c; j++) {
                for (int k = 0; k < zc; k++) {
                    cout << arr[i][j];
                }
            }
            cout << '\n';
        }
        
    }

    return 0;
}
