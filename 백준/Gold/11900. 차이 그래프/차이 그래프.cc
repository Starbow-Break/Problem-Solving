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

int N; 
int dist[2'000];
int A[2'000];

void dijkstra(int start) {
    fill(dist, dist+2'000, INF);
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({start, 0}); dist[start] = 0;
    
    while(!pq.empty()) {
        int cur = pq.top().fi;
        int d = pq.top().se;
        pq.pop();
        
        for(int next = 0; next < N; next++) {
            if(A[(N+cur-next)%N] > 0) {
                if(dist[next] > dist[cur]+A[(N+cur-next)%N]) {
                    dist[next] = dist[cur]+A[(N+cur-next)%N];
                    pq.push({next, dist[next]});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    A[0] = 0;
    for(int i = 1; i < N; i++) cin >> A[i];
    
    dijkstra(0);
    
    int Q; cin >> Q;
    while(Q--) {
        int a, b; cin >> a >> b;
        cout << (dist[(N+b-a)%N] == INF ? -1 : dist[(N+b-a)%N]) << '\n';
    }
    
    return 0;
}
