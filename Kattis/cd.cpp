// sorting_and_searching
// https://open.kattis.com/problems/cd
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin>>__t;for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int n, m;
int arr[1000010], brr[1000010];

int go() {
    int re = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr[i] == brr[j]) {
            re++;
            i++;
            j++;
        } else if (arr[i] < brr[j]) {
            i++;
        } else {
            j++;
        }
    }
    return re;
}

int main() {
    fast;

    while (cin >> n >> m && (n != 0 && m != 0)) {
        For (i, n) {
            cin >> arr[i];
        }
        For (i, m) {
            cin >> brr[i];
        }

        sort(arr, arr + n);
        sort(brr, brr + m);

        cout << go() << '\n';
    }

    return 0;
}