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

struct node {
    ll sum, minV;
};

node segTree[1<<19];
ll arr[200001];

node merge(int a, int b) {
    node newNode;
    newNode.sum = segTree[a].sum+segTree[b].sum;
    newNode.minV = min(segTree[a].minV, segTree[b].minV);
    
    return newNode;
}

void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = {arr[l], arr[l]};
        return;
    }
    
    int mid = (l+r)>>1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, (idx<<1)|1);
    segTree[idx] = merge(idx<<1, (idx<<1)|1);
}

void update(int l, int r, int idx, int t, int v) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] = {v, v};
        return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, t, v); update(mid+1, r, (idx<<1)|1, t, v);
    segTree[idx] = merge(idx<<1, (idx<<1)|1);
}

ll getSum(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx].sum;
    
    int mid = (l+r)>>1;
    ll A = getSum(l, mid, idx<<1, i, j);
    ll B = getSum(mid+1, r, (idx<<1)|1, i, j);
    
    return A+B;
}

ll getMin(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return 1e9;
    
    if(i <= l && r <= j) return segTree[idx].minV;
    
    int mid = (l+r)>>1;
    ll A = getMin(l, mid, idx<<1, i, j);
    ll B = getMin(mid+1, r, (idx<<1)|1, i, j);
    
    return min(A, B);
}

int getLeftIndex(int N, int i, int j) {
    if(i == 1) return 1;
    
    int l = 1; int r = i;
    while(l <= r) {
        int mid = (l+r)>>1;
        
        if(getMin(1, N, 1, mid, i) >= j) r = mid-1;
        else l = mid+1;
    }
    
    return l;
}

int getRightIndex(int N, int i, int j) {
    if(i == N) return N;
    
    int l = i; int r = N;
    while(l <= r) {
        int mid = (l+r)>>1;
        
        if(getMin(1, N, 1, i, mid) >= j) l = mid+1;
        else r = mid-1;
    }
    
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) { cin >> arr[i]; }
    
    initTree(1, N, 1);
    
    int M; cin >> M;
    while(M--) {
        int q, i, j; cin >> q >> i >> j;
        if(q == 1) {
            update(1, N, 1, i, j);
        }
        else {
            int l = getLeftIndex(N, i, j);
            int r = getRightIndex(N, i, j);
            cout << getSum(1, N, 1, l, r) << '\n';
        }
    }

    return 0;
}