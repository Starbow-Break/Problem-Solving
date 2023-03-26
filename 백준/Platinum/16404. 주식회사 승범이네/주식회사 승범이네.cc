#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>
#define MAX_N 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct node {
    int money, lazy;
};

vector<int> edges[MAX_N+1];
node segTree[1 << 18];
int in[MAX_N+1], out[MAX_N+1];

int ord = 0;
bool visited[MAX_N+1] = {false, };
void dfs(int cur = 1) {
    in[cur] = ++ord;
    
    for(auto &next: edges[cur]) {
        if(!visited[next]) dfs(next);
    }
    
    out[cur] = ord;
}

void propagate(int l, int r, int idx) {
    if(l < r) {
        segTree[idx<<1].lazy += segTree[idx].lazy;
        segTree[idx<<1|1].lazy += segTree[idx].lazy;
    }
    
    segTree[idx].money += (r-l+1)*segTree[idx].lazy;
    segTree[idx].lazy = 0;
}

node merge(node &a, node &b) {
    return {a.money+b.money, a.lazy+b.lazy};
}

void update(int l, int r, int idx, int i, int j, int del) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].lazy += del;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, i, j, del); update(mid+1, r, idx<<1|1, i, j, del);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

int query(int l, int r, int idx, int t) {
    propagate(l, r, idx);
    
    if(r < t || t < l) return 0;
    
    if(l == r) return segTree[idx].money;
    
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, t)+query(mid+1, r, idx<<1|1, t);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        
        if(v != -1) {
            edges[v].push_back(i);
        }
    }
    
    dfs();
    
    for(int i = 1; i < (1<<18); i++) segTree[i] = {0, 0};

    while(M--) {
        int q; cin >> q;
        
        if(q == 1) {
            int i, w; cin >> i >> w;
            update(1, N, 1, in[i], out[i], w);
        }
        else {
            int i; cin >> i;
            cout << query(1, N, 1, in[i]) << '\n';
        }
    }
    
    return 0;
}