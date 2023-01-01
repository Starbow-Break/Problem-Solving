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

const int INF = 1000010000;

struct node {
    int value, maxV, minV;
};

int N;
int arr[100001];
node segTree[270000];

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

//두 노드 병합
node merge(node &left, node &right) {
    int maxV = max(left.maxV, right.maxV);
    int minV = min(left.minV, right.minV);
    int value = max(left.value, right.value, right.maxV-left.minV);
    
    return {value, maxV, minV};
}

//초기 트리
void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = {0, arr[l], arr[l]};
        return;
    }
    
    int mid = (l+r)>>1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, (idx<<1)|1);
    segTree[idx] = merge(segTree[idx<<1], segTree[(idx<<1)|1]);
}

//값 수정
void update(int l, int r, int idx, int t, int value) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] = {0, value, value};
        return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, t, value);
    update(mid+1, r, (idx<<1)|1, t, value);
    segTree[idx] = merge(segTree[idx<<1], segTree[(idx<<1)|1]);
}

//최대 상승값
node query(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return {0, -INF, INF};
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = (l+r)>>1;
    node left = query(l, mid, idx<<1, i, j);
    node right = query(mid+1, r, (idx<<1)|1, i, j);
    return merge(left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) { cin >> arr[i]; }
    
    initTree(1, N, 1);
    
    int M; cin >> M;
    while(M--) {
        int q, a, b; cin >> q >> a >> b;
        if(q == 1) {
            update(1, N, 1, a, b);
        }
        else {
            cout << query(1, N, 1, a, b).value << '\n';
        }
    }

    return 0;
}