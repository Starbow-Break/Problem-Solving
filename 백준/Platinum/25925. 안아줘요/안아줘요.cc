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

//max segment tree
struct SegmentTree {
    int segTree[1 << 20];
    
    SegmentTree() {
        fill(segTree, segTree+(1<<20), 0);
    }
    
    void update(int l, int r, int idx, int t, int v) {
        if(r < t || t < l) return;
        
        if(l == r) {
            segTree[idx] = max(segTree[idx], v);
            return;
        }
        
        int mid = (l+r) >> 1;
        update(l, mid, idx<<1, t, v); update(mid+1, r, idx<<1|1, t, v);
        segTree[idx] = max(segTree[idx<<1], segTree[idx<<1|1]);
    }
    
    int query(int l, int r, int idx, int i, int j) {
        if(r < i || j < l) return 0;
        
        if(i <= l && r <= j) return segTree[idx];
        
        int mid = (l+r) >> 1;
        return max(query(l, mid, idx<<1, i, j), query(mid+1, r, idx<<1|1, i, j));
    }
};

int y_minus_x[500001], y_plus_x[500001];
vector<pii> y;
vector<int> vec1, vec2; // y-x, y+x

int ans[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, Q; cin >> N >> Q;
    SegmentTree seg1 = SegmentTree(), seg2 = SegmentTree(); // y-x, y+x
    
    for(int i = 1; i <= N; i++) {
        int X, Y; cin >> X >> Y;
        y.pb({Y, i});
        y_minus_x[i] = Y-X; y_plus_x[i] = Y+X;
        vec1.pb(Y-X); vec2.pb(Y+X);
    }
    
    sort(all(y));
    compress(vec1); compress(vec2);
    
    //Sweeping
    for(auto &p: y) {
        int v1 = lower_bound(vec1.begin(), vec1.end(), y_minus_x[p.se])-vec1.begin()+1;
        int v2 = lower_bound(vec2.begin(), vec2.end(), y_plus_x[p.se])-vec2.begin()+1;
        int q1 = seg1.query(1, N, 1, v1, N);
        int q2 = seg2.query(1, N, 1, v2, N);
        
        ans[p.se] = max(q1, q2)+1;
        
        seg1.update(1, N, 1, v1, ans[p.se]);
        seg2.update(1, N, 1, v2, ans[p.se]);
    }
    
    while(Q--) {
        int q; cin >> q;
        cout << ans[q] << '\n';
    }
    
    return 0;
}
