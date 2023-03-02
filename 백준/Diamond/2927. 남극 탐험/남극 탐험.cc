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
#define MAX_N 30'000
#define MAX_Q 300'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct query {
    string name; int a, b;
};

int N; 
int root[MAX_N+1];
int w[MAX_N+1];
vector<query> queries;
vector<int> temp[MAX_N+1], tree[MAX_N+1]; int ans[MAX_N+1];
int parent[MAX_N+1], dep[MAX_N+1], sz[MAX_N+1], top[MAX_N+1], in[MAX_N+1], out[MAX_N+1];
int segTree1[1 << 16]; bool segTree2[1 << 16];

//------------------Union-Find--------------------
int findRoot(int v) {
    if(v == root[v])  return v;
    
    root[v] = findRoot(root[v]);
    return root[v];
}

void unionSet(int v1, int v2) {
    int r1 = findRoot(v1); int r2 = findRoot(v2);
    
    if(r1 > r2) swap(r1, r2);
    root[r2] = r1;
}

bool inSameSet(int v1, int v2) {
    return findRoot(v1) == findRoot(v2);
}
//------------------Union-Find--------------------

//----------------------DFS-----------------------
//단방향 그래프 생성, parent, dep, sz 초기화
bool visited[MAX_N+1] = {false, };
void dfs1(int cur = 1) {
    visited[cur] = true; sz[cur] = 1;
    for(auto &child: temp[cur]) {
        if(!visited[child]) {
            tree[cur].push_back(child);
            parent[child] = cur; dep[child] = dep[cur]+1;
            dfs1(child);
            sz[cur] += sz[child];
        }
    }
}

//heavy edge를 먼저 방문할 수 있도록 설정해준다.
void dfs2(int cur = 1) {
    for(auto &child: tree[cur]) {
        if(sz[tree[cur][0]] < sz[child]) swap(child, tree[cur][0]);
        dfs2(child);
    }
}

//ETT로 in, out 그리고 top 초기화
int ord = 0;
void dfs3(int cur = 1) {
    in[cur] = ++ord;
    for(auto &child: tree[cur]) {
        top[child] = (child == tree[cur][0] ? top[cur] : child);
        dfs3(child);
    }
    out[cur] = ord;
}
//----------------------DFS-----------------------

//------------------Segment Tree------------------
void update1(int l, int r, int idx, int a, int x) {
    if(r < a || a < l) return;
    
    if(l == r) {
        segTree1[idx] = x;
        return;
    }
    
    int mid = (l+r)>>1;
    update1(l, mid, idx<<1, a, x); update1(mid+1, r, (idx<<1)|1, a, x);
    segTree1[idx] = segTree1[idx<<1]+segTree1[(idx<<1)|1];
}

void init1() {
    for(int i = 1; i <= N; i++) {
        update1(1, N, 1, in[i], w[i]);
    }
}


int query1(int l, int r, int idx, int a, int b) {
    if(r < a || b < l) return 0;
    
    if(a <= l && r <= b) return segTree1[idx];
    
    int mid = (l+r)>>1;
    return query1(l, mid, idx<<1, a, b)+query1(mid+1, r, (idx<<1)|1, a, b);
}

void init2() {
    fill(segTree2+1, segTree2+(1<<16), false);
}

void update2(int l, int r, int idx, int a, bool x) {
    if(r < a || a < l) return;
    
    if(l == r) {
        segTree2[idx] = x;
        return;
    }
    
    int mid = (l+r)>>1;
    update2(l, mid, idx<<1, a, x); update2(mid+1, r, (idx<<1)|1, a, x);
    segTree2[idx] = segTree2[idx<<1] && segTree2[(idx<<1)|1];
}

bool query2(int l, int r, int idx, int a, int b) {
    if(a > b || (r < a || b < l)) return true;
    
    if(a <= l && r <= b) return segTree2[idx];
    
    int mid = (l+r)>>1;
    return query2(l, mid, idx<<1, a, b) && query2(mid+1, r, (idx<<1)|1, a, b);
}
//------------------Segment Tree------------------

//--------------------Queries---------------------
bool bridge(int a, int b) {
    if(inSameSet(a, b)) return false;
    
    unionSet(a, b);
    if(dep[a] < dep[b]) swap(a, b);
    update2(1, N, 1, in[a], true);
    return true;
}

void penguins(int a, int x) {
    update1(1, N, 1, in[a], x);
}

bool hasRoute(int a, int b) {
    bool check = true;
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        check = check && query2(1, N, 1, in[top[a]], in[a]);
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    check = check && query2(1, N, 1, in[a]+1, in[b]);
    
    return check;
}

int excursion(int a, int b) {
    int ret = 0;
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        ret += query1(1, N, 1, in[top[a]], in[a]);
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    ret += query1(1, N, 1, in[a], in[b]);
    
    return ret;
}
//--------------------Queries---------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) root[i] = i;
    for(int i = 1; i <= N; i++) cin >> w[i];
    
    int Q; cin >> Q;
    while(Q--) {
        string s; int a, b; cin >> s >> a >> b;
        queries.push_back({s, a, b});
        
        if(s == "bridge") {
            if(!inSameSet(a, b)) {
                unionSet(a, b);
                temp[a].push_back(b); temp[b].push_back(a);
            }
        }
    }
    
    for(int i = 1; i <= N; i++) {
        if(!inSameSet(1, i)) {
            temp[1].push_back(i); temp[i].push_back(1);
        }
    }
    
    //HLD 수행 전에 dfs로 필요한 정보를 얻는다.
    parent[1] = -1; dep[1] = 0; top[1] = 1;
    dfs1(); dfs2(); dfs3();
    
    init1(); init2();
    
    for(int i = 1; i <= N; i++) root[i] = i;
    for(auto &q: queries) {
        //다리 연결
        if(q.name == "bridge") cout << (bridge(q.a, q.b) ? "yes" : "no") << '\n';
        //펭귄 수 업데이트
        if(q.name == "penguins") penguins(q.a, q.b);
        //경로가 존재한지 확인 후 전체 펭귄 수 구하기
        if(q.name == "excursion") {
            if(hasRoute(q.a, q.b)) cout << excursion(q.a, q.b) << '\n';
            else cout << "impossible" << '\n';
        }
    }

    return 0;
}