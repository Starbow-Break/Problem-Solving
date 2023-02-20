#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX_V 50'000
#define MAX_E 200'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

struct edge {
    int s, f, w;
    
    bool operator<(edge &e) {
        return w < e.w;
    }
};

const ll INF = 1'000'000'000'000'000'000;

int V, E;
vector<edge> edges;
bool isUsed[MAX_E] = {false, };
vector<pii> mst[MAX_V+1]; int len = 0;

int parent[MAX_V+1], dep[MAX_V+1] = {0, };
int p[16][MAX_V+1]; pii maxW[16][MAX_V+1];

//루트노드 찾기
int findRoot(int v) {
    if(v == parent[v]) return v;
    
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

//v1과 v2가 같은 집합에 속한지 여부
bool inSameSet(int v1, int v2) {
    return findRoot(v1) == findRoot(v2);
}

//v1과 v2가 속한 집합을 합침
void unionSet(int v1, int v2) {
    int r1 = findRoot(v1), r2 = findRoot(v2);
    
    if(r1 > r2) swap(r1, r2);
    parent[r2] = r1;
}

//MST 생성
bool makeMST() {
    sort(edges.begin(), edges.end());
    
    int cnt = 0; int idx = 0;
    while(cnt < V-1 && idx < E) {
        int s = edges[idx].s, f = edges[idx].f, w = edges[idx].w;
        if(!inSameSet(s, f)) {
            unionSet(s, f);
            mst[s].push_back({f, w}); mst[f].push_back({s, w});
            isUsed[idx] = true;
            cnt++; len += w;
        }
        
        idx++;
    }
    
    return (cnt == V-1);
}

//MST에서 DFS
bool visited[MAX_V+1] = {false, };
void dfs(int cur = 1) {
    visited[cur] = true;
    
    for(auto &next: mst[cur]) {
        if(!visited[next.first]) {
            dep[next.first] = dep[cur]+1;
            p[0][next.first] = cur; maxW[0][next.first] = {next.second, -1};
            dfs(next.first);
        }
    }
}

pii merge(pii a, pii b) {
    vector<int> values;
    values.push_back(-a.first);
    values.push_back(-a.second);
    values.push_back(-b.first);
    values.push_back(-b.second);
                
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    
    return {-values[0], -values[1]};
}

//MST에 대한 희소 테이블 생성
void buildTable() {
    for(int i = 0; i < 16; i++) {
        fill(p[i], p[i]+V+1, 0);
        for(int v = 1; v <= V; v++) {
            maxW[i][v] = {-1, -1};
        }
    }
    
    dfs();
    
    for(int i = 1; i < 16; i++) {
        for(int v = 1; v <= V; v++) {
            if(p[i-1][v])
                p[i][v] = p[i-1][p[i-1][v]];
            else 
                p[i][v] = 0;
                
            if(p[i][v]) {
                maxW[i][v] = merge(maxW[i-1][v], maxW[i-1][p[i-1][v]]);
            }
        }
    }
}

//v의 step 단계 위의 부모와 둘 사이를 연결하는 경로 상의 최대 간선 반환
pair<int, pii> getParent(int v, int step) {
    pii w = {-1, -1}; int idx = 0;
    
    while(step > 0) {
        if(step%2) {
            w = merge(w, maxW[idx][v]);
            v = p[idx][v];
        }
        
        step /= 2; idx++;
    }
    
    return {v, w};
}

//v1과 v2 사이의 최단 경로에서 가중치가 가장 큰 간선의 가중치를 반환
pii findMaxEdgeInRoute(int v1, int v2) {
    pii ret = {-1, -1}; 
    int d = dep[v1]-dep[v2];
    
    if(d > 0) {
        pair<int, pii> p = getParent(v1, d);
        v1 = p.first; ret = merge(ret, p.second);
    }
    else {
        pair<int, pii> p = getParent(v2, -d);
        v2 = p.first; ret = merge(ret, p.second);
    }
    
    for(int i = 15; i >= -1; i--) {
        bool ch;
        if(i >= 0) ch = p[i][v1] != p[i][v2];
        else ch = v1 != v2;
        
        int idx = (i >= 0) ? i : 0;
        if(ch) {
            ret = merge(ret, maxW[idx][v1]);
            ret = merge(ret, maxW[idx][v2]);
            v1 = p[idx][v1]; v2 = p[idx][v2];
        }
    }
    
    return ret;
}

//문제 해결
ll solve() {
    //MST 생성
    if(!makeMST()) return -1;
    
    //희소 테이블 생성
    buildTable();
    
    ll ret = INF;
    
    for(int i = 0; i < E; i++) {
        if(!isUsed[i] && edges[i].s != edges[i].f) {
            int w = edges[i].w;
            pii ww = findMaxEdgeInRoute(edges[i].s, edges[i].f);
            
            if(ww.first == w && ww.second == w) continue;
            
            if(ww.first == w) {
                if(ww.second != -1) ret = min(ret, 0LL+len+w-ww.second);
            }
            else 
                ret = min(ret, 0LL+len+w-ww.first);
        }
    }
    
    return (ret == INF) ? -1 : ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> V >> E;
    
    for(int i = 1; i <= V; i++) parent[i] = i;
    for(int i = 0; i < E; i++) {
        int s, f, w; cin >> s >> f >> w;
        edges.push_back({s, f, w});
    }
    
    cout << solve() << '\n';
    //cout << "MST : " << len;

    return 0;
}