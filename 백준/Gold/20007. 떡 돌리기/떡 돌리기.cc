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

const int INF = 1'000'000'000;

vector<pii> edges[1000];

int dist[1000];

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({0, s}); dist[s] = 0;
    
    while(!pq.empty()) {
        int cur = pq.top().se;
        int d = pq.top().fi;
        pq.pop();
        
        for(auto &[next, w]: edges[cur]) {
            if(dist[cur]+w < dist[next]) {
                dist[next] = dist[cur]+w;
                pq.push({dist[next], next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, X, Y; cin >> N >> M >> X >> Y;
    
    while(M--) {
        int a, b, w; cin >> a >> b >> w;
        edges[a].pb({b, w}); edges[b].pb({a, w});
    }
    
    fill(dist, dist+N, INF);
    dijkstra(Y);
    
    vector<int> vec;
    for(int i = 0; i < N; i++) vec.pb(2*dist[i]);
    sort(all(vec));
    
    int cnt = 0;
    int i = 0, cur = 0;
    while(i < N) {
        if(vec[i] > X) {
            cnt = -1;
            break;
        }
        
        if(cur+vec[i] > X) {
            cnt++;
            cur = vec[i]; 
        }
        else cur += vec[i];
        
        i++;
    }
    if(cnt != -1) cnt++;
    
    cout << cnt;
    
    return 0;
}