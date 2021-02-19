// number_theory
// https://open.kattis.com/problems/leapfrog
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forcase int __t;cin >> __t;while (__t--)

using namespace std;

long long modInverse(long long a, long long m) { 
    long long m0 = m; 
    long long y = 0, x = 1; 
  
    if (m == 1) return 0; 
  
    while (a > 1) { 
        long long q = a / m, t = m;
  
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 

    if (x < 0) x += m0; 
    return x; 
} 

struct P {
    long long m;
    vector<vector<long long>> v;
};

int n;
vector<P> vec;

void Push(long long x, long long d) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].m == d) {
            for (int j = 0; j < vec[i].v.size(); j++) {
                if ((vec[i].v[j][0] - x) % d == 0) {
                    vec[i].v[j].push_back(x);
                    return;
                }
            }

            vector<long long> newv;
            newv.push_back(x);
            vec[i].v.push_back(newv);
            return;
        }
    }

    P tmp;
    tmp.m = d;
    vector<long long> newv;
    newv.push_back(x);
    tmp.v.push_back(newv);
    vec.push_back(tmp);
}

void Trim() {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].v.size(); j++) {
            sort(vec[i].v[j].begin(), vec[i].v[j].end());
        }
    }
}

size_t maxW(const P& p) {
    size_t mx = 0;
    for (int i = 0; i < p.v.size(); i++) {
        mx = max(mx, p.v[i].size());
    }
    return mx;
}

int makeHeight() {
    int re = 0;
    for (int i = 0; i < vec.size(); i++) {
        re += maxW(vec[i]);
    }
    return re;
}

long long ans = -1;
int ch[50];
void cal();
void makech(int cur) {
    if (cur == vec.size()) {
        /*cout << "cal: ";
        for (int i = 0; i < vec.size(); i++) {
            cout << ch[i] << ' ';
        }
        cout << "\n";*/
        cal();
        return;
    }

    size_t mx = maxW(vec[cur]);
    for (int i = 0; i < vec[cur].v.size(); i++) {
        if (mx == vec[cur].v[i].size()) {
            ch[cur] = i;
            makech(cur + 1);
        }
    }
}

void cal() {
    long long M = 1;
    for (int i = 0; i < vec.size(); i++) {
        M *= vec[i].m;
    }

    long long x = 0;
    for (int i = 0; i < vec.size(); i++) {
        long long a = vec[i].v[ch[i]].front() % vec[i].m;
        long long t = modInverse((M / vec[i].m) % vec[i].m, vec[i].m);

        //cout << a << ' ' << t << ' ' << M / vec[i].m << ' ' << '\n';

        x += a * t * (M / vec[i].m);
    }

    x %= M;

    long long upper = 0;
    for (int i = 0; i < vec.size(); i++) {
        upper = max(upper, vec[i].v[ch[i]].back());
    }

    //cout << "upper = " << upper << '\n';

    if (upper > x) {
        if ((upper - x) % M == 0) {
            x = upper;
        } else {
            x += M * ((upper - x) / M + 1);
        }
    }

    //cout << "x = " << x << '\n';

    if (ans == -1) {
        ans = x;
    } else {
        ans = min(ans, x);
    }
}

void show() {
    for (int i = 0; i < vec.size(); i++) {
        cout << "m = " << vec[i].m << '\n';
        for (int j = 0; j < vec[i].v.size(); j++) {
            cout << "  ";
            for (int k = 0; k < vec[i].v[j].size(); k++) {
                cout << vec[i].v[j][k] << ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    fast;

    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        long long d;

        cin >> x >> d;
        Push(x, d);
    }

    Trim();
    //show();

    int height = makeHeight();
    makech(0);

    cout << ans << ' ' << height << '\n';

    return 0;
}
