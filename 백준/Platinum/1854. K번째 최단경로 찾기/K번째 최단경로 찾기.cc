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
        return a.fi > b.fi;
    }
};

vector<pii> edges[1001];
priority_queue<int, vector<int>, less<int>> dist[1001];

void dijkstra(int start, int k) {
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({0, start}); dist[start].push(0);
    
    while(!pq.empty()) {
        int cur = pq.top().se, d = pq.top().fi;
        pq.pop();
        
        if(dist[cur].size() == k && dist[cur].top() < d) continue;
        
        for(auto &[next, w]: edges[cur]) {
            if(dist[next].size() < k) {
                dist[next].push(d+w);
                pq.push({d+w, next});
            }
            else {
                if(d+w < dist[next].top()) {
                    dist[next].pop();
                    dist[next].push(d+w);
                    pq.push({d+w, next});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K; cin >> N >> M >> K;
    for(int i = 1; i <= M; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges[a].pb({b, w});
    }
    
    dijkstra(1, K);
    
    for(int i = 1; i <= N; i++) {
        cout << (dist[i].size() == K ? dist[i].top() : -1) << '\n';
    }
    
    return 0;
}
