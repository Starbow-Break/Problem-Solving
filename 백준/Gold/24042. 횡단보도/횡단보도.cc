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

const ll INF = 1'000'000'000'000'000'000;

struct edge {
    int f, num;
};

struct node {
    int v; ll dist;
};

struct cmp {
    bool operator()(node &a, node &b) {
        return a.dist > b.dist;
    }
};

int N, M;
vector<edge> edges[100001];

ll d[100001];
void dijkstra(int start, int end) {
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({start, 0}); d[start] = 0;
    
    while(!pq.empty()) {
        int cur = pq.top().v;
        ll dist = pq.top().dist;
        pq.pop();
        
        if(d[cur] < dist) continue;
        for(auto &e: edges[cur]) {
            ll dd;
            if(dist < e.num) dd = e.num+1;
            else {
                if(dist%M <= e.num%M) {
                    dd = dist/M*M+e.num%M+1;
                }
                else {
                    dd = M*(dist/M+1)+e.num%M+1;
                }
            }
            
            if(dd < d[e.f]) {
                d[e.f] = dd;
                pq.push({e.f, dd});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    fill(d, d+N+1, INF);
    
    FOR(i, 0, M) {
        int a, b; cin >> a >> b;
        edges[a].pb({b, i});
        edges[b].pb({a, i});
    }
    
    dijkstra(1, N);
    
    cout << d[N];
    
    return 0;
}
