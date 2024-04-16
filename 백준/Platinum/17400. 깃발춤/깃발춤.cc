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

class SegmentTree {
    private:
    int sz;
    vector<ll> segTree;
    
    void _update(int l, int r, int idx, int t, int d) {
        if(r < t || t < l) return;
        
        if(l == r) {
            segTree[idx] += d;
            return;
        }
        
        int mid = (l+r) >> 1;
        _update(l, mid, idx<<1, t, d); 
        _update(mid+1, r, idx<<1|1, t, d);
        segTree[idx] = segTree[idx<<1]+segTree[idx<<1|1];
    }
    
    ll _sum(int l, int r, int idx, int i, int j) {
        if(r < i || j < l) return 0;
        if(i <= l && r <= j) return segTree[idx];
        
        int mid = (l+r) >> 1;
        return _sum(l, mid, idx<<1, i, j)
            + _sum(mid+1, r, idx<<1|1, i, j);
    }
    
    public:
    SegmentTree(vector<int> &init) {
        sz = init.size();
        segTree.resize(4*sz, 0);
        for(int i = 1; i <= sz; i++) {
            _update(1, sz, 1, i, init[i-1]);
        }
    }
    
    ll sum(int l, int r) {
        return _sum(1, sz, 1, l, r);
    }
    
    void add(int i, int x) {
        _update(1, sz, 1, i, x);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, Q; cin >> N >> Q;
    vector<int> odd, even;
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        if(i%2) odd.pb(v);
        else even.pb(v);
    }
    
    SegmentTree* oddSegTree = new SegmentTree(odd);
    SegmentTree* evenSegTree = new SegmentTree(even);
    
    while(Q--) {
        int q, l, r; cin >> q >> l >> r;
        if(q == 1) {
            ll oddTotal = 0, evenTotal = 0;
            if(r-l >= 1 || l%2) {
                oddTotal = oddSegTree->sum((l+2)/2, (r+1)/2);
            }
            if(r-l >= 1 || !(l%2)) {
                evenTotal = evenSegTree->sum((l+1)/2, r/2);
            }
            
            cout << abs(oddTotal-evenTotal) << '\n';
        }
        else {
            if(l%2) oddSegTree->add((l+1)/2, r);
            else evenSegTree->add(l/2, r);
        }
    }
    
    return 0;
}
