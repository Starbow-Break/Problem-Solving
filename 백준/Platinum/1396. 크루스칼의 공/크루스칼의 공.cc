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

struct edge {
    int a, b, c;
    
    bool operator<(edge &e) {
        return c < e.c;
    }
};

vector<edge> edges;
vector<int> tree[2*MAX_N];
int parent[2*MAX_N];
int p[2*MAX_N][18] = {0, };
int w[2*MAX_N] = {0, }, num[2*MAX_N] = {0, };
int dep[MAX_N+1] = {0, };

int findRoot(int v) {
    if(v == parent[v]) return v;
    
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

bool sameSet(int v1, int v2) {
    return findRoot(v1) == findRoot(v2);
}

void unionSet(int v1, int v2, int root) {
    int r1 = findRoot(v1); int r2 = findRoot(v2);
    
    parent[r1] = root; parent[r2] = root;
}

void makeTree(int N) {
    int cnt = 0;
    for(auto &e: edges) {
        if(cnt == N-1) break;
        
        int r1 = findRoot(e.a); int r2 = findRoot(e.b);
        if(r1 == r2) continue;
        
        cnt++; int root = N+cnt;
        tree[r1].push_back(root); tree[r2].push_back(root);
        tree[root].push_back(r1); tree[root].push_back(r2);
        w[root] = max(w[r1], w[r2]); w[root] = max(w[root], e.c);
        num[root] = num[r1]+num[r2];
            
        unionSet(r1, r2, N+cnt);
    }
}

bool visited[2*MAX_N] = {false, };
void dfs(int cur) {
    visited[cur] = true;
    for(auto &next: tree[cur]) {
        if(!visited[next]) {
            dep[next] = dep[cur]+1;
            p[next][0] = cur;
            dfs(next);
        }
    }
}

void makeTable(int N) {
    for(int r = 2*N-1; r >= 1; r--) { if(!visited[r]) dfs(r); }
    
    for(int i = 1; i <= 17; i++) {
        for(int v = 1; v < 2*N; v++) {
            p[v][i] = p[p[v][i-1]][i-1];
        }
    }
}

int getParent(int v, int step) {
    int idx = 0;
    while(step != 0) {
        if(step%2) v = p[v][idx];
        
        step /= 2; idx++;
    }
    
    return v;
}

int getLCA(int x, int y) {
    int d = dep[x]-dep[y];
    
    if(d > 0) x = getParent(x, d);
    else y = getParent(y, -d);
    
    for(int i = 17; i >= -1; i--) {
        bool check;
        
        if(i >= 0) check = p[x][i] != p[y][i];
        else check = x != y;
        
        if(check) {
            x = p[x][(i < 0 ? 0 : i)]; y = p[y][(i < 0 ? 0 : i)];
        }
    }
    
    return x;
}

pii solve(int x, int y) {
    if(!sameSet(x, y)) return {-1, -1};
    
    int lca = getLCA(x, y);
    
    return {w[lca], num[lca]};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    for(int i = 1; i < 2*MAX_N; i++) { parent[i] = i; }
    for(int i = 1; i <= n; i++) { w[i] = 0; num[i] = 1; }
    
    for(int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end());
    
    makeTree(n);
    makeTable(n);
    
    int Q; cin >> Q;
    while(Q--) {
        int x, y; cin >> x >> y;
        pii ans = solve(x, y);
        
        if(ans.first == -1) cout << -1;
        else cout << ans.first << " " << ans.second;
        
        cout <<'\n';
    }

    return 0;
}