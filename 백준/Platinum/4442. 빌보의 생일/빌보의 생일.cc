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

void update(int l, int r, int idx, int t, int v) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] = v;
        return;
    }
    
    int mid = (l+r) >> 1;
    update(l, mid, idx<<1, t, v); update(mid+1, r, idx<<1|1, t, v);
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
    
    while(true) {
        int N; cin >> N;
        if(!N) break;
        
        map<string, int> mp;
        
        for(int i = 1; i <= N; i++) {
            string s; cin >> s;
            mp.insert({s, i});
        }
        
        vector<int> vec(N);
        for(int i = 0; i < N; i++) {
            string s; cin >> s;
            auto t = mp.find(s);
            vec[i] = t->se;
        }
        
        initTree(1, N, 1);
        
        ll ans = 0;
        for(auto &v: vec) {
            ans += query(1, N, 1, v, N);
            update(1, N, 1, v, 1);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}