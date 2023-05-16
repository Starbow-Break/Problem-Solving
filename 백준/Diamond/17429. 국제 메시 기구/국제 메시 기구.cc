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

const ull mod = 1LL << 32;

struct node {
    ull value, addLazy, mulLazy;
};

int n, q;
node segTree[1 << 20];
int w[MAX_N+1], invIn[MAX_N+1];
int sz[MAX_N+1] = {0, }, top[MAX_N+1], parent[MAX_N+1], in[MAX_N+1], out[MAX_N+1], dep[MAX_N+1] = {0, };
vector<int> temp[MAX_N+1], edges[MAX_N+1];
bool visited[MAX_N+1] = {false, }; 

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
    ull addLazy = segTree[idx].addLazy;
    ull mulLazy = segTree[idx].mulLazy;
    
    if(l != r) {
        segTree[idx<<1].addLazy *= mulLazy;
        segTree[idx<<1].addLazy %= mod;
        segTree[idx<<1].mulLazy *= mulLazy;
        segTree[idx<<1].mulLazy %= mod;
        segTree[idx<<1].addLazy += addLazy;
        segTree[idx<<1].addLazy %= mod;
        
        segTree[idx<<1|1].addLazy *= mulLazy;
        segTree[idx<<1|1].addLazy %= mod;
        segTree[idx<<1|1].mulLazy *= mulLazy;
        segTree[idx<<1|1].mulLazy %= mod;
        segTree[idx<<1|1].addLazy += addLazy;
        segTree[idx<<1|1].addLazy %= mod;
    }
    
    segTree[idx].value *= mulLazy;
    segTree[idx].value %= mod;
    segTree[idx].value += addLazy*(r-l+1)%mod;
    segTree[idx].value %= mod;
    
    segTree[idx].addLazy = 0;
    segTree[idx].mulLazy = 1;
}

node merge(node a, node b) {
    node ret;
    
    ret.value = (a.value+b.value)%mod;
    ret.addLazy = 0; ret.mulLazy = 1;
    
    return ret;
}

void initTree() {
    for(int i = 1; i < 1<<20; i++) segTree[i] = {0, 0, 1};
}

void updateAdd(int l, int r, int idx, int i, int j, int v) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].addLazy += v;
        segTree[idx].addLazy %= mod;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)>>1;
    updateAdd(l, mid, idx<<1, i, j, v); updateAdd(mid+1, r, idx<<1|1, i, j, v);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

void updateMul(int l, int r, int idx, int i, int j, int v) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].mulLazy *= v;
        segTree[idx].mulLazy %= mod;
        segTree[idx].addLazy *= v;
        segTree[idx].addLazy %= mod;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)>>1;
    updateMul(l, mid, idx<<1, i, j, v); updateMul(mid+1, r, idx<<1|1, i, j, v);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

ull query(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx].value;
    
    int mid = (l+r)>>1;
    return (query(l, mid, idx<<1, i, j)+query(mid+1, r, idx<<1|1, i, j))%mod;
}

void routeAdd(int a, int b, int v) {
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        updateAdd(1, n, 1, in[top[a]], in[a], v);
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    updateAdd(1, n, 1, in[a], in[b], v);
}

void subTreeAdd(int a, int v) {
    updateAdd(1, n, 1, in[a], out[a], v);
}

void routeMul(int a, int b, int v) {
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        updateMul(1, n, 1, in[top[a]], in[a], v);
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    updateMul(1, n, 1, in[a], in[b], v);
}

void subTreeMul(int a, int v) {
    updateMul(1, n, 1, in[a], out[a], v);
}

ull routeQuery(int a, int b) {
    ull ret = 0;
    
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        ret += query(1, n, 1, in[top[a]], in[a]);
        ret %= mod;
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    ret += query(1, n, 1, in[a], in[b]);
    ret %= mod;
    
    return ret;
}

ull subTreeQuery(int a) {
    return query(1, n, 1, in[a], out[a]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> q;
    
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        temp[a].push_back(b); temp[b].push_back(a);
    }
    
    top[1] = -1;
    dfs(); dfs1(); dfs2();
    
    initTree();
    
    while(q--) {
        int k, x, y, v; cin >> k;
        switch(k) {
            case 1:
                cin >> x >> v;
                subTreeAdd(x, v);
                break;
            case 2: 
                cin >> x >> y >> v;
                routeAdd(x, y, v);
                break;
            case 3: 
                cin >> x >> v;
                subTreeMul(x, v);
                break;
            case 4: 
                cin >> x >> y >> v;
                routeMul(x, y, v);
                break;
            case 5: 
                cin >> x;
                cout << subTreeQuery(x) << '\n';
                break;
            case 6: 
                cin >> x >> y;
                cout << routeQuery(x, y) << '\n';
                break;
        }
    }

    return 0;
}