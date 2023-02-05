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

const int INF = 1'000'000'000;

int N; 
int weight[MAX_N+1];
vector<int> temp[MAX_N+1], graph[MAX_N+1];
int in[MAX_N+1], out[MAX_N+1], dep[MAX_N+1] = {0, }, sz[MAX_N+1];
int top[MAX_N+1], parent[MAX_N+1], invIn[MAX_N+1];

struct minSegTree {
    int segTree[270000];
    
    void init() {
        fill(segTree, segTree+270000, INF);
    }
    
    void update(int i, int j, int idx, int t) {
        if(j < t || t < i) return;
        
        if(i == j) {
            segTree[idx] = (segTree[idx] == INF ? t : INF); return;
        }
        
        int mid = (i+j)>>1;
        update(i, mid, idx<<1, t); update(mid+1, j, (idx<<1)|1, t);
        segTree[idx] = min(segTree[idx<<1], segTree[(idx<<1)|1]);
    }
    
    int query(int i, int j, int idx, int u, int v) {
        if(j < u || v < i) return INF;
        
        if(u <= i && j <= v) {
            return segTree[idx];
        }
        
        int mid = (i+j)>>1;
        int L = query(i, mid, idx<<1, u, v);
        int R = query(mid+1, j, (idx<<1)|1, u, v);
        return min(L, R);
    }
} segTree;

bool visited[MAX_N+1] = {false, };
void dfs(int cur = 1) {
    visited[cur] = true;
    
    for(auto &next: temp[cur]) {
        if(!visited[next]) {
            parent[next] = cur;
            graph[cur].push_back(next);
            dfs(next);
        }
    }
}

void dfs1(int cur = 1) {
    sz[cur] = 1;
    
    for(auto &next: graph[cur]) {
        dep[next] = dep[cur]+1;
        dfs1(next);
        if(sz[next] > sz[graph[cur][0]]) swap(graph[cur][0], next);
        sz[cur] += sz[next];
    }
}

int ord = 0;
void dfs2(int cur = 1) {
    ord++;
    in[cur] = ord; invIn[ord] = cur; 
    for(auto &next: graph[cur]) {
        top[next] = (next == graph[cur][0] ? top[cur] : next);
        dfs2(next);
    }
    
    out[cur] = ord;
}

void init() {
    segTree.init();
}

void update(int v) {
    segTree.update(1, N, 1, in[v]);
}

int query(int v) {
    int ret = INF; int u = 1;
    
    while(top[u] != top[v]) {
        if(dep[u] < dep[v]) swap(u, v);
        ret = min(ret, segTree.query(1, N, 1, in[top[u]], in[u]));
        u = parent[top[u]];
    }
    
    if(dep[u] > dep[v]) swap(u, v);
    ret = min(ret, segTree.query(1, N, 1, in[u], in[v]));
    return (ret == INF ? -1 : invIn[ret]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        temp[a].push_back(b); temp[b].push_back(a);
    }
    
    parent[1] = -1; top[1] = 1;
    dfs(); dfs1(); dfs2();
    
    init();
    
    int Q; cin >> Q;
    while(Q--) {
        int q, v; cin >> q >> v;
        if(q == 1) {
            update(v);
        }
        else {
            cout << query(v) << '\n';
        }
    }

    return 0;
}