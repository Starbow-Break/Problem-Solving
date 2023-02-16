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

const ll INF = 1'000'000'000'000'000'000;

int N, K;
int parent[18][MAX_N+1];
ll len[18][MAX_N+1]; int dep[MAX_N+1] = {0, };

vector<pii> edges[MAX_N+1];

bool visited[MAX_N+1] = {false, };
void dfs(int cur = 1) {
    visited[cur] = true;
    
    for(auto &next: edges[cur]) {
        if(!visited[next.first]) {
            parent[0][next.first] = cur; dep[next.first] = dep[cur]+1;
            len[0][next.first] = next.second;
            dfs(next.first);
        }
    }
}

void buildTable() {
    parent[0][1] = -1; len[0][1] = INF;
    dfs();
    
    for(int i = 1; i <= 17; i++) {
        for(int v = 1; v <= N; v++) {
            if(parent[i-1][v] == -1) parent[i][v] = -1;
            else parent[i][v] = parent[i-1][parent[i-1][v]];
            
            len[i][v] = parent[i][v] == -1 ? INF : len[i-1][v]+len[i-1][parent[i-1][v]];
        }
    }
}

ll l[2]; //v1~lca, v2~lca

int getParent(int v, int step, int idx) {
    int i = 0;
    while(step > 0) {
        if(step%2) {
            l[idx] += len[i][v]; v = parent[i][v];
        }
        
        step /= 2; i++;
    }
    
    return v;
}

int getMiddle(int v1, int v2) {
    int _v1 = v1, _v2 = v2;
    l[0] = 0; l[1] = 0;
    
    int d = dep[v1]-dep[v2];
    if(d > 0) v1 = getParent(v1, d, 0);
    else v2 = getParent(v2, -d, 1);
    
    for(int i = 17; i >= -1; i--) {
        bool c;
        if(i >= 0) c = parent[i][v1] != parent[i][v2];
        else c = v1 != v2;
        
        int idx = i < 0 ? 0 : i;
        if(c) {
            l[0] += len[idx][v1]; l[1] += len[idx][v2];
            v1 = parent[idx][v1]; v2 = parent[idx][v2];
        }
    }
    
    if((l[0]+l[1])%2) return -1;
    
    ll t = (l[0]+l[1])/2;
    
    if(l[0] < l[1]) swap(_v1, _v2);
    while(t > 0) {
        bool flag = false;
        for(int i = 17; i >= 0; i--) {
            if(t >= len[i][_v1]) {
                t -= len[i][_v1]; _v1 = parent[i][_v1];
                flag = true; break;
            }
        }
        
        if(!flag) return -1;
    }
    
    return _v1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for(int i = 1; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    
    buildTable();
    
    while(K--) {
        int a, b; cin >> a >> b;
        cout << getMiddle(a, b) << '\n';
    }

    return 0;
}