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

const int INF = 1e9;
pii segTree[1 << 18];
int lazy[1 << 18] = {0, };

vector<pii> datas;

void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = datas[l-1];
        return;
    }
    
    int mid = (l+r) >> 1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, idx<<1|1);
    segTree[idx] = (segTree[idx<<1] < segTree[idx<<1|1] ?
        segTree[idx<<1] : segTree[idx<<1|1]);
}

void propagate(int l, int r, int idx) {
    if(l != r) {
        lazy[idx<<1] += lazy[idx];
        lazy[idx<<1|1] += lazy[idx];
    }
    
    segTree[idx].fi += lazy[idx];
    lazy[idx] = 0;
}

void update(int l, int r, int idx, int i, int j, int delta) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        lazy[idx] += delta;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r) >> 1;
    update(l, mid, idx<<1, i, j, delta);
    update(mid+1, r, idx<<1|1, i, j, delta);
    segTree[idx] = (segTree[idx<<1] < segTree[idx<<1|1] ?
        segTree[idx<<1] : segTree[idx<<1|1]);
}

pii query(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return {INF, INF};
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = (l+r) >> 1;
    pii L = query(l, mid, idx<<1, i, j);
    pii R = query(mid+1, r, idx<<1|1, i, j);
    return (L < R ? L : R);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 1; i < (1<<18); i++) {
        segTree[i] = {INF, INF};
    }
    
    int N, M; cin >> N >> M;
    vector<int> pos(N);
    
    for(int i = 0; i < N; i++) {
        int p, c; cin >> p >> c;
        datas.pb({c, p});
        pos[i] = p;
    }
    
    sort(pos.begin(), pos.end());
    
    for(int i = 0; i < N; i++) {
        datas[i].se = lower_bound(pos.begin(), pos.end(), datas[i].se)-pos.begin()+1;
    }
    
    sort(datas.begin(), datas.end(), [&](pii &a, pii &b) {
        return a.se < b.se;
    });
    
    initTree(1, N, 1);
    
    queue<pii> q; q.push({1, N});
    
    ll ans = 0;
    while(!q.empty()) {
        pii range = q.front(); q.pop();
        pii v = query(1, N, 1, range.fi, range.se);
        
        ans += v.fi;
        
        if(range.fi <= v.se-1) {
            q.push({range.fi, v.se-1});
        }
        if(v.se+1 <= range.se) {
            q.push({v.se+1, range.se});
        }
        
        update(1, N, 1, range.fi, range.se, -v.fi);
    }
    
    cout << ans;
    
    return 0;
}