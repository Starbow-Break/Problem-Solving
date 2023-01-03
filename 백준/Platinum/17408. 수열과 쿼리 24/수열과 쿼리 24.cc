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
    int max1, max2;
};

int arr[100001];
node segTree[270000];

node merge(int a, int b) {
    int v[4] = {segTree[a].max1, segTree[a].max2, 
                segTree[b].max1, segTree[b].max2};
    sort(v, v+4);
    return {v[3], v[2]};
}

node merge(node a, node b) {
    int v[4] = {a.max1, a.max2, b.max1, b.max2};
    sort(v, v+4);
    return {v[3], v[2]};
}

void initTree(int i, int j, int idx) {
    if(i == j) {
        segTree[idx] = {arr[i], 0};
        return;
    }
    
    int mid = (i+j)>>1;
    initTree(i, mid, idx<<1);
    initTree(mid+1, j, (idx<<1)|1);
    
    segTree[idx] = merge(idx<<1, (idx<<1)|1);
}

void update(int i, int j, int idx, int t, int v) {
    if(j < t || t < i) return;
    
    if(i == j) {
        segTree[idx] = {v, 0};
        return;
    }
    
    int mid = (i+j)>>1;
    update(i, mid, idx<<1, t, v); update(mid+1, j, (idx<<1)|1, t, v);
    segTree[idx] = merge(idx<<1, (idx<<1)|1);
}

node getMax1AndMax2(int i, int j, int idx, int l, int r) {
    if(j < l || r < i) return {0, 0};
    
    if(l <= i && j <= r) return segTree[idx];
    
    int mid = (i+j)>>1;
    node L = getMax1AndMax2(i, mid, idx<<1, l, r);
    node R = getMax1AndMax2(mid+1, j, (idx<<1)|1, l, r);
    return merge(L, R);
}

int query(int N, int l, int r) {
    node p = getMax1AndMax2(1, N, 1, l, r);
    return p.max1+p.max2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    
    initTree(1, N, 1);
    
    int Q; cin >> Q;
    while(Q--) {
        int q; cin >> q;
        if(q == 1) {
            int i, v; cin >> i >> v;
            update(1, N, 1, i, v);
        }
        else {
            int l, r; cin >> l >> r;
            cout << query(N, l, r) << '\n';
        }
    }

    return 0;
}