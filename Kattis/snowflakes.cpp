// sorting_and_searching
// https://open.kattis.com/problems/snowflakes
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9;//1e9 + 7;
const ll INF = 1e18;

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> n;
        queue<int> que;
        set<int> st;
        int ans = 0;
        int d;
        For (i, n) {
            cin >> d;
            while (st.count(d)) {
                st.erase(que.front());
                que.pop();
            }
            que.push(d);
            st.insert(d);
            ans = max(ans, (int)que.size());
        }
        cout << ans << '\n';
    }


    return 0;
}