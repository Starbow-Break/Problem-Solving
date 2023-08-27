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
int X[100001];

void initTree(int l, int r, int idx) {
    if(l == r) {
        if(X[l] == 0) segTree[idx] = 0;
        else segTree[idx] = X[l]/abs(X[l]);
        return;
    }
    
    int mid = l+r >> 1;
    initTree(l, mid, idx<<1);
    initTree(mid+1, r, idx<<1|1);
    segTree[idx] = segTree[idx<<1]*segTree[idx<<1|1];
}

void update(int l, int r, int idx, int i, int v) {
    if(i < l || r < i) return;
    
    if(l == r) {
        if(v == 0) segTree[idx] = 0;
        else segTree[idx] = v/abs(v);
        return;
    }
    
    int mid = l+r >> 1;
    update(l, mid, idx<<1, i, v);
    update(mid+1, r, idx<<1|1, i, v);
    segTree[idx] = segTree[idx<<1]*segTree[idx<<1|1];
}

int query(int l, int r, int idx, int i, int j) {
    if(j < l || r < i) return 1;
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = l+r >> 1;
    return query(l, mid, idx<<1, i, j)*query(mid+1, r, idx<<1|1, i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    while(cin >> N >> K) {
        FOR(i, 1, N+1) {
            cin >> X[i];
        }
        
        initTree(1, N, 1);
        
        while(K--) {
            char c; int x, y; cin >> c >> x >> y;
            if(c == 'C') {
                update(1, N, 1, x, y);
            }
            else {
                int ret = query(1, N, 1, x, y);
                if(ret > 0) cout << '+';
                else if(ret < 0) cout << '-';
                else cout << 0;
            }
        }
        
        cout << '\n';
    }
    
    return 0;
}