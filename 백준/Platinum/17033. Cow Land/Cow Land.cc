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
#define MAX 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, Q;
int sz[MAX+1], dep[MAX+1], parent[MAX+1], top[MAX+1], in[MAX+1], invIn[MAX+1], out[MAX+1];
vector<int> temp[MAX+1]; vector<int> edges[MAX+1];
int arr[MAX+1];

struct xorSegTree {
    int sgTree[270000];
    
    void init(int i, int j, int idx) {
        if(i == j) {
            sgTree[idx] = arr[invIn[i]];
            return;
        }
        
        int mid = (i+j)>>1;
        init(i, mid, idx<<1); init(mid+1, j, (idx<<1)|1);
        sgTree[idx] = sgTree[idx<<1]^sgTree[(idx<<1)|1];
    }
    
    void update(int i, int j, int idx, int t, int v) {
        if(j < t || t < i) return;
        
        if(i == j) {
            sgTree[idx] = v;
            return;
        }
        
        int mid = (i+j)>>1;
        update(i, mid, idx<<1, t, v); update(mid+1, j, (idx<<1)|1, t, v);
        sgTree[idx] = sgTree[idx<<1]^sgTree[(idx<<1)|1];
    }
    
    int query(int i, int j, int idx, int l, int r) {
        if(j < l || r < i) return 0;
        
        if(l <= i && j <= r) return sgTree[idx];
        
        int mid = (i+j)>>1;
        return query(i, mid, idx<<1, l, r)^query(mid+1, j, (idx<<1)|1, l, r);
    }
    
} segTree;

bool visited[MAX+1] = {false, };
void dfs(int cur = 1) {
    visited[cur] = true;
    for(auto &next: temp[cur]) {
        if(!visited[next]) {
            parent[next] = cur;
            edges[cur].push_back(next);
            dfs(next);
        }
    }
}

void dfs1(int cur = 1, int depth = 0) {
    sz[cur] = 1; dep[cur] = depth;
    for(auto &next: edges[cur]) {
        dfs1(next, depth+1); sz[cur] += sz[next];
        if(sz[next] > sz[edges[cur][0]]) swap(edges[cur][0], next);
    }
}

int ord = 0;
void dfs2(int cur = 1) {
    ord++; in[cur] = ord; invIn[ord] = cur;
    for(auto &next: edges[cur]) {
        top[next] = (next == edges[cur][0] ? top[cur] : next);
        dfs2(next);
    }
    out[cur] = ord;
}

int query(int i, int j) {
    int ret = 0;
    while(top[i]^top[j]) {
        if(dep[top[i]] < dep[top[j]]) swap(i, j);
        
        ret ^= segTree.query(1, N, 1, in[top[i]], in[i]);
        i = parent[top[i]];
    }
    
    if(dep[i] > dep[j]) swap(i, j);
    ret ^= segTree.query(1, N, 1, in[i], in[j]);
    return ret;
}

void update(int i, int v) {
    segTree.update(1, N, 1, in[i], v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) { cin >> arr[i]; }
    
    parent[1] = -1;
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        temp[a].push_back(b); temp[b].push_back(a);
    }
    
    dfs(); dfs1(); dfs2();
    
    segTree.init(1, N, 1);
    while(Q--) {
        int q, i, j; cin >> q >> i >> j;
        
        if(q == 1) update(i, j);
        else cout << query(i, j) << '\n';
    }

    return 0;
}