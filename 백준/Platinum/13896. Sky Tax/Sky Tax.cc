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

int N, Q, R; 
int sz[MAX+1], dep[MAX+1];
vector<int> edges[MAX+1];
int root; int parent[MAX+1][18];

void clear() {
    for(int i = 1; i <= MAX; i++) {
        sz[i] = 0; dep[i] = 0; edges[i].clear();
    }
}

void dfs(int cur = 1, int bef = -1) {
    sz[cur] = 1; parent[cur][0] = bef;
    for(auto &next: edges[cur]) {
        if(sz[next] == 0) {
            dep[next] = dep[cur]+1;
            dfs(next, cur); sz[cur] += sz[next];
        }
    }
}

void buildTable() {
    dfs();
    for(int i = 1; i <= 17; i++) {
        for(int v = 1; v <= N; v++) {
            if(parent[v][i-1] == -1) parent[v][i] = -1;
            else parent[v][i] = parent[parent[v][i-1]][i-1];
        }
    }
}

int getParent(int v, int step) {
    int idx = 0;
    while(step > 0) {
        if(step%2) v = parent[v][idx];
        
        step /= 2; idx++;
    }
    
    return v;
}

int getLCA(int v1, int v2) {
    int d = dep[v1]-dep[v2];
    
    if(d > 0) v1 = getParent(v1, d);
    else v2 = getParent(v2, -d);
    
    for(int i = 17; i >= -1; i--) {
        bool check;
        if(i == -1) check = v1 != v2;
        else check = parent[v1][i] != parent[v2][i];
        
        if(check) {
            v1 = parent[v1][(i < 0 ? 0 : i)];
            v2 = parent[v2][(i < 0 ? 0 : i)];
        }
    }
    
    return v1;
}

int query(int u) {
    if(root == u) return N;
    
    int lca = getLCA(root, u);
    
    if(lca == u) {
        int uu = getParent(root, dep[root]-dep[u]-1);
        return N-sz[uu];
    }
    else return sz[u];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":" << '\n';
        clear();
        
        cin >> N >> Q >> R;
        root = R;
        for(int i = 1; i < N; i++) {
            int a, b; cin >> a >> b;
            edges[a].push_back(b); edges[b].push_back(a);
        }
        
        buildTable();
        
        while(Q--) {
            int s, u; cin >> s >> u;
            if(s) {
                cout << query(u) << '\n';
            }
            else root = u;
        }
    }

    return 0;
}