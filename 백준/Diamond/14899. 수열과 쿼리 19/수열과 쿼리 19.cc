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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll INF = 1'000'000'000'000'000'000;

struct node {
    ll minV, maxV, sum, lazy1, lazy2, check;
};

node segTree[1 << 18];
int A[100000];

node merge(node &a, node &b) {
    node ret;
    ret.minV = min(a.minV, b.minV);
    ret.maxV = max(a.maxV, b.maxV);
    ret.sum = a.sum+b.sum;
    ret.lazy1 = 0; ret.lazy2 = 0; ret.check = false;
    
    return ret;
}

void propagate(int l, int r, int idx) {
    ll lazy1 = segTree[idx].lazy1;
    ll lazy2 = segTree[idx].lazy2;
    if(l != r) {
        if(segTree[idx].check) {
            segTree[idx<<1].lazy1 = 0; segTree[idx<<1].lazy2 = lazy2;
            segTree[idx<<1].check = true;
            segTree[idx<<1|1].lazy1 = 0; segTree[idx<<1|1].lazy2 = lazy2;
            segTree[idx<<1|1].check = true;
        }
        segTree[idx<<1].lazy1 += lazy1;
        segTree[idx<<1|1].lazy1 += lazy1;
    }
    
    if(segTree[idx].check) {
        segTree[idx].minV = lazy2;
        segTree[idx].maxV = lazy2;
        segTree[idx].sum = lazy2*(r-l+1);
    }
    segTree[idx].minV += lazy1;
    segTree[idx].maxV += lazy1;
    segTree[idx].sum += lazy1*(r-l+1);
    segTree[idx].lazy1 = 0; segTree[idx].lazy2 = 0;
    segTree[idx].check = false;
}

ll divide(ll a, ll b) {
    return a/b-(a < 0 && abs(a)%b);
}

void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = {A[l], A[l], A[l], 0, 0, false};
        return;
    }
    
    int mid = (l+r)>>1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, idx<<1|1);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

void query1(int l, int r, int idx, int i, int j, int c) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].lazy1 += c;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)>>1;
    query1(l, mid, idx<<1, i, j, c); query1(mid+1, r, idx<<1|1, i, j, c);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

void query2(int l, int r, int idx, int i, int j, int d) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        if(divide(segTree[idx].minV, d) == divide(segTree[idx].maxV, d)) {
            ll v = divide(segTree[idx].minV, d);
            segTree[idx].lazy2 = v;
            segTree[idx].check = true;
            propagate(l, r, idx);
            return;
        }
        if(segTree[idx].maxV == segTree[idx].minV+1) {
            ll v = segTree[idx].maxV-divide(segTree[idx].maxV, d);
            segTree[idx].lazy1 -= v;
            propagate(l, r, idx);
            return;
        }
    }
    
    int mid = (l+r)>>1;
    query2(l, mid, idx<<1, i, j, d); query2(mid+1, r, idx<<1|1, i, j, d);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

ll query3(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return INF;
    
    if(i <= l && r <= j) return segTree[idx].minV;
    
    int mid = (l+r)>>1;
    return min(query3(l, mid, idx<<1, i, j), query3(mid+1, r, idx<<1|1, i, j));
}

ll query4(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx].sum;
    
    int mid = (l+r)>>1;
    return query4(l, mid, idx<<1, i, j)+query4(mid+1, r, idx<<1|1, i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, Q; cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> A[i];
    
    initTree(0, N-1, 1);
    
    while(Q--) {
        int q, l, r, c; cin >> q;
        switch(q) {
            case 1:
            cin >> l >> r >> c;
            query1(0, N-1, 1, l, r, c);
            break;
            case 2:
            cin >> l >> r >> c;
            query2(0, N-1, 1, l, r, c);
            break;
            case 3:
            cin >> l >> r;
            cout << query3(0, N-1, 1, l, r) << '\n';
            break;
            case 4:
            int l, r; cin >> l >> r;
            cout << query4(0, N-1, 1, l, r) << '\n';
        }
    }

    return 0;
}