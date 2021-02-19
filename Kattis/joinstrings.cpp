// linked_list
// https://open.kattis.com/problems/joinstrings
#include <iostream>
#include <string>
#include <vector>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int n;
vector<string> s;
int tail[100010];
int nxt[100010];

int main() {
    fast;


    cin >> n;

    string ss;
    For (i, n) {
        cin >> ss;
        s.push_back(ss);

        nxt[i] = i;
        tail[i] = i;
    }

    int a, b;
    For (i, n - 1) {
        cin >> a >> b;
        a--;
        b--;

        int x = tail[a];
        while (tail[x] != x) {
            x = tail[x];
        }

        tail[a] = b;
        nxt[x] = b;
    }

    while (nxt[a] != a) {
        cout << s[a];
        a = nxt[a];
    }
    cout << s[a] << '\n';

    return 0;
}
 rs