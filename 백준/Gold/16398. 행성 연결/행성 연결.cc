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
    int a, b, w;
    
    bool operator<(edge &e) {
        return w < e.w;
    }
};

vector<edge> edges;
int parent[1001];

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    int arr[1001][1001];
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
        for(int j = 1; j <= N; j++) cin >> arr[i][j];
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            edges.pb({i, j, arr[i][j]});
        }
    }
    
    sort(all(edges));
    
    ll ans = 0, cnt = 0;
    for(int i = 0; i < edges.size() && cnt < N-1; i++) {
        if(findRoot(edges[i].a) != findRoot(edges[i].b)) {
            merge(edges[i].a, edges[i].b);
            ans += edges[i].w;
            cnt++;
        }
    }
    
    cout << ans;
    
    return 0;
}