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

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.se > b.se;
    }
};

const int INF = 1e9;

int N, M, K, S, T;
vector<pii> edges[500'000];
int dist[500'000];

void dijkstra(int start) {
    fill(dist, dist+500'000, INF);
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({start, 0}); dist[start] = 0;
    
    while(!pq.empty()) {
        int cur = pq.top().fi;
        int d = pq.top().se;
        pq.pop();
        
        for(auto &[next, w]: edges[cur]) {
            if(dist[next] > d + w) {
                dist[next] = d + w;
                pq.push({next, dist[next]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K >> S >> T;
    S--; T--;
    
    while(M--) {
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        for(int p = 0; p < K; p++) {
            edges[10000*p+a].pb({10000*((p+w)%K)+b, w});
        }
    }
    
    dijkstra(S);
    
    if(dist[T] == INF) cout << "IMPOSSIBLE";
    else cout << dist[T];
    
    return 0;
}