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

ll segTree[1 << 21] = {0, };

void update(int l, int r, int idx, int p, int x) {
    if(p < l || r < p) return;
    
    if(l == r) {
        segTree[idx] += x;
        return;
    }
    
    int mid = l+r >> 1;
    update(l, mid, idx<<1, p, x);
    update(mid+1, r, idx<<1|1, p, x);
    segTree[idx] = segTree[idx<<1]+segTree[idx<<1|1];
}

ll query(int l, int r, int idx, int i, int j) {
    if(j < l || r < i) return 0;
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = l+r >> 1;
    return query(l, mid, idx<<1, i, j)+query(mid+1, r, idx<<1|1, i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, Q; cin >> N >> Q;
    while(Q--) {
        int q, p, x;
        cin >> q >> p >> x;
        if(q == 1) {
            update(1, N, 1, p, x);
        }
        else {
            cout << query(1, N, 1, p, x) << '\n';
        }
    }
    
    return 0;
}
