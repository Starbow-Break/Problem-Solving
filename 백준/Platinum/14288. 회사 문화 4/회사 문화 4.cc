#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX_N 100'000
#define MAX_M 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

struct node {
    int value = 0, lazy = 0;
};

vector<int> edges[MAX_N+1];
node segTree0[1 << 18]; int segTree1[1 << 18];
int in[MAX_N+1], out[MAX_N+1];

int ord = 0; bool visited[MAX_N+1] = {false, };
void dfs(int cur = 1) {
    ord++; in[cur] = ord;
    visited[cur] = true;
    
    for(auto &next: edges[cur]) {
        if(!visited[next]) dfs(next);
    }
    
    out[cur] = ord;
}

void propagate(int l, int r, int idx) {
    if(l != r) {
        segTree0[idx<<1].lazy += segTree0[idx].lazy;
        segTree0[(idx<<1)|1].lazy += segTree0[idx].lazy;
    }
    
    segTree0[idx].value += segTree0[idx].lazy;
    segTree0[idx].lazy = 0;
}

void update0(int l, int r, int idx, int i, int j, int w) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree0[idx].lazy += w;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r) >> 1;
    update0(l, mid, idx<<1, i, j, w); update0(mid+1, r, (idx<<1)|1, i, j, w);
    segTree0[idx].value = segTree0[idx<<1].value+segTree0[(idx<<1)|1].value;
}

int query0(int l, int r, int idx, int i) {
    propagate(l, r, idx);
    
    if(r < i || i < l) return 0;
    
    if(l == r) return segTree0[idx].value;
    
    int mid = (l+r)>>1;
    return query0(l, mid, idx<<1, i)+query0(mid+1, r, (idx<<1)|1, i);
}

void update1(int l, int r, int idx, int i, int w) {
    if(r < i || i < l) return;
    
    if(l == r) {
        segTree1[idx] += w; return;
    }
    
    int mid = (l+r) >> 1;
    update1(l, mid, idx<<1, i, w); update1(mid+1, r, (idx<<1)|1, i, w);
    segTree1[idx] = segTree1[idx<<1]+segTree1[(idx<<1)|1];
}

int query1(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree1[idx];
    
    int mid = (l+r)>>1;
    return query1(l, mid, idx<<1, i, j)+query1(mid+1, r, (idx<<1)|1, i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    int mode = 0;
    for(int i = 1; i <= n; i++) {
        int v; cin >> v;
        if(v != -1) edges[v].push_back(i);
    }
    
    dfs();
    
    while(m--) {
        int q; cin >> q;
        if(q == 1) {
            int i, w; cin >> i >> w;
            if(mode) update1(1, n, 1, in[i], w);
            else update0(1, n, 1, in[i], out[i], w);
        }
        else if(q == 2) {
            int i; cin >> i;
            cout << query0(1, n, 1, in[i])+query1(1, n, 1, in[i], out[i]) << '\n';
        }
        else mode = 1-mode;
    }

    return 0;
}