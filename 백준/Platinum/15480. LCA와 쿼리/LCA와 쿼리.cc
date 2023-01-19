#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M;
vector<int> edge[100001];
int arr[100001][18] = {0, };
int depth[100001];

void dfs(int cur = 1, int bef = -1, int dep = 0) {
    arr[cur][0] = bef; depth[cur] = dep;
    
    for(auto &next: edge[cur]) {
        if(!arr[next][0]) {
            dfs(next, cur, dep+1);
        }
    }
}

void buildTable(int N) {
    dfs();
    for(int j = 1; j < 18; j++) {
        for(int i = 1; i <= N; i++) {
            if(arr[i][j-1] == -1) arr[i][j] = -1;
            else arr[i][j] = arr[arr[i][j-1]][j-1];
        }
    }
}

int lcaWithRoot1(int u, int v) {
    int du = depth[u]; int dv = depth[v];
    if(du < dv) {
        int d = dv-du;
        
        int idx = 0;
        while(d > 0) {
            if(d%2) v = arr[v][idx];
            d /= 2; idx++;
        }
    }
    if(du > dv) {
        int d = du-dv;
        
        int idx = 0;
        while(d > 0) {
            if(d%2) u = arr[u][idx];
            d /= 2; idx++;
        }
    }
    
    for(int idx = 17; idx >= 0; idx--) {
        if(arr[u][idx] != arr[v][idx]) {
            u = arr[u][idx]; v = arr[v][idx];
        }
    }
        
    if(u != v) u = arr[u][0]; v = arr[v][0];
    
    return u;
}

int lca(int r, int u, int v) {
    int l = lcaWithRoot1(u, v);
    if(r == 1) return l;
    
    if(l == u) {
        int ru = lcaWithRoot1(r, u);
        int rv = lcaWithRoot1(r, v);
        
        if(depth[ru] < depth[u]) return u;
        if(depth[rv] == depth[v]) return v;
        else return rv;
        
    }
    else if(l == v) {
        int ru = lcaWithRoot1(r, u);
        int rv = lcaWithRoot1(r, v);
        
        if(depth[rv] < depth[v]) return v;
        if(depth[ru] == depth[u]) return u;
        else return ru;
    }
    else {
        int ru = lcaWithRoot1(r, u);
        int rv = lcaWithRoot1(r, v);
        
        if(ru == u) return u;
        if(rv == v) return v;
        if(ru != l && rv == l) return ru;
        if(rv != l && ru == l) return rv;
        else return l;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v); edge[v].push_back(u);
    }
    
    buildTable(N);
    
    cin >> M;
    while(M--) {
        int r, u, v; cin >> r >> u >> v;
        cout << lca(r, u, v) << '\n';
    }
    
    return 0;
}