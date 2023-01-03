#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>
#define MOD 998244353

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct node {
    ll value = 0, weight = 0, lazy = -1;
};

int N, Q; 
node segTree[1<<20];

void initTree(int i, int j, int idx) {
    if(i == j) {
        segTree[idx].weight = 1LL*i*(N-i+1)%MOD;
        return;
    }
    
    int mid = (i+j)>>1;
    initTree(i, mid, idx<<1); initTree(mid+1, j, (idx<<1)|1);
    segTree[idx].weight = segTree[idx<<1].weight+segTree[(idx<<1)|1].weight;
    segTree[idx].weight %= MOD;
}

void propagate(int i, int j, int idx) {
    if(segTree[idx].lazy == -1) return;
    
    segTree[idx].value = segTree[idx].lazy*segTree[idx].weight%MOD;
    
    if(i != j) {
        segTree[idx<<1].lazy = segTree[idx].lazy;
        segTree[(idx<<1)|1].lazy = segTree[idx].lazy;
    }
    
    segTree[idx].lazy = -1;
}

void update(int i, int j, int idx, int l, int r, ll c) {
    propagate(i, j, idx);
    
    if(j < l || r < i) return;
    
    if(l <= i && j <= r) {
        segTree[idx].lazy = c;
        propagate(i, j, idx);
        return;
    }
    
    int mid = (i+j)>>1;
    update(i, mid, idx<<1, l, r, c);
    update(mid+1, j, (idx<<1)|1, l, r, c);
    segTree[idx].value = segTree[idx<<1].value+segTree[(idx<<1)|1].value;
    segTree[idx].value %= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q;
    
    initTree(1, N, 1);
    
    ll ans = 0;
    for(int i = 1; i <= Q; i++) {
        int l, r; ll c; cin >> l >> r >> c;
        c *= i; c %= MOD;
        
        update(1, N, 1, l, r, c);
        ans += segTree[1].value; ans %= MOD;
    }
    
    cout << ans;

    return 0;
}