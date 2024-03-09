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

struct cmp {
    bool operator()(pll &a, pll &b) {
        return a.fi > b.fi;
    } 
};

int N, M; 
int numToVertex[22];
int vertexToNum[100'001];

vector<pii> edges[100'001]; // 원래 그래프
vector<pll> edgesA[22]; // 필요한 정보만 모아놓은 그래프

ll dist[100'001];
void dijkstra(int start) {
    fill(dist, dist+N+1, INF);
    
    priority_queue<pll, vector<pll>, cmp> pq;
    dist[start] = 0; pq.push({0, start});
    
    while(!pq.empty()) {
        int cur = pq.top().se;
        ll d = pq.top().fi;
        pq.pop();
        
        if(d != dist[cur]) continue;
        
        for(auto &[next, w]: edges[cur]) {
            if(dist[next] > dist[cur] + w) {
                dist[next] = dist[cur] + w;
                pq.push({dist[next], next});
            }
        }
    }
}

ll dp[1 << 20][20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    while(M--) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].pb({v, w}); edges[v].pb({u, w});
    }
    
    int X, Z, P; cin >> X >> Z >> P;
    vertexToNum[X] = P; numToVertex[P] = X;
    vertexToNum[Z] = P+1; numToVertex[P+1] = Z;
    
    for(int p = 0; p < P; p++) {
        int v; cin >> v;
        vertexToNum[v] = p; numToVertex[p] = v;
    }
    
    for(int i = 0; i < P+1; i++) {
        dijkstra(numToVertex[i]);
        for(int j = i+1; j <= P+1; j++) {
            if(dist[numToVertex[j]] != INF) {
                edgesA[i].pb({j, dist[numToVertex[j]]});
                edgesA[j].pb({i, dist[numToVertex[j]]});
            }
        }
    }
    
    for(int i = 0; i < (1 << P); i++) {
        fill(dp[i], dp[i]+P, INF);
    }
    
    for(auto &[next, w]: edgesA[P]) {
        if(next < P) {
            dp[1 << next][next] = w;
        }
    }
    
    for(int status = 1; status < (1 << P); status++) {
        for(int cur = 0; cur < P; cur++) {
            if(dp[status][cur] != INF) {
                for(auto &[next, w]: edgesA[cur]) {
                    if(next < P && !(status & (1 << next))) {
                        dp[status | (1 << next)][next] = min(
                            dp[status | (1 << next)][next], dp[status][cur] + w
                        );
                    }
                }
            }
        }
    }
    
    ll ans = INF;
    for(auto &[prev, w]: edgesA[P+1]) {
        if(prev < P) {
            ans = min(ans, dp[(1 << P) - 1][prev] + w);
        }
    }
    
    cout << (ans == INF ? -1 : ans);
    
    return 0;
}
