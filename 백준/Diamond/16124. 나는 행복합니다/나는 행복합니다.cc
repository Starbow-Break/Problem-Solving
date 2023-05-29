#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
#define x first
#define y second
#define MOD 998'244'353

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

struct Node {
    ll value[10], lazy[10];
    int len;
    
    Node() {
        for(int i = 0; i < 10; i++) {
            value[i] = 0; lazy[i] = i;
        }
        len = 0;
    }
    
    ll getValue() {
        ll ret = 0;
        for(int i = 0; i < 10; i++) {
            ret += value[i]*i; ret %= MOD;
        }
        return ret;
    }
};

ll powTen[1'000'000];
Node segTree[1 << 21];

//노드 갱신
void propagate(int l, int r, int idx) {
    //lazy 전파
    if(l != r) {
        for(int i = 0; i < 10; i++) {
            segTree[idx<<1].lazy[i] = segTree[idx].lazy[segTree[idx<<1].lazy[i]];
            segTree[idx<<1|1].lazy[i] = segTree[idx].lazy[segTree[idx<<1|1].lazy[i]];
        }
    }
    
    //노드 갱신 및 lazy 초기화
    ll temp[10] = {0, };
    for(int i = 0; i < 10; i++) {
        temp[segTree[idx].lazy[i]] += segTree[idx].value[i];
        temp[segTree[idx].lazy[i]] %= MOD;
    }
    
    for(int i = 0; i < 10; i++) {
        segTree[idx].value[i] = temp[i];
        segTree[idx].lazy[i] = i;
    }
}

//두 노드 합치기
Node merge(Node &a, Node &b) {
    Node ret = Node();
    for(int i = 0; i < 10; i++) {
        ret.value[i] = (a.value[i]*powTen[b.len]%MOD+b.value[i])%MOD;
    }
    ret.len = a.len+b.len;
    
    return ret;
}

//세그먼트 트리 설정
void buildTree(int l, int r, int idx, string &s) {
    if(l == r) {
        segTree[idx] = Node();
        segTree[idx].value[s[l-1]-'0'] = 1;
        segTree[idx].len = 1;
        return;
    }
    
    int mid = l+r>>1;
    buildTree(l, mid, idx<<1, s); buildTree(mid+1, r, idx<<1|1, s);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

//시그먼트 트리 갱신
void segUpdate(int l, int r, int idx, int i, int j, int from, int to) {
    propagate(l, r, idx); //해당 노드 먼저 갱신
    
    if(r < i || j < l) return;
    if(i <= l && r <= j) {
        segTree[idx].lazy[from] = to;
        
        //노드 갱신 및 lazy 전파
        propagate(l, r, idx);
        return;
    }
    
    int mid = l+r>>1;
    segUpdate(l, mid, idx<<1, i, j, from, to);
    segUpdate(mid+1, r, idx<<1|1, i, j, from, to);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

//[i..j] 정수 값 구하기
Node segQuery(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx); //해당 노드 먼저 갱갱신
    
    if(r < i || j < l) return Node();
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = l+r>>1;
    Node a = segQuery(l, mid, idx<<1, i, j);
    Node b = segQuery(mid+1, r, idx<<1|1, i, j);
    return merge(a, b);
}

void init(string s) {
    buildTree(1, s.length(), 1, s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    powTen[0] = 1;
    for(int i = 1; i < 1'000'000; i++) {
        powTen[i] = powTen[i-1]*10; powTen[i] %= MOD;
    }
    
    string pw; cin >> pw;
    int sz = pw.length();
    init(pw);
    
    int Q; cin >> Q;
    while(Q--) {
        int q, i, j, from, to; cin >> q;
        if(q == 1) {
            cin >> i >> j >> from >> to;
            segUpdate(1, sz, 1, i, j, from, to);
        }
        else {
            cin >> i >> j;
            cout << segQuery(1, sz, 1, i, j).getValue() << '\n';
        }
    }
    
    return 0;
}