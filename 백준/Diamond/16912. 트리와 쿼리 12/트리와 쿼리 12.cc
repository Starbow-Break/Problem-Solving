#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <cassert>
#define MAX_N 100'000
#define MAX_Q 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int INF = 1'000'000;

struct edge {
    int s, f, l, r;
};

struct node {
    int p, c, d;
};

int N, Q;
int parent[MAX_N+1], depth[MAX_N+1];

map<pii, int> mp;
vector<edge> edges;
int queryNum[MAX_Q+1]; bool ans[MAX_Q+1]; pii query[MAX_Q+1];
vector<pii> segTree[270000];

void update(int i, int j, int idx, int l, int r, pii e) {
    if(j < l || r < i) return;
    
    if(l <= i && j <= r) {
        segTree[idx].push_back(e); return;
    }
    
    int mid = (i+j)>>1;
    update(i, mid, idx<<1, l, r, e); update(mid+1, j, (idx<<1)|1, l, r, e);
}

stack<node> s;

int findRoot(int v) {
    if(v == parent[v]) return v;
    
    return findRoot(parent[v]);
}

bool unionSet(int v1, int v2) {
    int r1 = findRoot(v1); int r2 = findRoot(v2);
    
    if(r1 == r2) return false;
    
    if(depth[r1] < depth[r2]) swap(r1, r2);
    parent[r2] = r1;
    
    if(depth[r1] == depth[r2]) {
        depth[r1]++;
        s.push({r1, r2, 1});
    }
    else {
        s.push({r1, r2, 0});
    }
    
    return true;
}

bool sameSet(int v1, int v2) {
    return findRoot(v1) == findRoot(v2);
}

void deleteEdge(int cnt) {
    while(cnt--) {
        node n = s.top(); s.pop();
        
        parent[n.c] = n.c;
        if(n.d == 1) depth[n.p]--;
    }
}

void solve(int i, int j, int idx) {
    int cnt = 0; //[i, j]시간대에서 추가로 생성된 간선의 수
    for(auto &e: segTree[idx]) {
        cnt += unionSet(e.first, e.second);
    }
    
    //i == j인 경우 i시간대의 포레스트 상태을 얻을 수 있으므로 ans[i]를 업데이트 한다.
    if(i == j) {
        if(queryNum[i] == 3)
            ans[i] = sameSet(query[i].first, query[i].second);
            
        deleteEdge(cnt);
        return;
    }
    
    int mid = (i+j)>>1;
    solve(i, mid, idx<<1); solve(mid+1, j, (idx<<1)|1);
    deleteEdge(cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q; int cnt = 0;
    for(int i = 1; i <= N; i++) {parent[i] = i; depth[i] = 0;}
    
    for(int i = 1; i <= Q; i++) {
        int q, a, b; cin >> q >> a >> b;
        queryNum[i] = q;
        if(a > b) swap(a, b);
        
        if(q == 1) {
            auto t = mp.find({a, b});
            if(t == mp.end()) mp.insert({{a, b}, cnt});
            else t->second = cnt;
            cnt++;
            
            edges.push_back({a, b, i, INF});
        }
        if(q == 2) {
            int j = mp.find({a, b})->second;
            edges[j].r = i-1;
        }
        if(q == 3) {
            query[i] = {a, b};
        }
    }
    
    for(auto &e: edges) {
        update(1, Q, 1, e.l, e.r, {e.s, e.f});
    }
    
    solve(1, Q, 1);
    
    for(int i = 1; i <= Q; i++) {
        if(queryNum[i] == 3) cout << ans[i] << '\n';
    }

    return 0;
}