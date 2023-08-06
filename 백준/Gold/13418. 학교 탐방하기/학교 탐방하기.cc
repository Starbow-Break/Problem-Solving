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

struct edge {
    int s, f, w;
    
    bool operator<(edge &e) {
        return w < e.w;
    }
};

vector<edge> edges;
int parent[1001];

int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v]  = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

void init(int n) {
    FOR(i, 0, n+1) {
        parent[i] = i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    M++;
    while(M--) {
        int s, f, w; cin >> s >> f >> w;
        edges.pb({s, f, 1-w});
    }
    
    init(N);
    sort(edges.begin(), edges.end());
    int cnt = 0, maxV = 0, minV = 0;
    for(auto &e: edges) {
        if(cnt == N) break;
        if(findRoot(e.s) != findRoot(e.f)) {
            merge(e.s, e.f);
            minV += e.w;
            cnt++;
        }
    }
    
    init(N);
    sort(edges.rbegin(), edges.rend());
    cnt = 0;
    for(auto &e: edges) {
        if(cnt == N) break;
        if(findRoot(e.s) != findRoot(e.f)) {
            merge(e.s, e.f);
            maxV += e.w;
            cnt++;
        }
    }
    
    cout << maxV*maxV-minV*minV;
    
    return 0;
}
