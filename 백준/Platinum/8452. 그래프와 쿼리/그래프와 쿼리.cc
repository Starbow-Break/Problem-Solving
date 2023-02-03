#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX_N 1'000
#define MAX_M 100'000
#define MAX_Q 200'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

struct edge {
    int f, num;
};

struct query {
    char t; int p;
};

const int INF = 100'000'000;

int n, m, q; 
int shortest[MAX_N+1]; //shortest[a][b] = a에서 b까지의 최단거리

vector<edge> graph[MAX_N+1];
vector<query> queries;
vector<pii> edges(MAX_M+1);
bool isUsed[MAX_M+1];
int ans[MAX_Q];

bool visited[MAX_N+1]; queue<pii> que;
void bfs(int cur) {
    fill(visited+1, visited+n+1, false);

    que.push({cur, 0}); visited[cur] = true;
    while(!que.empty()) {
        int v = que.front().first; int d = que.front().second;
        que.pop();
        
        for(auto &next: graph[v]) {
            int w = next.f; int num = next.num;
            if(!visited[w] && isUsed[num]) {
                if(shortest[w] > shortest[cur]+d+1) {
                    shortest[w] = shortest[cur]+d+1;
                    que.push({w, d+1});
                    visited[w] = true;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> q;
    fill(isUsed+1, isUsed+m+1, true);
    
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        edges[i] = {a, b};
        graph[a].push_back({b, i});
    }
    
    for(int i = 0; i < q; i++) {
        char t; int p; cin >> t >> p;
        queries.push_back({t, p});
        
        if(t == 'U') isUsed[p] = false;
    }
    
    shortest[1] = 0;
    fill(shortest+2, shortest+n+1, INF);
    bfs(1);
    
    for(int i = q-1; i >= 0; i--) {
        if(queries[i].t == 'E') {
            int _ans = (shortest[queries[i].p] != INF
                ? shortest[queries[i].p] : -1);
            ans[i] = _ans;
        }
        else {
            int p = queries[i].p; isUsed[p] = true;
            int a = edges[p].first; int b = edges[p].second;
            if(shortest[a] != INF) bfs(a);
            ans[i] = -2;
        }
    }
    
    for(int i = 0; i < q; i++) {
        if(ans[i] != -2) cout << ans[i] << '\n';
    }

    return 0;
}