//
// https://open.kattis.com/problems/equalsumseasy
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin>>__t;for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int n;
vector<int> v1, v2;
map<int, int> mp1, mp2;

int Sum(vector<int>& v, int col) {
    int re = 0;
    for (int i = 0; i < v.size(); i++) {
        if ((1 << i) & col) {
            re += v[i];
        }
    }
    return re;
}

int build(vector<int>& v, map<int, int>& m) {
    bool ok = false;
    for (int i = 1; i < (1 << v.size()); i++) {
        int sum = Sum(v, i);
        if (m.count(sum)) {
            return i;
        }
        m[sum] = i;
    }
    return -1;
}

void show(vector<int>& v, int col) {
    For (i, 10) {
        if (col & (1 << i)) {
            cout << v[i] << ' ';
        }
    }
}

bool query() {
    for (auto p : mp1) {
        if (mp2.count(p.first)) {
            show(v1, p.second);
            cout << '\n';
            show(v2, mp2[p.first]);
            cout << '\n';
            return true;
        }
    }

    return false;
}

int main() {
    fast;

    forcase {
        v1.clear();
        v2.clear();
        mp1.clear();
        mp2.clear();

        cout << "Case #" << ___t << ":\n";
        cin >> n;

        int tmp;
        For (i, n) {
            cin >> tmp;
            if (i % 2 == 0) {
                v1.push_back(tmp);
            } else {
                v2.push_back(tmp);
            }  
        }

        int ans1 = build(v1, mp1);
        int ans2 = build(v2, mp2);

        if (ans1 != -1) {
            show(v1, ans1);
            cout << '\n';
            show(v1, mp1[Sum(v1, ans1)]);
            cout << '\n';
        } else if (ans2 != -1) {
            show(v2, ans2);
            cout << '\n';
            show(v2, mp2[Sum(v2, ans2)]);
            cout << '\n';
        } else if (query()) {

        } else {
            cout << "Impossible\n";
        }
    }

    return 0;
}