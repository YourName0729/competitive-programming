//
// https://open.kattis.com/problems/insert
#include <vector>
#include <algorithm>
#include <iostream>

#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ull = unsigned long long;
using ll = long long;
using namespace std;

class BigInt {
public:
    BigInt() {
        for (int i = 0; i < 400; i++) {
            num[i] = 0;
        }
    }
    BigInt(int d) {
        if (d == 0) return;
        num[0] = d;
        size = 1;
        BigInt();
    }

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
        out << b.num[b.size - 1];
        for (int i = b.size - 2; i >= 0; i--) {
            int d = dgtOfLL(b.num[i]);
            for (int j = 0; j < LogMod - d; j++) {
                out << '0';
            }
            if (b.num[i] != 0)
                out << b.num[i];
        }
        return out;
    }

    long long num[400];
    int size = 0;

    const static int LogMod = 9;
    const static long long Mod = 1e9;
};

struct Node {
    int val = -1, s = -1;
    Node *l = NULL, *r = NULL;
};

Node* root;
BigInt c[220][220];

void push(Node* cur, int val) {
    if (cur->val == -1) {
        cur->val = val;
        return;
    }
    if (cur->val <= val) {
        if (cur->r == NULL) {
            cur->r = new Node;
        }
        push(cur->r, val);
    } else {
        if (cur->l == NULL) {
            cur->l = new Node;
        }
        push(cur->l, val);
    }
}

int size(Node* cur) {
    if (cur == NULL)    return 0;
    if (cur->s != -1)   return cur->s;
    cur->s = size(cur->l) + size(cur->r) + 1;
    return cur->s;
}

BigInt ans(Node* cur) {
    if (cur->l == NULL && cur->r == NULL)   return BigInt(1);
    if (cur->l == NULL) return ans(cur->r);
    if (cur->r == NULL) return ans(cur->l);

    return c[size(cur->l)][size(cur->r)] * ans(cur->l) * ans(cur->r);
}

void del(Node* cur) {
    if (cur == NULL)    return;
    del(cur->l);
    del(cur->r);
    delete cur;
}

int main() {

    For (i, 200) {
        c[i][0] = BigInt(1);
        c[0][i] = BigInt(1);
    }
    for (int i = 1; i < 200; i++) {
        for (int j = 1; j < 200; j++) {
            c[i][j] = c[i - 1][j] + c[i][j - 1];
        }
    }

    int n;
    while (cin >> n && n != 0) {
        root = new Node;

        For (i, n) {
            int tmp;
            cin >> tmp;
            push(root, tmp);
        }

        cout << ans(root) << '\n';

        del(root);
    }

    return 0;
}