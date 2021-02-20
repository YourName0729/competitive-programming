// 
// https://open.kattis.com/problems/aliennumbers
#include <iostream>
#include <string>
#include <map>
#include <vector>

#define For(i, n) for (int i = 0; i < n; i++)

using namespace std;

string s1, s2, d;

string dec2sys(long long num, string sys) {
    string re;
    
    while (num) {
        re = sys[num % sys.length()] + re;
        num /= sys.length();
    }
    
    return re;
}

long long sys2dec(string sys, string ds) {
    long long re = 0;
    
    for (int i = 0; i < ds.length(); i++) {
        For (j, sys.length()) {
            if (ds[i] == sys[j]) {
                re *= sys.length();
                re += j;
                break;
            }
        }
    }
    
    return re;
}

int main() {
    
    int t;
    cin >> t;
    For (i, t) {
        cin >> d >> s1 >> s2;
        
        cout << "Case #" << i + 1 << ": " << dec2sys(sys2dec(s1, d), s2) << '\n';
    }

    return 0;
}
