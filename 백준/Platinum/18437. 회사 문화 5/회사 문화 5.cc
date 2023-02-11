#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX_N 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

struct node {
    int value, lazy;
};

node segTree[1<<18];
vector<int> edges[MAX_N+1];
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

void initTree(int l, int r, int idx) {
    segTree[idx].lazy = -1;
    
    if(l == r) {
        segTree[idx].value = 1;
        return;
    }
    
    int mid = (l+r)>>1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, (idx<<1)|1);
    segTree[idx].value = segTree[idx<<1].value+segTree[(idx<<1)|1].value;
}

void propagate(int l, int r, int idx) {
    if(segTree[idx].lazy != -1) {
        if(l != r) {
            segTree[idx<<1].lazy = segTree[idx].lazy;
            segTree[(idx<<1)|1].lazy = segTree[idx].lazy;
        }
        
        segTree[idx].value = (r-l+1)*segTree[idx].lazy;
        segTree[idx].lazy = -1;
    }
}

void update(int l, int r, int idx, int i, int j, int v) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].lazy = v;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, i, j, v); update(mid+1, r, (idx<<1)|1, i, j, v);
    segTree[idx].value = segTree[idx<<1].value+segTree[(idx<<1)|1].value;
}

int query(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx].value;
    
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, i, j)+query(mid+1, r, (idx<<1)|1, i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    initTree(1, N, 1);
    
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        if(v != 0) edges[v].push_back(i);
    }
    
    dfs();
    
    int Q; cin >> Q;
    while(Q--) {
        int q, i; cin >> q >> i;
        switch(q) {
            case 1:
                update(1, N, 1, in[i]+1, out[i], 1);
                break;
            case 2:
                update(1, N, 1, in[i]+1, out[i], 0);
                break;
            default:
                cout << query(1, N, 1, in[i]+1, out[i]) << '\n';
        }
    }

    return 0;
}