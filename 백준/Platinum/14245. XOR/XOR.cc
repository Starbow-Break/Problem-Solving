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

// 세그트리의 노드
struct Node {
    int value, lazy;
};

int arr[500000]; //수열

Node segTree[1 << 20]; //세그트리

//노드 갱신
void propagate(int l, int r, int idx) {
    if(l != r) {
        segTree[idx<<1].lazy ^= segTree[idx].lazy;
        segTree[idx<<1|1].lazy ^= segTree[idx].lazy;
    }
    
    segTree[idx].value ^= segTree[idx].lazy;
    segTree[idx].lazy = 0;
}

//세그트리 업데이트
void update(int l, int r, int idx, int i, int j, int v) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].lazy ^= v;
        propagate(l, r, idx);
        return;
    }
    
    int mid = l+r >> 1;
    update(l, mid, idx<<1, i, j, v);
    update(mid+1, r, idx<<1|1, i, j, v);
}

//특정 요소에 적용해야 할 xor 값 구하기
int query(int l, int r, int idx, int t) {
    propagate(l, r, idx);
    
    if(r < t || t < l) return 0;
    
    if(l == r) return segTree[idx].value;
    
    int mid = l+r >> 1;
    return query(l, mid, idx<<1, t)^query(mid+1, r, idx<<1|1, t);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 1; i < 1 << 20; i++) {
        segTree[i] = {0, 0};
    }
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    int Q; cin >> Q;
    while(Q--) {
        int q; cin >> q;
        if(q == 1) {
            int a, b, c; cin >> a >> b >> c;
            update(0, N-1, 1, a, b, c);
        }
        else {
            int a; cin >> a;
            int value = query(0, N-1, 1, a);
            cout << (arr[a]^value) << '\n';
        }
    }
    
    return 0;
}
