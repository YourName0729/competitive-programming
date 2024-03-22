
#include <bits/stdc++.h>

using namespace std;

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

// for minimum vertex cover and maximum independet set

// bool vstx2[X] = {0}, vsty2[Y] = {0};

// void dfs2(int x) {
//     // x should be unmatched in mx[x]
//     vstx2[x] = true;
//     for (auto y : g[x]) {
//         vsty2[y] = true;
//         if (int nx = my[y]; nx != -1 && !vstx2[nx])
//             dfs2(nx);
//     }
// }

// vertex cover are the visited xs and unvisited ys
// independet set are the unvisited xs and visited ys