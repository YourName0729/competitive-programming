// https://open.kattis.com/problems/nonnegpartsums
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

template <class T>
class MinQueue {
public:
    stack< pair<T, T> > inbox, outbox;
    void enqueue(T val) {
        T m = val;
        if (!inbox.empty()) m = min(m, inbox.top().second);
        inbox.push(pair<T, T>(val, m));
    }
    bool dequeue(T* d = nullptr) {
        if (outbox.empty() && !inbox.empty()) {
            pair<T, T> t = inbox.top(); inbox.pop();
            outbox.push(pair<T, T>(t.first, t.first));
            while (!inbox.empty()) {
                t = inbox.top(); inbox.pop();
                T m = min(t.first, outbox.top().second);
                outbox.push(pair<T, T>(t.first, m));
            }
        }
        if (outbox.empty()) return false;
        else {
            if (d != nullptr) *d = outbox.top().first;
            outbox.pop();
            return true;
        }
    }
    bool empty() { return outbox.empty() && inbox.empty(); }
    size_t size() { return outbox.size() + inbox.size(); }
    T get_min() {
        if (outbox.empty()) return inbox.top().second;
        if (inbox.empty()) return outbox.top().second;
        return min(outbox.top().second, inbox.top().second);
    }
};

int n;
int a[1000010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n) {
        MinQueue<int> mq;
        int sum = 0;
        For (i, n) {
            cin >> a[i]; 
            sum += a[i];
            mq.enqueue(sum);
        }

        int ans = 0, pfx = 0;
        For (i, n) {
            if (mq.get_min() >= pfx) {
                ans++;
            }

            pfx += a[i];
            mq.dequeue();
            mq.enqueue(sum + pfx);
        }   

        cout << ans << '\n';
    }

    return 0;
}
