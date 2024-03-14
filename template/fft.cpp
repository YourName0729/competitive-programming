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

/// fft module
//      author: mpfeifer1 
//      ref: https://github.com/mpfeifer1/Kattis/blob/master/kinversions.cpp

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