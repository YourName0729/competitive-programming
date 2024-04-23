// https://open.kattis.com/problems/includescoring
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 2147483647;

int n;
ar<int, 6> arr[1010];

int score[30] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
        arr[i][0] = -arr[i][0];
        arr[i][4] = i;
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        // if (j != n) cout << (arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1] && arr[i][2] == arr[j][2]) << '\n';
        for (; j < n && 
            arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1] && arr[i][2] == arr[j][2];
            ++j
        );
        // cout << i << ' ' << j << " ?\n";
        int sm = 0;
        for (int k = i; k < j; ++k) sm += k < 30? score[k] : 0;
        for (int k = i; k < j; ++k) arr[k][5] = (int)ceil((double)sm / (j - i)) + arr[k][3]; 
        i = j - 1;
    }

    sort(arr, arr + n, [](const ar<int, 6>& a, const ar<int, 6>& b) { return a[4] < b[4]; } );

    for (int i = 0; i < n; ++i) cout << arr[i][5] << '\n';

    return 0;
}