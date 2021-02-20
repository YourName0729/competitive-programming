//
// https://open.kattis.com/problems/plantingtrees
#include <vector>
#include <algorithm>
#include <iostream>

#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ll = long long;
using namespace std;

vector<int> vec;

int main() {
    
    int n;
    cin >> n;
    For (i, n) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());

    int mx = n + vec[0];
    For (i, vec.size()) {
        mx = max(mx, n - i + vec[i]);
    }
    cout << mx + 1 << '\n';

    return 0;
}
