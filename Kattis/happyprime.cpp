// 
// https://open.kattis.com/problems/happyprime#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ull = unsigned long long;
using ll = long long;
using namespace std;

bool prime(int num) {
    if (num == 1)   return false;

    for (int i = 2; i < num; i++) {
        if (i > sqrt(num) + 1)  return true;
        if (num % i == 0)   return false;
    }
    return true;
}

int nxtHappy(int num) {
    int re = 0;
    while (num) {
        re += (num % 10) * (num % 10);
        num /= 10;
    }
    return re;
}

bool happy(int num) {
    int it1 = num, it2 = nxtHappy(num);
    while (true) {
        if (it2 == 1)   return true;
        if (it1 == it2) return false;

        it1 = nxtHappy(it1);
        it2 = nxtHappy(nxtHappy(it2));
    }
}

int main() {

    int n;
    cin >> n;
    For (i, n) {
        int k, num;
        cin >> k >> num;
        cout << k << ' ' << num << ' ';

        if (prime(num) && happy(num)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


    return 0;
}