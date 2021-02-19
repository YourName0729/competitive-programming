// divide_and_conquer
// https://open.kattis.com/problems/froshweek
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <utility>
#include <queue>
#include <iomanip>
#include <deque>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

ll ans = 0;
int n;
int arr[1000100];
int tmp[1000100];

void move(int from, int to) {
    tmp[to] = arr[from];
    ans += abs(from - to);
}

void m_sort(int bot, int top) {
    if (bot == top) return;

    int mid = (bot + top) / 2;
    m_sort(bot, mid);
    m_sort(mid + 1, top);

    int l = bot, r = mid + 1, k = bot;
    while (l <= mid && r <= top) {
        if (arr[l] == arr[r]) {
            move(l, k);
            k++;
            move(r, k);
            k++; l++; r++;
        } else if (arr[l] < arr[r]) {
            move(l, k);
            k++; l++;
        } else {
            move(r, k);
            k++; r++;
        }
    }

    while (l <= mid) {
        move(l, k);
        k++; l++;
    }
    while (r <= top) {
        move(r, k);
        k++; r++;
    }

    for (int i = bot; i <= top; i++) {
        arr[i] = tmp[i];
    }
}

int main() {

    cin >> n;
    For (i, n) {
        cin >> arr[i];
    }

    m_sort(0, n - 1);

    cout << ans / 2 << '\n';

    // For (i, n) {
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';

    return 0;
}