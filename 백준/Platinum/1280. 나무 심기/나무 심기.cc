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

// 합 세그먼트 트리
struct SumSegTree {
    ll sgTree[1 << 19];
    
    SumSegTree() {
        fill(sgTree, sgTree+(1<<19), 0);
    }
    
    void update(int l, int r, int idx, int t, int v) {
        if(r < t || t < l) return;
        
        if(l == r) {
            sgTree[idx] += v;
            return;
        }
        
        int mid = l+r >> 1;
        update(l, mid, idx<<1, t, v); update(mid+1, r, idx<<1|1, t, v);
        sgTree[idx] = sgTree[idx<<1]+sgTree[idx<<1|1];
    }
    
    ll query(int l, int r, int idx, int i, int j) {
        if(r < i || j < l) return 0;
        
        if(i <= l && r <= j) return sgTree[idx];
        
        int mid = l+r >> 1;
        return query(l, mid, idx<<1, i, j) + query(mid+1, r, idx<<1|1, i, j);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    ll ans = 1;
    SumSegTree *segTree1 = new SumSegTree();
    SumSegTree *segTree2 = new SumSegTree();
    
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        
        ll sl = segTree1->query(0, 200000, 1, 0, v-1);
        ll cl = segTree2->query(0, 200000, 1, 0, v-1);
        ll sr = segTree1->query(0, 200000, 1, v+1, 200000);
        ll cr = segTree2->query(0, 200000, 1, v+1, 200000);
        if(i >= 2) {
            ll cur = v*cl-sl+(sr-v*cr);
            cur %= MOD;
            ans *= cur; ans %= MOD;
        }
        
        segTree1->update(0, 200000, 1, v, v);
        segTree2->update(0, 200000, 1, v, 1);
    }
    
    cout << ans;
    
    return 0;
}
