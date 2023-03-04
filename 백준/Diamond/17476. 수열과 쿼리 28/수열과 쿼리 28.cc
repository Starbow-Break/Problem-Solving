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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct node {
    ll value, minV, maxV, lazy1, lazy2;
};

int A[MAX_N+1];
node segTree[1 << 18];

//노드 갱신 및 lazy 전파
void propagate(int l, int r, int idx) {
    if(segTree[idx].lazy2 != -1) {
        segTree[idx].value = segTree[idx].lazy2*(r-l+1);
        segTree[idx].minV = segTree[idx].maxV = segTree[idx].lazy2;
    }
    
    segTree[idx].value += segTree[idx].lazy1*(r-l+1);
    segTree[idx].minV += segTree[idx].lazy1;
    segTree[idx].maxV += segTree[idx].lazy1;
    
    if(l != r) {
        if(segTree[idx].lazy2 != -1) {
            segTree[idx<<1].lazy1 = 0;
            segTree[idx<<1].lazy2 = segTree[idx].lazy2;
            segTree[(idx<<1)|1].lazy1 = 0;
            segTree[(idx<<1)|1].lazy2 = segTree[idx].lazy2;
        }
        
        segTree[idx<<1].lazy1 += segTree[idx].lazy1;
        segTree[(idx<<1)|1].lazy1 += segTree[idx].lazy1;
    }
    
    segTree[idx].lazy1 = 0; segTree[idx].lazy2 = -1;
}

//두 노드를 합침
node merge(node &l, node &r) {
    return {l.value+r.value, min(l.minV, r.minV), max(l.maxV, r.maxV), 0, -1};
}

//초기 트리 생성
void buildTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = {A[l], A[l], A[l], 0, -1}; return;
    }
    
    int mid = (l+r)>>1;
    buildTree(l, mid, idx<<1); buildTree(mid+1, r, (idx<<1)|1);
    segTree[idx] = merge(segTree[idx<<1], segTree[(idx<<1)|1]);
}

//[l, r]에 대해 +X 적용
void updatePlus(int l, int r, int idx, int i, int j, int x) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].lazy1 += x;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)>>1;
    updatePlus(l, mid, idx<<1, i, j, x); updatePlus(mid+1, r, (idx<<1)|1, i, j, x);
    segTree[idx] = merge(segTree[idx<<1], segTree[(idx<<1)|1]);
}

//[l, r]에 대해 sqrt 적용
void updateSqrt(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        //[l, r]의 모든 원소가 동일한 값으로 변하는 경우
        if(floor(sqrt(segTree[idx].minV)) == floor(sqrt(segTree[idx].maxV))) {
            segTree[idx].lazy2 = floor(sqrt(segTree[idx].minV));
            propagate(l, r, idx);
            return;
        }
        //동잃한 값으로 변하지는 않으나 원래값의 최소, 최대의 차이가 1일 때
        //이 때는 sqrt를 아무리 취해도 최소, 최대의 간격이 변하지 않는다.(다시말하면 동일한 값만큼 값이 내려간다)
        else if(segTree[idx].minV+1 == segTree[idx].maxV) {
            segTree[idx].lazy1 += floor(sqrt(segTree[idx].minV))-segTree[idx].minV;
            propagate(l, r, idx);
            return;
        }
    }
    
    int mid = (l+r)>>1;
    updateSqrt(l, mid, idx<<1, i, j); updateSqrt(mid+1, r, (idx<<1)|1, i, j);
    segTree[idx] = merge(segTree[idx<<1], segTree[(idx<<1)|1]);
}

//sum(A_i, ..., A_j)
ll query(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx].value;
    
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, i, j)+query(mid+1, r, (idx<<1)|1, i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    buildTree(1, N, 1);
    
    int M; cin >> M;
    while(M--) {
        int q, l, r, x; cin >> q;
        switch(q) {
            case 1:
                cin >> l >> r >> x;
                updatePlus(1, N, 1, l, r, x);
                break;
            case 2:
                cin >> l >> r;
                updateSqrt(1, N, 1, l, r);
                break;
            case 3:
                cin >> l >> r;
                cout << query(1, N, 1, l, r) << '\n';
        }
    }

    return 0;
}