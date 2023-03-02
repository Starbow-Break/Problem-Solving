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
#define MAX_N 500'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N;
vector<int> edge[MAX_N+1];
int in[MAX_N+1], out[MAX_N+1], dep[MAX_N+1] = {0, }, segTree[1 << 20] = {0, };
int parent[MAX_N+1][20];

//ETT
int ord = 0;
void dfs(int cur = 1) {
    in[cur] = ++ord;
    for(auto &child: edge[cur]) {
        dep[child] = dep[cur]+1; parent[child][0] = cur;
        dfs(child);
    }
    out[cur] = ord;
}

//---------------------LCA---------------------
//희소 테이블 초기화
void buildTree() {
    parent[1][0] = -1;
    dfs();
    for(int i = 1; i < 20; i++) {
        for(int v = 1; v <= N; v++) {
            if(parent[v][i-1] == -1) parent[v][i] = -1;
            else parent[v][i] = parent[parent[v][i-1]][i-1];
        }
    }
}

int getParent(int v, int step) {
    int idx = 0;
    while(step > 0) {
        if(step%2) v = parent[v][idx];
        
        idx++; step /= 2;
    }
    
    return v;
}

int getLCA(int v1, int v2) {
    int d = dep[v1]-dep[v2];
    
    if(d > 0) v1 = getParent(v1, d);
    else v2 = getParent(v2, -d);
    
    for(int i = 19; i >= -1; i--) {
        bool check;
        if(i >= 0) check = parent[v1][i] != parent[v2][i];
        else check = v1 != v2;
        
        int idx = (i >= 0 ? i : 0);
        if(check) {
            v1 = parent[v1][idx]; v2 = parent[v2][idx];
        }
    }
    
    return v1;
}
//---------------------LCA---------------------

//----------------------------Segment Tree----------------------------
void update(int l, int r, int idx, int t, int x) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] = x; return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, t, x); update(mid+1, r, (idx<<1)|1, t, x);
    segTree[idx] = segTree[idx<<1]+segTree[(idx<<1)|1];
}

int query(int l, int r, int idx, int a, int b) {
    if(r < a || b < l) return 0;
    
    if(a <= l && r <= b) return segTree[idx];
    
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, a, b)+query(mid+1, r, (idx<<1)|1, a, b);
}
//----------------------------Segment Tree----------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 2; i <= N; i++) {
        int v; cin >> v;
        edge[v].push_back(i);
    }
    
    buildTree();
    
    int centroid;
    for(int i = 1; i <= N; i++) {
        update(1, N, 1, in[i], 1);
        
        if(i == 1) centroid = 1;
        else {
            int lca = getLCA(centroid, i);
            
            //centroid의 서브트리에 i번째 노드가 추가된 경우
            if(lca == centroid) {
                int t = getParent(i, dep[i]-dep[centroid]-1);
                int sz = query(1, N, 1, in[t], out[t]);
                if(sz > i/2) centroid = t;
            }
            //그 외
            else {
                int sz = query(1, N, 1, in[centroid], out[centroid]);
                if(sz <= i/2) centroid = parent[centroid][0];
            }
        }
        
        cout << centroid << ' ';
    }

    return 0;
}