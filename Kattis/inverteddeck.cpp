// searching
// https://open.kattis.com/problems/inverteddeck
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define For1(i, n) for(int i = 1; i <= n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n;
int arr[1000010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        cin >> arr[i];
    }

    int l = 0, r = n - 1;


    while (l + 1 < n && arr[l + 1] >= arr[l])    l++;
    while (r - 1 >= 0 && arr[r - 1] <= arr[r])   r--;

    if (l == n - 1) {
        cout << "1 1\n";
        return 0;
    }

    for (int i = l; i < r; i++) {
        if (arr[i + 1] > arr[i]) {
            cout << "impossible\n";
            return 0;
        }
    }

    while (l - 1 >= 0 && arr[l - 1] == arr[l])  l--;
    while (r + 1 < n && arr[r + 1] == arr[r])   r++;

    if ((r == n - 1 || arr[l] <= arr[r + 1]) && (l == 0 || arr[r] >= arr[l - 1])) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
    else {
        cout << "impossible\n";
    }




    return 0;
}