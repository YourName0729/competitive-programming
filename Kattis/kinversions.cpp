// https://open.kattis.com/problems/kinversions
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

void nextpow(ll& n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
}

ll fft_size(ll x) {
    x++;
    nextpow(x);
    x++;
    nextpow(x);
    return x;
}

void fft(valarray<complex<double>>& x) {
    ll s = x.size();

    if(s <= 1) {
        return;
    }

    valarray<complex<double>> even = x[slice(0, s/2, 2)];
    valarray<complex<double>> odd  = x[slice(1, s/2, 2)];

    fft(even);
    fft(odd);

    for(ll i = 0; i < s/2; i++) {
        complex<double> t = polar(1.0, -2.0 * M_PI * i / s) * odd[i];
        x[i]     = even[i] + t;
        x[i+s/2] = even[i] - t;
    }
}

void ifft(valarray<complex<double>>& x) {
    x = x.apply(conj);
    fft(x);
    x = x.apply(conj);
    x /= x.size();
}

template<typename T>
vector<T> poly_pow(vector<T>& a, vector<T>& b) {
    // 1. Assume a.size() == b.size()
    // 2. Assume a.size() = 2^k for some int k
    ll sz = a.size();

    valarray<complex<double>> v1(sz);
    valarray<complex<double>> v2(sz);

    for (int i = 0; i < a.size(); i++) v1[i] = a[i];
    for (int i = 0; i < b.size(); ++i) v2[i] = b[i];

    fft(v1);
    fft(v2);

    for (int i = 0; i < sz; ++i) v1[i] *= v2[i];

    ifft(v1);

    vector<T> re(sz);
    for (int i = 0; i < sz; ++i) re[i] = (T)(v1[i].real() + .25);
    return re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;

    int sz = fft_size(s.length());
    vector<int> a(sz), b(sz);
    for (int i = 0; i < s.length(); ++i) {
        a[i] = s[i] == 'A';
        b[sz - i - 1] = s[i] == 'B'; 
    }

    vector<int> ans = poly_pow(a, b);

    for (int i = 0; i < s.length() - 1; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}