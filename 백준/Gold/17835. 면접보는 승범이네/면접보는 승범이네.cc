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

vector<pii> edges[100001];
ll dist[100001];

struct cmp {
    bool operator()(pll &a, pll &b) {
        return a.fi > b.fi;
    }
};

void dijkstra(vector<int> &start) {
    fill(dist, dist+100001, INF);
    priority_queue<pll, vector<pll>, cmp> pq;
    for(auto &s: start) {
        pq.push({0, s}); dist[s] = 0;
    }
    
    while(!pq.empty()) {
        ll d = pq.top().fi;
        int cur = pq.top().se;
        pq.pop();
        
        if(d > dist[cur]) continue;
        
        for(auto &[next, w]: edges[cur]) {
            if(dist[next] > d+w) {
                dist[next] = d+w;
                pq.push({dist[next], next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K; cin >> N >> M >> K;
    repeat(M) {
        int a, b, w; cin >> a >> b >> w;
        edges[b].pb({a, w});
    }
    
    vector<int> start(K);
    FOR(i, 0, K) cin >> start[i];
    
    dijkstra(start);
    
    int ans = 1;
    for(int i = 1; i <= N; i++) {
        if(dist[i] > dist[ans]) ans = i;
    }
    
    cout << ans << '\n' << dist[ans];
    
    return 0;
}
