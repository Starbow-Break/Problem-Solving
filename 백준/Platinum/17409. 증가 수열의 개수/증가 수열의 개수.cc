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
#define MAX_N 100'000
#define MOD 1'000'000'007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

//세그먼트 트리에 사용할 노드
struct node {
    int cnt[11];
    
    //노드 초기화
    void init() {
        fill(cnt, cnt+11, 0);
    }
};

node segTree[1<<18]; int A[MAX_N+1];

//두 노드 병합
node merge(node a, node b) {
    node ret;
    
    for(int i = 0; i <= 10; i++) {
        ret.cnt[i] = (a.cnt[i]+b.cnt[i])%MOD;
    }
    
    return ret;
}

//세그트리 초기화
void initTree() {
    for(int i = 1; i < (1<<18); i++) segTree[i].init();
}

//업데이트 쿼리
void update(int l, int r, int idx, int t, node newNode) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] = newNode;
        return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, t, newNode); update(mid+1, r, (idx<<1)|1, t, newNode);
    segTree[idx] = merge(segTree[idx<<1], segTree[(idx<<1)|1]);
}

node query(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) {
        node zero; zero.init();
        return zero;
    }
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = (l+r)>>1;
    return merge(query(l, mid, idx<<1, i, j), query(mid+1, r, (idx<<1)|1, i, j));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    
    initTree();
    
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        node newNode = query(1, N, 1, 1, v-1);
        for(int j = 9; j >= 1; j--) newNode.cnt[j+1] = newNode.cnt[j];
        newNode.cnt[1] = 1;
        update(1, N, 1, v, newNode);
    }
    
    cout << segTree[1].cnt[K];

    return 0;
}