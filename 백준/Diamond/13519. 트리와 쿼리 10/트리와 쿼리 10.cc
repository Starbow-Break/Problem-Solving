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

const int INF = 2'000'000'000;

struct node {
    int left, right, maxV, sum, lazy;
};

node segTree[1 << 18];
int w[MAX_N+1], invIn[MAX_N+1];
int sz[MAX_N+1] = {0, }, top[MAX_N+1], parent[MAX_N+1], in[MAX_N+1], out[MAX_N+1], dep[MAX_N+1] = {0, };
vector<int> temp[MAX_N+1], edges[MAX_N+1];
bool visited[MAX_N+1] = {false, }; 

void dfs(int cur = 1) {
    visited[cur] = true;
    sz[cur]++;
    
    for(auto &next: temp[cur]) {
        if(!visited[next]) {
            edges[cur].push_back(next);
            parent[next] = cur; dep[next] = dep[cur]+1;
            dfs(next);
            sz[cur] += sz[next];
        }
    }
}

void dfs1(int cur = 1) {
    for(auto &next: edges[cur]) {
        if(sz[edges[cur][0]] < sz[next]) swap(edges[cur][0], next);
        dfs1(next);
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
    
    if(lazy == -INF) return;
    
    if(l != r) {
        segTree[idx<<1].lazy = lazy;
        segTree[idx<<1|1].lazy = lazy;
    }
    
    int sum = (r-l+1)*lazy;
    segTree[idx] = {max(0, sum), max(0, sum), max(0, sum), sum, -INF};
}

node merge(node a, node b) {
    node ret;
    ret.sum = a.sum+b.sum;
    ret.lazy = -INF;
    ret.left = max(a.left, a.sum+b.left);
    ret.right = max(b.right, b.sum+a.right);
    ret.maxV = max(ret.left, ret.right);
    ret.maxV = max(ret.maxV, a.maxV); ret.maxV = max(ret.maxV, b.maxV);
    ret.maxV = max(ret.maxV, a.right+b.left);
    
    return ret;
}

node merge1(node a, node b) {
    node ret;
    ret.sum = a.sum+b.sum;
    ret.lazy = -INF;
    ret.left = max(a.right, a.sum+b.left);
    ret.right = max(b.right, b.sum+a.left);
    ret.maxV = max(ret.left, ret.right);
    ret.maxV = max(ret.maxV, a.maxV); ret.maxV = max(ret.maxV, b.maxV);
    ret.maxV = max(ret.maxV, a.left+b.left);
    
    return ret;
}

void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = {max(0, w[invIn[l]]), max(0, w[invIn[l]]), max(0, w[invIn[l]]), w[invIn[l]], -INF};
        return;
    }
    
    int mid = (l+r)/2;
    initTree(l, mid, idx<<1); initTree(mid+1, r, idx<<1|1);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

void segUpdate(int l, int r, int idx, int i, int j, int v) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].lazy = v;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)/2;
    segUpdate(l, mid, idx<<1, i, j, v); segUpdate(mid+1, r, idx<<1|1, i, j, v);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

node segQuery(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return {0, 0, 0, 0, -INF};
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = (l+r)/2;
    return merge(segQuery(l, mid, idx<<1, i, j), segQuery(mid+1, r, idx<<1|1, i, j));
}

void update(int n, int a, int b, int v) {
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        segUpdate(1, n, 1, in[top[a]], in[a], v);
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    segUpdate(1, n, 1, in[a], in[b], v);
}

int query(int n, int a, int b) {
    node retA = {0, 0, 0, 0, -INF};
    node retB = {0, 0, 0, 0, -INF};
    
    while(top[a] ^ top[b]) {
        if(dep[top[a]] > dep[top[b]]) {
            node curNode = segQuery(1, n, 1, in[top[a]], in[a]);
            retA = merge(curNode, retA);
            a = parent[top[a]];
        }
        else {
            node curNode = segQuery(1, n, 1, in[top[b]], in[b]);
            retB = merge(curNode, retB);
            b = parent[top[b]];
        }
    }
    
    node curNode;
    if(dep[a] < dep[b]) {
        curNode = segQuery(1, n, 1, in[a], in[b]);
        retB = merge(curNode, retB);
    }
    else {
        curNode = segQuery(1, n, 1, in[b], in[a]);
        retA = merge(curNode, retA);
    }
    
    return merge1(retA, retB).maxV;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        temp[a].push_back(b); temp[b].push_back(a);
    }
    
    top[1] = -1;
    dfs(); dfs1(); dfs2();
    
    initTree(1, n, 1);
    
    int m; cin >> m;
    while(m--) {
        int q, u, v, w; cin >> q;
        if(q == 1) {
            cin >> u >> v;
            cout << query(n, u, v) << '\n';
        }
        else {
            cin >> u >> v >> w;
            update(n, u, v, w);
        }
    }

    return 0;
}