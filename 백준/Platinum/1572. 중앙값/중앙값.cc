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

int segTree[1 << 18] = {0, };

void update(int l, int r, int idx, int t, int d) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] += d;
        return;
    }
    
    int mid = (l+r) >> 1;
    update(l, mid, idx<<1, t, d);
    update(mid+1, r, idx<<1|1, t, d);
    segTree[idx] = segTree[idx<<1]+segTree[idx<<1|1];
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
    
    int N, K; cin >> N >> K;
    int t[N+1]; ll ans = 0;
    for(int i = 1; i <= N; i++) cin >> t[i];
    for(int i = 1; i <= N; i++) {
        update(0, 65536, 1, t[i], 1);
        
        if(i > K) {
            update(0, 65536, 1, t[i-K], -1);
        }
        
        if(i >= K) {
            int s = 0, e = 65536;
            while(s <= e) {
                int mid = (s+e) >> 1;
                int cnt = query(0, 65536, 1, 0, mid);
                if(cnt < (K+1)/2) s = mid+1;
                else e = mid-1;
            }
            
            ans += s;
        }
    }
    
    cout << ans;
    
    return 0;
}