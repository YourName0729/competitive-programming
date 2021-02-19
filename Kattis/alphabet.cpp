//
// https://open.kattis.com/problems/alphabet
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <utility>
#include <queue>
#include <iomanip>
#include <deque>
#include <set>
#include <functional>

#define Forcase int __t;cin>>__t;for(int cases=1;cases<=__t;cases++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define LINF 1e18
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

int LIS(vector<int>& s)
{
    // 不得不判斷的特例
    if (s.size() == 0) return 0;
 
    // 先放入一個數字，免得稍後 v.back() 出錯。
    vector<int> v;
    v.push_back(s[0]);
 
    for (int i = 1; i < s.size(); ++i)
    {
        int n = s[i];
 
        if (n > v.back())
            v.push_back(n);
        else
            *lower_bound(v.begin(), v.end(), n) = n;
    }
 
    return v.size();
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    string s;
    cin >> s;

    vector<int> vec;
    For (i, s.length()) {
        vec.push_back(s[i]);
    }

    cout << 26 - LIS(vec) << '\n';
    

    return 0;
}