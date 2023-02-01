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

int N; 
vector<int> edges[MAX+1];
int parent[MAX+1][18];
int depth[MAX+1] = {0, };

bool visited[MAX+1] = {false, };
void dfs(int cur = 1, int bef = -1) {
    visited[cur] = true; parent[cur][0] = bef;
    for(auto &next: edges[cur]) {
        if(!visited[next]) {
            depth[next] = depth[cur]+1;
            dfs(next, cur);
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

int getParent(int cur, int step) {
    int idx = 0;
    while(step > 0) {
        if(step%2) {
            cur = parent[cur][idx];
        }
        
        step /= 2; idx++;
    }
    
    return cur;
}

int getLCA(int v1, int v2) {
    int d = depth[v1]-depth[v2];
    
    if(d > 0) v1 = getParent(v1, d);
    else v2 = getParent(v2, -d);

    for(int i = 17; i >= -1; i--) {
        bool check;
        
        if(i >= 0) check = parent[v1][i] != parent[v2][i];
        else check = v1 != v2;
        
        int idx = i; if(idx < 0) idx = 0;
        if(check) { v1 = parent[v1][idx]; v2 = parent[v2][idx]; }
    }
    
    return v1;
}

int distance(int v1, int v2) {
    int lca = getLCA(v1, v2);
    return (depth[v1]-depth[lca])+(depth[v2]-depth[lca]);
}

int getMid(int v1, int v2) {
    int lca = getLCA(v1, v2);
    int d = (depth[v1]-depth[lca])+(depth[v2]-depth[lca]);
    
    if(d%2) return -1;
    else {
        if(depth[v1] > depth[v2]) return getParent(v1, d/2);
        else return getParent(v2, d/2);
    }
}

int solve(int a, int b, int c) {
    int mAB = getMid(a, b);
    int mBC = getMid(b, c);
    int mCA = getMid(c, a);
    
    if(mAB != -1) {
        int d = max(abs(depth[mAB]-depth[a]), abs(depth[mAB]-depth[b]));
        if(d == distance(mAB, c)) return mAB;
    }
    if(mBC != -1) {
        int d = max(abs(depth[mBC]-depth[b]), abs(depth[mBC]-depth[c]));
        if(d == distance(mBC, a)) return mBC;
    }
    if(mCA != -1) {
        int d = max(abs(depth[mCA]-depth[c]), abs(depth[mCA]-depth[a]));
        if(d == distance(mCA, b)) return mAB;
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b); edges[b].push_back(a);
    }
    
    buildTable();
    
    int Q; cin >> Q;
    while(Q--) {
        int a, b, c; cin >> a >> b >> c;
        cout << solve(a, b, c) << '\n';
    }

    return 0;
}