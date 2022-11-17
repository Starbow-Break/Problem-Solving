#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

const int M = 1048575;

struct treeNode {
    int maxValue; //노드에 해당하는 범위의 최댓값
    int andTotal; //노드에 해당하는 범위의 수들을 전부 AND 연산한 값
    int orTotal; //노드에 해당하는 범위의 수들을 전부 OR 연산한 값
    int lazy = 0; //lazy propagation
};

int arr[200001]; //초기 데이터
treeNode segTree[1050000]; //세그먼트 트리

//트리 초기화
void initTree(int s, int f, int idx) {
    if(s == f) {
        segTree[idx].maxValue = segTree[idx].andTotal = segTree[idx].orTotal = arr[s];
        return;
    }
    
    int mid = (s+f)>>1;
    initTree(s, mid, idx<<1); initTree(mid+1, f, (idx<<1)|1);
    segTree[idx].maxValue = max(segTree[idx<<1].maxValue, segTree[(idx<<1)|1].maxValue);
    segTree[idx].andTotal = segTree[idx<<1].andTotal & segTree[(idx<<1)|1].andTotal;
    segTree[idx].orTotal = segTree[idx<<1].orTotal | segTree[(idx<<1)|1].orTotal;
}

//x에서 자릿수가 0인 모든 자리에서 노드에 속한 모든 값이 동일한 자리에서 자릿수가 1이면 true
bool andLazy(int idx, int x) {
    return (~x & segTree[idx].andTotal) == (~x & M);
}

//x에서 자릿수가 1인 모든 자리에서 노드에 속한 모든 값이 동일한 자리에서 자릿수가 0이면 true
bool orLazy(int idx, int x) {
    return (x & ~segTree[idx].orTotal) == x;
}

//AND query
void query1(int s, int f, int idx, int l, int r, int x) {
    //갱신이 필요한 노드인 경우
    if(segTree[idx].lazy != 0) {
        segTree[idx].maxValue += segTree[idx].lazy;
        segTree[idx].andTotal += segTree[idx].lazy;
        segTree[idx].orTotal += segTree[idx].lazy;
        
        if(s < f) {
            segTree[idx<<1].lazy += segTree[idx].lazy;
            segTree[(idx<<1)|1].lazy += segTree[idx].lazy;
        }
        
        segTree[idx].lazy = 0;
    }
    
    if(f < l || r < s) { return; }
    
    x += ((~x & ~segTree[idx].orTotal) & M);
    
    if(l <= s && f <= r) {
        if(andLazy(idx, x)) { //AND query에서 lazy값을 저장해야 하는 경우
            segTree[idx].maxValue -= (M-x);
            segTree[idx].andTotal -= (M-x);
            segTree[idx].orTotal -= (M-x);
            
            //자식 노드도 동일한 작업을 수행함. lazy에 저장한 후 추후 갱신
            segTree[idx<<1].lazy -= (M-x);
            segTree[(idx<<1)|1].lazy -= (M-x);
            return;
        }
    }
    
    if(x == M) return;
    
    int mid = (s+f) >> 1;
    query1(s, mid, idx<<1, l, r, x);
    query1(mid+1, f, (idx<<1)|1, l, r, x);
    segTree[idx].maxValue = max(segTree[idx<<1].maxValue, segTree[(idx<<1)|1].maxValue);
    segTree[idx].andTotal = segTree[idx<<1].andTotal & segTree[(idx<<1)|1].andTotal;
    segTree[idx].orTotal = segTree[idx<<1].orTotal | segTree[(idx<<1)|1].orTotal;
}

//OR query
void query2(int s, int f, int idx, int l, int r, int x) {
    //갱신이 필요한 노드인 경우
    if(segTree[idx].lazy != 0) {
        segTree[idx].maxValue += segTree[idx].lazy;
        segTree[idx].andTotal += segTree[idx].lazy;
        segTree[idx].orTotal += segTree[idx].lazy;
        
        if(s < f) {
            segTree[idx<<1].lazy += segTree[idx].lazy;
            segTree[(idx<<1)|1].lazy += segTree[idx].lazy;
        }
        
        segTree[idx].lazy = 0;
    }
    
    if(f < l || r < s) return;
    
    x -= (x & segTree[idx].andTotal);
    
    if(l <= s && f <= r) {
        if(orLazy(idx, x)) { //OR query에서 lazy값을 저장해야 하는 경우
            segTree[idx].maxValue += x;
            segTree[idx].andTotal += x;
            segTree[idx].orTotal += x;
            
            //자식 노드도 동일한 작업을 수행함. lazy에 저장한 후 추후 갱신
            segTree[idx<<1].lazy += x;
            segTree[(idx<<1)|1].lazy += x;
            return;
        }
    }
    
    if(x == 0) return;
    
    int mid = (s+f) >> 1;
    query2(s, mid, idx<<1, l, r, x);
    query2(mid+1, f, (idx<<1)|1, l, r, x);
    segTree[idx].maxValue = max(segTree[idx<<1].maxValue, segTree[(idx<<1)|1].maxValue);
    segTree[idx].andTotal = segTree[idx<<1].andTotal & segTree[(idx<<1)|1].andTotal;
    segTree[idx].orTotal = segTree[idx<<1].orTotal | segTree[(idx<<1)|1].orTotal;
}

//MAX query
int query3(int s, int f, int idx, int l, int r) {
    //갱신이 필요한 노드인 경우
    if(segTree[idx].lazy != 0) {
        segTree[idx].maxValue += segTree[idx].lazy;
        segTree[idx].andTotal += segTree[idx].lazy;
        segTree[idx].orTotal += segTree[idx].lazy;
        
        if(s < f) {
            segTree[idx<<1].lazy += segTree[idx].lazy;
            segTree[(idx<<1)|1].lazy += segTree[idx].lazy;
        }
        
        segTree[idx].lazy = 0;
    }
    
    if(f < l || r < s) return 0;
    
    if(l <= s && f <= r) return segTree[idx].maxValue;
    
    int mid = (s+f) >> 1;
    int L = query3(s, mid, idx<<1, l, r);
    int R = query3(mid+1, f, (idx<<1)|1, l, r);
    return max(L, R);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) { cin >> arr[i]; }
    
    initTree(1, N, 1); //세그먼트 트리 초기화
    
    int M; cin >> M;
    while(M--) {
        int q; cin >> q;
        if(q == 1) { //ans 연산
            int l, r, x; cin >> l >> r >> x;
            query1(1, N, 1, l, r, x);
        }
        if(q == 2) { //or 연산
            int l, r, x; cin >> l >> r >> x;
            query2(1, N, 1, l, r, x);
        }
        if(q == 3) { //max값 출력
            int l, r; cin >> l >> r;
            cout << query3(1, N, 1, l, r) << '\n';
        }
    }

    return 0;
}