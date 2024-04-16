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

vector<pii> edges(100'001);
bool cut[100'001] = {false, };
vector<int> cutEdge;

int parent[100'001], sz[100'001];
int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a), rb = findRoot(b);
    if(ra == rb) return;
    
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
    sz[ra] += sz[rb];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, Q; cin >> N >> M >> Q;
    
    for(int i = 1; i <= N; i++) {
        parent[i] = i; sz[i] = 1;
    }
    
    for(int i = 1; i <= M; i++) {
        int a, b; cin >> a >> b;
        edges[i] = {a, b};
    }
    
    for(int q = 1; q <= Q; q++) {
        int v; cin >> v;
        cut[v] = true;
        cutEdge.pb(v);
    }
    
    for(int i = 1; i <= M; i++) {
        if(!cut[i]) {
            merge(edges[i].fi, edges[i].se);
        }
    }
    
    ll ans = 0;
    reverse(all(cutEdge));
    for(auto &e: cutEdge) {
        int ra = findRoot(edges[e].fi);
        int rb = findRoot(edges[e].se);
        
        if(ra != rb) {
            ans += 1LL*sz[ra]*sz[rb];
            merge(ra, rb);
        }
    }
    
    cout << ans;
    
    return 0;
}
