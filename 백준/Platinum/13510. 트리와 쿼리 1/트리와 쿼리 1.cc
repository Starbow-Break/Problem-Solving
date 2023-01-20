#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX 100000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

struct edge {
    int f, w, num;
};

int N; 
int edgeNode[MAX]; //각 간선을 대변하는 정점
int weight[MAX+1]; //정점의 가중치
//각각 서브트리의 크기, 깊이, 부모 노드, 체인상의 top 노드
int sz[MAX+1] = {0, }, dep[MAX+1], parent[MAX+1], top[MAX+1];
int in[MAX+1], out[MAX+1]; //ETT에서의 in, out 값
vector<edge> edges[MAX+1]; //간선
vector<int> child[MAX+1]; //자식노드

struct maxSegTree {
    ll segTree[270000] = {0, };
    
    void update(int i, int j, int idx, int t, int v) {
        if(j < t || t < i) return;
        
        if(i == j) {
            segTree[idx] = v;
            return;
        }
        
        int mid = (i+j)>>1;
        update(i, mid, idx<<1, t, v); update(mid+1, j, (idx<<1)|1, t, v);
        segTree[idx] = max(segTree[idx<<1], segTree[(idx<<1)|1]);
    }
    
    int query(int i, int j, int idx, int l, int r) {
        if(j < l || r < i) return 0;
        
        if(l <= i && j <= r) return segTree[idx];
        
        int mid = (i+j)>>1;
        int L = query(i, mid, idx<<1, l, r);
        int R = query(mid+1, j, (idx<<1)|1, l, r);
        return max(L, R);
    }
    
    void build() {
        for(int i = 1; i <= N; i++) {
            update(1, N, 1, in[i], weight[i]);
        }
    }
} sgTr;

bool visited[MAX+1] = {false, };
//각 노드의 부모 노드, 자식 노드, 깊이 구하기
void dfs(int cur = 1, int depth = 0) {
    visited[cur] = true;
    dep[cur] = depth;
    for(auto &e: edges[cur]) {
        if(!visited[e.f]) {
            child[cur].push_back(e.f); parent[e.f] = cur;
            weight[e.f] = e.w; edgeNode[e.num] = e.f;
            dfs(e.f, depth+1);
        }
    }
}

//각 노드의 sz 구하기 및 heavy edge를 맨 앞으로 빼기
void dfs1(int cur = 1) {
    sz[cur] = 1;
    for(auto &next: child[cur]) {
        dfs1(next); sz[cur] += sz[next];
        if(sz[next] > sz[child[cur][0]])
            swap(sz[next], sz[child[cur][0]]);
    }
}

//in, out 및 top(각 노드가 속해 있는 체인의 top 노드) 구하기
int ord = 0;
void dfs2(int cur = 1) {
    ord++; in[cur] = ord;
    for(auto &next: child[cur]) {
        top[next] = ((next == child[cur][0]) ? top[cur] : next);
        dfs2(next);
    }
    
    out[cur] = ord;
}

//1번 쿼리
void update(int i, int c) {
    weight[edgeNode[i]] = c;
    sgTr.update(1, N, 1, in[edgeNode[i]], c);
}

//2번 쿼리
int query(int u, int v) {
    int ret = 0;
    
    while(top[u] != top[v]) {
        //cout << u << " " << v << '\n';
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        int cur = sgTr.query(1, N, 1, in[top[u]], in[u]);
        ret = max(ret, cur);
        u = parent[top[u]];
    }
    
    if(dep[u] < dep[v]) swap(u, v);
    
    //cout << u << " " << v << " " << ret << '\n';
    int cur = 0;
    if(parent[u] == v)
        cur = sgTr.query(1, N, 1, in[u], in[u]);
    else {
        if(u != v) cur = sgTr.query(1, N, 1, in[v]+1, in[u]);
    }
        
    ret = max(ret, cur);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i < N; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].push_back({v, w, i});
        edges[v].push_back({u, w, i});
    }
    
    parent[1] = -1; weight[1] = 0; top[1] = 1;
    dfs(); dfs1(); dfs2();
    
    sgTr.build();
    
    int M; cin >> M;
    while(M--) {
        int q, i, j; cin >> q >> i >> j;
        if(q == 1) update(i, j);
        else cout << query(i, j) << '\n';
    }
    
    /*for(int i = 1; i < N; i++) cout << edgeNode[i] << " ";
    cout << '\n';
    for(int i = 1; i <= N; i++) cout << weight[i] << " ";
    cout << '\n';
    for(int i = 1; i <= N; i++) cout << top[i] << " ";*/

    return 0;
}