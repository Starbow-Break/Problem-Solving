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
node segTree[1 << 18];
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
        segTree[idx<<1].lazy += segTree[idx].lazy;
        segTree[(idx<<1)|1].lazy += segTree[idx].lazy;
    }
    
    segTree[idx].value += segTree[idx].lazy;
    segTree[idx].lazy = 0;
}

void update(int l, int r, int idx, int i, int j, int w) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].lazy += w;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r) >> 1;
    update(l, mid, idx<<1, i, j, w); update(mid+1, r, (idx<<1)|1, i, j, w);
    segTree[idx].value = segTree[idx<<1].value+segTree[(idx<<1)|1].value;
}

int query(int l, int r, int idx, int i) {
    propagate(l, r, idx);
    
    if(r < i || i < l) return 0;
    
    if(l == r) return segTree[idx].value;
    
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, i)+query(mid+1, r, (idx<<1)|1, i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int v; cin >> v;
        if(v != -1) edges[v].push_back(i);
    }
    
    dfs();
    
    while(m--) {
        int q; cin >> q;
        if(q == 1) {
            int i, w; cin >> i >> w;
            update(1, n, 1, in[i], out[i], w);
        }
        else {
            int i; cin >> i;
            cout << query(1, n, 1, in[i]) << '\n';
        }
    }

    return 0;
}