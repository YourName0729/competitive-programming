//
// https://open.kattis.com/problems/simpleaddition
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-9;

class BigInt {
public:
    BigInt() {
        size = 0;
        for (int i = 0; i < 2000; i++) {
            num[i] = 0;
        }
    }
    BigInt(int d) : BigInt() {
        if (d == 0) return;
        num[0] = d;
        size = 1;
    }
    BigInt(const std::string& str) : BigInt() {
        if (str.length() % LogMod == 0) {
            size = str.length() / LogMod;
            for (int i = size - 1; i >= 0; i--) {
                num[i] = stoi(str.substr((size - i - 1) * LogMod, LogMod));
            }
        } else {
            size = str.length() / LogMod + 1;
            int last = str.length() -  str.length() / LogMod * LogMod;
            num[size - 1] = stoi(str.substr(0, last));
            for (int i = size - 2; i >= 0; i--) {
                num[i] = stoi(str.substr((size - i - 2) * LogMod + last, LogMod));
            }
        }

        trim();
    }

    int digit() const {
        if (size == 0)  return 0;
        return (size - 1) * LogMod + dgtOfLL(num[size - 1]);
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
    friend bool operator<(const BigInt& b1, const BigInt& b2) {
        if (b1.digit() != b2.digit())   return b1.digit() < b2.digit();
        for (int i = b1.size - 1; i >= 0; i--) {
            if (b1.num[i] != b2.num[i]) {
                return b1.num[i] < b2.num[i];
            }
        }
        return false;
    }
    friend bool operator>(const BigInt& b1, const BigInt& b2) {
        return !(b1 < b2) && !(b1 == b2);
    }
    friend bool operator<=(const BigInt& b1, const BigInt& b2) {
        return b1 < b2 || b1 == b2;
    }
    friend bool operator>=(const BigInt& b1, const BigInt& b2) {
        return b1 > b2 || b1 == b2;
    }

    friend BigInt operator+(const BigInt& b1, const BigInt& b2) {
        BigInt re;
        for (int i = 0; i < std::max(b1.size, b2.size); i++) {
            re.num[i] += b1.num[i] + b2.num[i];
            re.carry(i);
        }
        return re;
    }
    friend BigInt operator-(const BigInt& b1, const BigInt& b2) {
        BigInt re = b1;
        for (int i = 0; i < re.size; i++) {
            if (re.num[i] < b2.num[i]) {
                re.num[i] += Mod;
                re.num[i + 1]--;
            }
            re.num[i] -= b2.num[i];
        }
        re.trim();
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



    friend std::istream& operator>>(std::istream& in, BigInt& b) {
        std::string s;
        in >> s;
        b = BigInt(s);
        return in;
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

        if (num[dgt] >= Mod) {
            num[dgt + 1] += num[dgt] / Mod;
            num[dgt] %= Mod;
            carry(dgt + 1);
        }
    }


    static int dgtOfLL(long long l) {
        int re = 0;
        while (l) {
            re++;
            l /= 10;
        }
        return re;
    }

    void trim() {
        while (size != 0 && num[size - 1] == 0) {
            size--;
        }
    }

    long long num[2000];
    int size = 0;

    const static int LogMod = 9;
    const static long long Mod = 1e9;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    BigInt a, b;
    cin >> a >> b;
    cout << a + b;

    

    return 0;
}