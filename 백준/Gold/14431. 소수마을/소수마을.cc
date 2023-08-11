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

const int INF = 1'000'000'000;

vector<pii> edges[4002];
vector<pii> pts;

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.se > b.se;
    }
};

bool isPrime[4900];
void getPrimes() {
    fill(isPrime+2, isPrime+4900, true);
    for(int i = 2; i < 4900; i++) {
        if(!isPrime[i]) continue;
        for(int j = i*2; j < 4900; j += i) {
            isPrime[j] = false;
        }
    }
}

int d[4002];
void dijkstra(int start) {
    fill(d, d+4002, INF);
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({start, 0}); d[start] = 0;
    while(!pq.empty()) {
        int cur = pq.top().fi, dist = pq.top().se;
        pq.pop();
        if(d[cur] < dist) continue;
        for(auto &[next, w]: edges[cur]) {
            if(d[next] > d[cur]+w) {
                d[next] = d[cur]+w;
                pq.push({next, d[next]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    pts.pb({x1, y1}); pts.pb({x2, y2});
    int N; cin >> N;
    repeat(N) {
        int x, y; cin >> x >> y;
        pts.pb({x, y});
    }
    
    for(int i = 0; i < N+2; i++) {
        for(int j = i+1; j < N+2; j++) {
            int d = sqrt(
                (pts[i].fi-pts[j].fi)*(pts[i].fi-pts[j].fi)
                +(pts[i].se-pts[j].se)*(pts[i].se-pts[j].se)
            );
            
            if(isPrime[d]) {
                edges[i].pb({j, d});
                edges[j].pb({i, d});
            }
        }
    }
    
    dijkstra(0);
    
    cout << (d[1] == INF ? -1 : d[1]);
    
    return 0;
}