//
// https://open.kattis.com/problems/anagramcounting
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include <map>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ull = unsigned long long;
using ll = long long;
using namespace std;

class BigInt {
public:
    BigInt() {
        for (int i = 0; i < 200; i++) {
            num[i] = 0;
        }
    }
    BigInt(int d) {
        if (d == 0) return;
        num[0] = d;
        size = 1;
        BigInt();
    }

    friend bool operator==(const BigInt& b1, const BigInt& b2) {
        if (b1.size != b2.size) return false;
        for (int i = 0; i < b1.size; i++) {
            if (b1.num[i] != b2.num[i]) {
                return false;
            }
        }
        return true;
    } 
    friend bool operator!=(const BigInt& b1, const BigInt& b2) {
        return !(b1 == b2);
    }

    friend BigInt operator+(const BigInt& b1, const BigInt& b2) {
        BigInt re;
        for (int i = 0; i < std::max(b1.size, b2.size); i++) {
            re.num[i] += b1.num[i] + b2.num[i];
            re.carry(i);
        }
        return re;
    }
    friend BigInt operator*(const BigInt& b1, const BigInt& b2) {
        BigInt re;
        for (int i = 0; i < b1.size; i++) {
            for (int j = 0; j < b2.size; j++) {
                re.num[i + j] += b1.num[i] * b2.num[j];
                re.carry(i + j);
            }
        }
        return re;
    }

    friend std::ostream& operator<<(std::ostream& out, const BigInt& b) {
        if (b.size == 0) {
            out << '0';
            return out;
        }

        out << b.num[b.size - 1];
        for (int i = b.size - 2; i >= 0; i--) {
            int d = BigInt::dgtOfLL(b.num[i]);
            for (int j = 0; j < BigInt::LogMod - d; j++) {
                out << '0';
            }
            if (b.num[i] != 0)
                out << b.num[i];
        }
        return out;
    }

protected:
    void carry(int dgt) {
        size = std::max(size, dgt + 1);

        if (num[dgt] > Mod) {
            num[dgt + 1] += num[dgt] / Mod;
            num[dgt] %= Mod;
            carry(dgt + 1);
        }
    }


    static int dgtOfLL(long long ll) {
        int re = 0;
        while (ll) {
            re++;
            ll /= 10;
        }
        return re;
    }

    long long num[200];
    int size = 0;

    const static int LogMod = 9;
    const static long long Mod = 1e9;
};

BigInt c[210][210];
map<char, int> mp;

int main() {

    For (i, 205) {
        c[0][i] = BigInt(1);
        c[i][0] = BigInt(1);
    }
    for (int i = 1; i < 205; i++) {
        for (int j = 1; j < 205; j++) {
            c[i][j] = c[i - 1][j] + c[i][j - 1];
        }
    }

    string s;
    while (getline(cin, s)) {
        mp.clear();
        For (i, s.length()) {
            mp[s[i]]++;
        }

        int sum = 0;
        Fore (p, mp) {
            sum += p.second;
        }

        BigInt ans(1);
        Fore (p, mp) {
            ans = ans * c[sum - p.second][p.second];
            sum -= p.second;
        }

        cout << ans << '\n';
    }

    return 0;
}