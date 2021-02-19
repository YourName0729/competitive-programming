// disjoint_set
// https://open.kattis.com/problems/unionfind
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long

using namespace std;

class DisjoitSet {
public:
    DisjoitSet(int N) {
        rt.resize(N);
        rnk.resize(N, 1);
        for (int i = 0; i < N; ++i) rt[i] = i;
        n = N;
    }

    size_t Size() const {
        return n;
    }

    void Union(int a, int b) {
        int fa = root(a), fb = root(b);
        if (fa == fb)   return;

        n--;
        if (rnk[fa] > rnk[fb]) rt[fb] = rt[fa];
        else if (rnk[fa] < rnk[fb]) rt[fa] = rt[fb];
        else {
            rt[fa] = fb;
            rnk[fb]++;
        }
    }

    bool InSameUnion(int a, int b) {
        return root(a) == root(b);
    }

protected:
    int root(int i) {
        if (rt[i] == i) return i;
        return rt[i] = root(rt[i]);
    }

    int n;
    vector<int> rt, rnk;
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;
    DisjoitSet ds(n);
    For (i, q) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == '?') {
            cout << (ds.InSameUnion(a, b)? "yes" : "no") << '\n'; 
        }
        else {
            ds.Union(a, b);
        }
    }
    

    return 0;
}