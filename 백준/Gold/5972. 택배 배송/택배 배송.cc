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

vector<pii> edges[50001];
const int INF = 1'000'000'000;

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.se > b.se;
    }
};

int dijkstra(int s, int e) {
    int d[50001];
    fill(d, d+50001, INF);
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({s, 0}); d[s] = 0;
    
    while(!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        if(cur.se != d[cur.fi]) continue;
        for(auto &[next, w]: edges[cur.fi]) {
            if(d[next] > d[cur.fi]+w) {
                d[next] = d[cur.fi]+w;
                pq.push({next, d[next]});
            }
        }
    }
    
    return d[e];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b, w; cin >> a >> b >> w;
        edges[a].pb({b, w});
        edges[b].pb({a, w});
    }
    
    cout << dijkstra(1, N);
    
    return 0;
}