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

const int MOD = 1'000'000'007;

vector<pii> edges;

int parent[2000];
int temp[2000];
ll pow3[2000];

int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

void backup(int sz) {
    for(int i = 0; i < sz; i++) temp[i] = parent[i];
}

void rollback(int sz) {
    for(int i = 0; i < sz; i++) parent[i] = temp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        edges.pb({u, v});
    }
    
    for(int i = 0; i < N; i++) {
        parent[i] = i;
    }
    
    ll ans = 0;
    pow3[0] = 1;
    for(int i = 1; i < M; i++) pow3[i] = pow3[i-1]*3%MOD;
    
    for(int i = M-1; i >= 0; i--) {
        backup(N);
        merge(edges[i].fi, edges[i].se);
        if(findRoot(0) == findRoot(N-1)) {
            ans += pow3[i];
            ans %= MOD;
            rollback(N);
        }
    }
    
    cout << ans;
    
    return 0;
}