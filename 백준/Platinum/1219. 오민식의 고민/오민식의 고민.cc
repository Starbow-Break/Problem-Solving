#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

const ll INF = 1e18;

struct edge {
    int v1, v2, w;
};

vector<edge> edges;
int benefit[50];

vector<pii> adj_list[50];

bool bfs(int start, int target) {
    bool visited[50] = {false, };
    queue<int> q; q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == target) return true;
        for(auto &[next, w]: adj_list[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    
    return false;
}

ll bellman_ford(int start, int finish, int vertex_num) {
    bool pass_neg_cycle = false;
    vector<ll> dist(vertex_num);
    fill(dist.begin(), dist.end(), INF);
    
    dist[start] = -benefit[start];
    
    for(int i = 1; i < vertex_num; i++) {
        for(int v = 0; v < vertex_num; v++) {
            if(dist[v] == INF) continue;
            for(auto &[next, w]: adj_list[v]) {
                if(dist[next] > dist[v]+w) {
                    dist[next] = dist[v]+w;
                }
            }
        }
    }
    
    for(int v = 0; v < vertex_num; v++) {
        if(dist[v] == INF) continue;
        for(auto &[next, w]: adj_list[v]) {
            if(dist[next] > dist[v]+w) {
                if(bfs(v, finish)) pass_neg_cycle = true;
            }
        }
    }
    
    return (pass_neg_cycle ? -INF : dist[finish]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, start, finish, M; cin >> N >> start >> finish >> M;
    
    repeat(M) {
        int v1, v2, w; cin >> v1 >> v2 >> w;
        edges.pb({v1, v2, w});
    }
    
    for(int i = 0; i < N; i++) cin >> benefit[i];
    
    for(auto &e: edges) {
        adj_list[e.v1].pb({e.v2, e.w-benefit[e.v2]});
    }
    
    ll max_benefit = -bellman_ford(start, finish, N);
    if(max_benefit == -INF) cout << "gg";
    else if(max_benefit == INF) cout << "Gee";
    else cout << max_benefit;
    
    return 0;
}
