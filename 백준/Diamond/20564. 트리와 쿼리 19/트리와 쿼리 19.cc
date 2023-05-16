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
#define MAX_N 500'000

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct node {
    ll numWhite, lazy;
};

int n, q; ll ans = 0;
node segTree[1 << 20];
int w[MAX_N+1], invIn[MAX_N+1];
int sz[MAX_N+1] = {0, }, top[MAX_N+1], parent[MAX_N+1], in[MAX_N+1], out[MAX_N+1], dep[MAX_N+1] = {0, };
vector<int> temp[MAX_N+1], edges[MAX_N+1];
bool visited[MAX_N+1] = {false, };
bool isWhite[MAX_N+1] = {false, }; int cntWhite = 0;

void dfs(int cur = 1) {
    visited[cur] = true;
    for(auto &next: temp[cur]) {
        if(!visited[next]) {
            edges[cur].push_back(next);
            parent[next] = cur; dep[next] = dep[cur]+1;
            dfs(next);
        }
    }
}

void dfs1(int cur = 1) {
    sz[cur] = 1;
    for(auto &next: edges[cur]) {
        dfs1(next); sz[cur] += sz[next];
        if(sz[edges[cur][0]] < sz[next]) swap(edges[cur][0], next);
    }
}

int ord = 0;
void dfs2(int cur = 1) {
    in[cur] = ++ord; invIn[ord] = cur;
    
    for(auto &next: edges[cur]) {
        top[next] = (next == edges[cur][0] ? top[cur] : next);
        dfs2(next);
    }
    
    out[cur] = ord;
}

void propagate(int l, int r, int idx) {
    int lazy = segTree[idx].lazy;
    
    if(l != r) {
        segTree[idx<<1].lazy += lazy;
        segTree[idx<<1|1].lazy += lazy;
    }
    
    segTree[idx].numWhite += 1LL*(r-l+1)*lazy;
    segTree[idx].lazy = 0;
}

node merge(node a, node b) {
    node ret;
    
    ret.numWhite = a.numWhite+b.numWhite;
    ret.lazy = 0;
    
    return ret;
}

void initTree() {
    for(int i = 1; i < 1<<20; i++) segTree[i] = {0, 0};
}

void segUpdate(int l, int r, int idx, int i, int j, int v) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].lazy += v;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)>>1;
    segUpdate(l, mid, idx<<1, i, j, v); segUpdate(mid+1, r, idx<<1|1, i, j, v);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

ll segQuery(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx].numWhite;
    
    int mid = (l+r)>>1;
    return segQuery(l, mid, idx<<1, i, j)+segQuery(mid+1, r, idx<<1|1, i, j);
}

void update(int a, int b, int v) {
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        segUpdate(1, n, 1, in[top[a]], in[a], v);
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    segUpdate(1, n, 1, in[a], in[b], v);
}

ll query(int a, int b) {
    ll ret = 0;
    
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        ret += segQuery(1, n, 1, in[top[a]], in[a]);
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    ret += segQuery(1, n, 1, in[a], in[b]);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) cin >> isWhite[i];
    
    for(int i = 2; i <= n; i++) {
        int v; cin >> v;
        temp[i].push_back(v); temp[v].push_back(i);
    }
    
    top[1] = -1;
    dfs(); dfs1(); dfs2();
    
    for(int i = 1; i <= n; i++) {
        if(isWhite[i]) {
            ans += query(1, i)-cntWhite;
            update(1, i, 1);
        }
        
        cntWhite += isWhite[i];
    }
    
    cout << ans << '\n';
    
    while(q--) {
        int v; cin >> v;
        if(isWhite[v]) {
            update(1, v, -1); cntWhite--;
            ans -= query(1, v)-cntWhite;
            cout << ans << '\n';
        }
        else {
            ans += query(1, v)-cntWhite;
            cout << ans << '\n';
            update(1, v, 1); cntWhite++;
        }
        
        isWhite[v] = !isWhite[v];
    }

    return 0;
}