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
const int MOD = 1e9+9;

struct cmp {
    bool operator()(pair<int, pll> &a, pair<int, pll> &b) {
        return a.se > b.se;
    }
};

vector<pii> edges[100'001];
pll dist[100'001];
int dp[100'001] = {0, };

void dijkstra(int start) {
    for(int i = 1; i <= 100'000; i++) dist[i] = {INF, INF};
    
    priority_queue<pair<int, pll>, vector<pair<int, pll>>, cmp> pq;
    pq.push({start, {0, 0}}); dist[start] = {0, 0};
    
    while(!pq.empty()) {
        int cur = pq.top().fi;
        pll d = pq.top().se;
        pq.pop();
        
        if(dist[cur] < d) continue;
        
        for(auto &[next, w]: edges[cur]) {
            if(dist[next] > make_pair(dist[cur].fi + w, dist[cur].se + 1)) {
                dist[next] = {dist[cur].fi + w, dist[cur].se + 1};
                pq.push({next, dist[next]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, x, y; cin >> N >> M >> x >> y;
    while(M--) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].pb({v, w});
    }
    
    dijkstra(x);
    
    vector<pair<pll, int>> vec;
    for(int i = 1; i <= N; i++) {
        vec.pb({dist[i], i});
    }
    
    sort(all(vec));
    
    dp[x] = 1;
    for(auto &[d, cur]: vec) {
        for(auto &[next, w]: edges[cur]) {
            if(dist[next] == make_pair(d.fi+w, d.se+1)) {
                dp[next] += dp[cur];
                dp[next] %= MOD;
            }
        }
    }
    
    if(dist[y].fi != INF && dist[y].se != INF) {
        cout << dist[y].fi << '\n' << dist[y].se << '\n';
        cout << dp[y];
    }
    else cout << -1;
    
    return 0;
}
