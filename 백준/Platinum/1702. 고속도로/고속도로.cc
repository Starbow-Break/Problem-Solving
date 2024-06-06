#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v: vec)
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

const int INF = 1e9;

struct edge {
    int e, c, t;
};

struct cmp {
    bool operator()(pair<int, pii> &a, pair<int, pii> &b) {
        return a.fi > b.fi;
    }
};

vector<edge> edges[101];
int dist[101][10'001];

void dijkstra(int s, int e) {
    FOR(i, 1, 101) {
        fill(dist[i], dist[i]+10'001, INF);
    }
    
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, cmp> pq;
    pq.push({0, {s, 0}}); dist[s][0] = 0;
    
    while(!pq.empty()) {
        int d = pq.top().fi; pii cur = pq.top().se;
        pq.pop();
        
        if(cur.fi == e) continue;
        if(d > dist[cur.fi][cur.se]) continue;
        
        FORIter(ed, edges[cur.fi]) {
            if(cur.se+ed.c <= 10'000 && dist[ed.e][cur.se+ed.c] > d + ed.t) {
                dist[ed.e][cur.se+ed.c] = d + ed.t;
                pq.push({d + ed.t, {ed.e, cur.se+ed.c}});
            }
        }
    }
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, s, e; cin >> n >> m >> s >> e;
    repeat(m) {
        int p, r, c, t; cin >> p >> r >> c >> t;
        edges[p].pb({r, c, t});
        edges[r].pb({p, c, t});
    }
    
    dijkstra(s, e);
    
    int ans = 0, minDist = INF;
    FOR(cost, 0, 10'001) {
        if(dist[e][cost] < minDist) {
            ans++;
            minDist = dist[e][cost];
        }
    }
    
    cout << ans;
    
    return 0;
}