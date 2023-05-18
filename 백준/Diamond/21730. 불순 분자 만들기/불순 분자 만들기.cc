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
#include <ctime>
#define MAX_N 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct node {
    int value, lazy;
};

int n, m, q;
int w[MAX_N+1], invIn[MAX_N+1];
int sz[MAX_N+1] = {0, }, top[MAX_N+1], parent[MAX_N+1], in[MAX_N+1], out[MAX_N+1], dep[MAX_N+1] = {0, };
vector<int> temp[MAX_N+1], edges[MAX_N+1];
vector<pii> microscope;

struct segTree{
    node sgTree[1 << 18];
    
    void initTree() {
        for(int i = 1; i < (1<<18); i++) sgTree[i] = {0, 0};
    }
    
    void propagate(int l, int r, int idx) {
        int lazy = sgTree[idx].lazy;
        
        if(l != r) {
            sgTree[idx<<1].lazy += lazy;
            sgTree[idx<<1|1].lazy += lazy;
        }
        
        sgTree[idx].value += (r-l+1)*lazy;
        sgTree[idx].lazy = 0;
    }
    
    node merge(node &a, node &b) {
        node ret;
        ret.value = a.value+b.value;
        ret.lazy = 0;
        return ret;
    }
    
    //노드의 value값을 1 증가
    void segUpdate(int l, int r, int idx, int i, int j, int v) {
        propagate(l, r, idx);
        
        if(r < i || j < l) return;
        
        if(i <= l && r <= j) {
            sgTree[idx].lazy += v;
            propagate(l, r, idx);
            return;
        }
        
        int mid = (l+r)>>1;
        segUpdate(l, mid, idx<<1, i, j, v); segUpdate(mid+1, r, idx<<1|1, i, j, v);
        sgTree[idx] = merge(sgTree[idx<<1], sgTree[idx<<1|1]);
    }
    
    //max값 구하기
    int segQuery(int l, int r, int idx, int i, int j) {
        propagate(l, r, idx);
        
        if(r < i || j < l) return 0;
        
        if(i <= l && r <= j) return sgTree[idx].value;
        
        int mid = (l+r)>>1;
        return segQuery(l, mid, idx<<1, i, j)+segQuery(mid+1, r, idx<<1|1, i, j);
    }
}segTreeV, segTreeE;

bool visited[MAX_N+1] = {false, }; 
void dfs(int cur = 1) {
    visited[cur] = true;
    
    for(auto &next: temp[cur]) {
        if(!visited[next]) {
            edges[cur].push_back(next);
            parent[next] = cur; dep[next] = dep[cur]+1;
            dfs(next);
        }
    }
}

void dfs1(int cur = 1) {
    sz[cur]++;
    
    for(auto &next: edges[cur]) {
        dfs1(next); sz[cur] += sz[next];
        if(sz[edges[cur][0]] < sz[next]) swap(edges[cur][0], next);
    }
}

int ord = 0;
void dfs2(int cur = 1) {
    in[cur] = ++ord; invIn[ord] = cur;
    
    for(auto &next: edges[cur]) {
        top[next] = (next == edges[cur][0] ? top[cur] : next);
        dfs2(next);
    }
    
    out[cur] = ord;
}

//전자가 지나가는 경로상에 존재하는 노드의 value를 1만큼 증가
void updateV(int a, int b) {
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        segTreeV.segUpdate(1, n, 1, in[top[a]], in[a], 1);
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    segTreeV.segUpdate(1, n, 1, in[a], in[b], 1);
}

//전자가 지나가는 경로상에 존재하는 간선의 value를 1만큼 증가
void updateE(int a, int b) {
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        segTreeE.segUpdate(1, n, 1, in[top[a]], in[a], 1);
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    segTreeE.segUpdate(1, n, 1, in[a], in[b], 1);
    segTreeE.segUpdate(1, n, 1, in[a], in[a], -1);
}

//경로상에 존재하는 모든 노드의 value의 합 구하기
ll queryV(int a, int b) {
    ll ret = 0;
    
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        ret += segTreeV.segQuery(1, n, 1, in[top[a]], in[a]);
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    ret += segTreeV.segQuery(1, n, 1, in[a], in[b]);
    
    return ret;
}

//경로상에 존재하는 모든 간선의 value의 합 구하기
ll queryE(int a, int b) {
    ll ret = 0;
    
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        ret += segTreeE.segQuery(1, n, 1, in[top[a]], in[a]);
        a = parent[top[a]];
    }
    
    if(dep[a] > dep[b]) swap(a, b);
    ret += segTreeE.segQuery(1, n, 1, in[a], in[b]);
    ret -= segTreeE.segQuery(1, n, 1, in[a], in[a]);
    
    return ret;
}

//전자의 경로 추가
void addElectron(int a, int b) {
    updateV(a, b); updateE(a, b);
}

//현미경의 실적 구하기
int getPerf(int num) {
    return queryV(microscope[num-1].first, microscope[num-1].second)
        -queryE(microscope[num-1].first, microscope[num-1].second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> q;
    
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        temp[a].push_back(b); temp[b].push_back(a);
    }
    
    top[1] = -1;
    dfs(); dfs1(); dfs2();
    
    segTreeV.initTree();
    segTreeE.initTree();
    
    while(m--) {
        int a, b; cin >> a >> b;
        microscope.push_back({a, b});
    }
    
    while(q--) {
        int i, x, y; cin >> i;
        
        if(i == 1) {
            cin >> x >> y;
            addElectron(x, y);
        }
        else {
            cin >> x;
            cout << getPerf(x) << '\n';
        }
    }

    return 0;
}