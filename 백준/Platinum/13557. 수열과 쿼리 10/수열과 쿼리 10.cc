#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct node {
    ll minV, maxV;
};

struct node2 {
    ll maxV, maxL, maxR, sum;
};

node segTree[270000];
node2 segTree2[270000];
ll arr[100001];
ll S[100001];

const ll INF = 1e18;

node2 merge(node2 A, node2 B) {
    node2 newNode;
    
    newNode.sum = A.sum+B.sum;
    newNode.maxL = max(A.maxL, A.sum+B.maxL);
    newNode.maxR = max(B.maxR, A.maxR+B.sum);
    
    newNode.maxV = max(A.maxV, B.maxV);
    newNode.maxV = max(newNode.maxV, newNode.maxL);
    newNode.maxV = max(newNode.maxV, newNode.maxR);
    newNode.maxV = max(newNode.maxV, A.maxR+B.maxL);
    
    return newNode;
}

void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx].minV = S[l];
        segTree[idx].maxV = S[l];
        return;
    }
    
    int mid = (l+r)>>1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, (idx<<1)|1);
    segTree[idx].maxV = max(segTree[idx<<1].maxV, segTree[(idx<<1)|1].maxV);
    segTree[idx].minV = min(segTree[idx<<1].minV, segTree[(idx<<1)|1].minV);
}

void initTree2(int l, int r, int idx) {
    if(l == r) {
        segTree2[idx].maxV = arr[l];
        segTree2[idx].maxL = arr[l];
        segTree2[idx].maxR = arr[l];
        segTree2[idx].sum = arr[l];
        return;
    }
    
    int mid = (l+r)>>1;
    initTree2(l, mid, idx<<1); initTree2(mid+1, r, (idx<<1)|1);
    segTree2[idx] = merge(segTree2[idx<<1], segTree2[(idx<<1)|1]);
}

ll maxQuery(int l, int r, int idx, int i, int j) {
    if(i <= l && r <= j) return segTree[idx].maxV;
    if(r < i || j < l) return -INF;
    
    int mid = (l+r)>>1;
    ll L = maxQuery(l, mid, idx<<1, i, j);
    ll R = maxQuery(mid+1, r, (idx<<1)|1, i, j);
    return max(L, R);
}

ll minQuery(int l, int r, int idx, int i, int j) {
    if(i <= l && r <= j) return segTree[idx].minV;
    if(r < i || j < l) return INF;
    
    int mid = (l+r)>>1;
    ll L = minQuery(l, mid, idx<<1, i, j);
    ll R = minQuery(mid+1, r, (idx<<1)|1, i, j);
    return min(L, R);
}

node2 query2(int l, int r, int idx, int i, int j) {
    if(i <= l && r <= j) return segTree2[idx];
    if(r < i || j < l) return {-INF, -INF, -INF, 0};
    
    int mid = (l+r)>>1; 
    node2 L = query2(l, mid, idx<<1, i, j);
    node2 R = query2(mid+1, r, (idx<<1)|1, i, j);
    return merge(L, R);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    S[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i]; S[i] = S[i-1]+arr[i];
    }
    
    initTree(0, N, 1);
    initTree2(0, N, 1);
    
    int M; cin >> M;
    while(M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        if(y1 <= x2) {
            cout << maxQuery(0, N, 1, x2, y2)-minQuery(0, N, 1, x1-1, y1-1) << '\n';
        }
        else {
            ll ans = -INF;
            ans = max(ans, maxQuery(0, N, 1, y1, y2)-minQuery(0, N, 1, x1-1, y1-1));
            ans = max(ans, maxQuery(0, N, 1, x2, y2)-minQuery(0, N, 1, x1-1, x2-1));
            ans = max(ans, query2(0, N, 1, x2, y1).maxV);
            cout << ans << '\n';
        }
    }

    return 0;
}