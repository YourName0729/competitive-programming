/// lca.cpp
//      author: konchin
//      ref: https://hackmd.io/@konchin/ryhgIlhMu

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> g[100010];
int anc[100010][30];
int tin[100010], tout[100010];

void build(int cur, int pre) {
    static int t = 0;
    tin[cur] = t++;
    int k = pre;
    for (int i = 0; i <= __lg(n); i++)
        anc[cur][i] = k, k = anc[k][i];
    for (const auto& i : g[cur])
        if (i != pre)
            build(i, cur);
    tout[cur] = t++;
}

bool isanc(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
};

int lca(int a, int b) {
    if (isanc(a, b)) return a;
    if (isanc(b, a)) return b;
    for(int i = __lg(n); i >= 0; i--)
        if (!isanc(anc[a][i], b))
            a = anc[a][i];
    return anc[a][0];
};