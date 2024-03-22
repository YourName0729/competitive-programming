// https://open.kattis.com/problems/codenames
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

/// bipartite matching
//      ref: https://web.ntnu.edu.tw/~algo/Matching.html
//      also sovles minimum vertex cover and maximum independet set

const int N = 510;
int mch[N];	// match index, -1 if no match
bool vst[N]; 		
vector<int> g[N];

int n;
string s[510];

bool dfs(int x)
{
	for (auto y : g[x]) {
		if (vst[y]) continue;

        vst[y] = true;

        if (mch[y] == -1 || dfs(mch[y]))
        {
            //mch[x] = y; 
            mch[y] = x;
            return true;
        }
    }
	return false;
}

int bipartite_matching()
{
	memset(mch, -1, sizeof(mch));

	int c = 0;
	for (int x = 0; x < n; ++x) {
        memset(vst, false, sizeof(vst));
        if (dfs(x)) c++;
    }
	return c; // the size of maximum matching or the minimum vertex cover
    // return size(x) + size(y) - c / 2; // the size of maximum independet set
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    For (i, n) cin >> s[i];
    For (i, n) For (j, n) {
        int cnt = 0;
        For (k, s[0].length()) {
            cnt += s[i][k] != s[j][k];
        }
        if (cnt == 2) {
            g[i].push_back(j);
            g[j].push_back(i);
        }
    } 

    int ans = bipartite_matching();
    //cout << ans << '\n';
    cout << n - ans / 2 << '\n';

    return 0;
}