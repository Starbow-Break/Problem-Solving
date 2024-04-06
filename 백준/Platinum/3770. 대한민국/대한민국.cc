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

int segTree[1 << 18];

void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = 0;
        return;
    }
    
    int mid = (l+r) >> 1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, idx<<1|1);
    segTree[idx] = segTree[idx<<1] + segTree[idx<<1|1];
}

void update(int l, int r, int idx, int t, int delta) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] += delta;
        return;
    }
    
    int mid = (l+r) >> 1;
    update(l, mid, idx<<1, t, delta); update(mid+1, r, idx<<1|1, t, delta);
    segTree[idx] = segTree[idx<<1] + segTree[idx<<1|1];
}

int query(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = (l+r) >> 1;
    return query(l, mid, idx<<1, i, j)+query(mid+1, r, idx<<1|1, i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int N, M, K; cin >> N >> M >> K;
        
        vector<pii> edges;
        
        while(K--) {
            int a, b; cin >> a >> b;
            edges.pb({a, b});
        }
        
        sort(all(edges));
        
        initTree(1, M, 1);
        
        ll ans = 0; int idx = 0;
        queue<int> q;
        for(int i = 1; i <= N; i++) {
            while(idx < edges.size() && edges[idx].fi == i) {
                q.push(edges[idx].se);
                ans += query(1, M, 1, edges[idx].se+1, M);
                idx++;
            }
            
            while(!q.empty()) {
                update(1, M, 1, q.front(), 1);
                q.pop();
            }
        }
        
        cout << "Test case "  << tc << ": ";
        cout << ans << '\n';
    }
    
    return 0;
}