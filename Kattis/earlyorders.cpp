// sorting_and_searching
// https://open.kattis.com/problems/earlyorders
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;

int k, n;
int a[200000];
stack<int> stk;
map<int, int> m;
set<int> st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> k >> n;
    For (i, k) {
        cin >> a[i];
        m[a[i]]++;
    }

    For (i, k) {
        m[a[i]]--;
        if (m[a[i]] == 0)   m.erase(a[i]);

        if (st.count(a[i])) continue;

        while (!stk.empty() && stk.top() > a[i] && m.count(stk.top())) {
            st.erase(stk.top());
            stk.pop();
        }

        stk.push(a[i]);
        st.insert(a[i]);
    }

    stack<int> cp;
    while (!stk.empty()) {
        cp.push(stk.top());
        stk.pop();
    }

    while (!cp.empty()) {
        cout << cp.top() << ' ';
        cp.pop();
    }

    return 0;
}