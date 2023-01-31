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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, Q; 

struct andSegTree {
    bool sgTree[550000];
    
    void init(int i, int j, int idx) {
        if(i == j) {
            sgTree[idx] = true;
            return;
        }
        
        int mid = (i+j)>>1;
        init(i, mid, idx<<1); init(mid+1, j, (idx<<1)|1);
        sgTree[idx] = sgTree[idx<<1] & sgTree[(idx<<1)|1];
    }
    
    void update(int i, int j, int idx, int t) {
        if(j < t || t < i) return;
        
        if(i == j) {
            sgTree[idx] = false;
            return;
        }
        
        int mid = (i+j)>>1;
        update(i, mid, idx<<1, t); update(mid+1, j, (idx<<1)|1, t);
        sgTree[idx] = sgTree[idx<<1] & sgTree[(idx<<1)|1];
    }
    
    bool query(int i, int j, int idx, int l, int r) {
        if(j < l || r < i) return true;
        
        if(l <= i && j <= r) return sgTree[idx];
        
        int mid = (i+j)>>1;
        return query(i, mid, idx<<1, l, r) & query(mid+1, j, (idx<<1)|1, l, r);
    }
    
} segTree;

int sz[200001], dep[200001], parent[200001], top[200001], in[200001], out[200001];
vector<int> edges[200001];

void dfs1(int cur = 1, int depth = 0) {
    sz[cur] = 1; dep[cur] = depth;
    for(auto &next: edges[cur]) {
        dfs1(next, depth+1); sz[cur] += sz[next];
        if(sz[next] > sz[edges[cur][0]]) swap(edges[cur][0], next);
    }
}

int ord = 0;
void dfs2(int cur = 1) {
    ord++; in[cur] = ord;
    for(auto &next: edges[cur]) {
        top[next] = (next == edges[cur][0] ? top[cur] : next);
        dfs2(next);
    }
    out[cur] = ord;
}

bool hasRoute(int b, int c) {
    bool ret = true;
    while(top[b]^top[c]) {
        if(dep[top[b]] < dep[top[c]]) swap(b, c);
        
        ret &= segTree.query(1, N, 1, in[top[b]], in[b]);
        b = parent[top[b]];
    }
    
    if(dep[b] > dep[c]) swap(b, c);
    if(b != c) ret &= segTree.query(1, N, 1, in[b]+1, in[c]);
    return ret;
}

void deleteEdge(int v) {
    if(v == 1) return;
    
    segTree.update(1, N, 1, in[v]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q;
    parent[1] = -1;
    for(int i = 2; i <= N; i++) {
        int p; cin >> p; 
        parent[i] = p; edges[p].push_back(i);
    }
    
    dfs1(); dfs2();
    
    segTree.init(1, N, 1);
    while(Q--) {
        int b, c, d; cin >> b >> c >> d;
        
        bool check = hasRoute(b, c);
        cout << (check ? "YES" : "NO") << '\n';
        if(d) {
            if(check) deleteEdge(b);
            else deleteEdge(c);
        }
    }

    return 0;
}