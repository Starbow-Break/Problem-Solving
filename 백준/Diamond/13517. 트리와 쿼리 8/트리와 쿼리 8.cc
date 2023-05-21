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
#define MAX 1'000'000

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

struct Node {
    Node *l, *r;
    int v;
    
    Node() {
        l = r = NULL; v = 0;
    }
};

int N; 
int w[100'001], parent[17][100'001] = {0, }, dep[100'001] = {0, };
vector<int> edges[100'001], dfsOrd;
Node* root[100'001];

bool visited[100'001] = {false, };
void dfs(int cur = 1) {
    visited[cur] = true;
    dfsOrd.push_back(cur);
    
    for(auto &next: edges[cur]) {
        if(!visited[next]) {
            parent[0][next] = cur;
            dep[next] = dep[cur]+1;
            dfs(next);
        }
    }
}

//희소배열 생성
void buildSparseTable() {
    dfs();
    for(int i = 1; i <= 16; i++) {
        for(int v = 1; v <= N; v++) {
            parent[i][v] = parent[i-1][parent[i-1][v]];
        }
    }
}

//조상 노드 찾기
int getAncestor(int v, int step) {
    int i = 0;
    while(step > 0) {
        if(step%2) v = parent[i][v];
        
        step /= 2; i++; 
    }
    
    return v;
}

//LCA 찾기
int lca(int a, int b) {
    int da = dep[a], db = dep[b];
    if(da-db > 0) a = getAncestor(a, da-db);
    else b = getAncestor(b, db-da);
    
    for(int i = 16; i >= -1; i--) {
        bool check = (i >= 0 ? parent[i][a] != parent[i][b] : a != b);
        
        if(check) {
            int idx = (i >= 0 ? i : 0);
            a = parent[idx][a]; b = parent[idx][b];
        }
    }
    
    return a;
}

//트리 초기화
void initTree(int l, int r, Node* cur) {
    if(l == r) { cur->v = 0; return; }
    
    int mid = l+r >> 1;
    cur->l = new Node(); cur->r = new Node();
    initTree(l, mid, cur->l); initTree(mid+1, r, cur->r);
    cur->v = cur->l->v + cur->r->v;
}

//트리 갱신
void update(int l, int r, Node* prev, Node* cur, int v) {
    if(l == r) { cur->v = prev->v+1; return; }
    
    int mid = l+r >> 1;
    if(v <= mid) {
        cur->l = new Node(); cur->r = prev->r;
        update(l, mid, prev->l, cur->l, v);
    }
    else {
        cur->l = prev->l; cur->r = new Node();
        update(mid+1, r, prev->r, cur->r, v);
    }
    
    cur->v = cur->l->v + cur->r->v;
}

int query(int l, int r, Node* cur, int i, int j) {
    if(r < i || j < l) return 0;
    if(i <= l && r <= j) return cur->v;
    
    int mid = l+r >> 1;
    return query(l, mid, cur->l, i, j)+query(mid+1, r, cur->r, i, j);
}

//PST 빌드
void buildPST() {
    root[0] = new Node();
    initTree(1, MAX, root[0]);
    
    for(auto &i: dfsOrd) {
        root[i] = new Node();
        update(1, MAX, root[parent[0][i]], root[i], w[i]);
    }
}

int solve(int a, int b, int k) {
    int l = lca(a, b);
    
    int i = 1, j = MAX;
    while(i <= j) {
        int mid = i+j >> 1;
        int q = query(1, MAX, root[a], 1, mid)+query(1, MAX, root[b], 1, mid)
            -query(1, MAX, root[l], 1, mid)-query(1, MAX, root[parent[0][l]], 1, mid);
        
        if(q >= k) j = mid-1;
        else i = mid+1;
    }
    
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> w[i];
    
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b); edges[b].push_back(a);
    }

    buildSparseTable();
    buildPST();
    
    int M; cin >> M;
    while(M--) {
        int a, b, k; cin >> a >> b >> k;
        cout << solve(a, b, k) << '\n';
    }

    return 0;
}