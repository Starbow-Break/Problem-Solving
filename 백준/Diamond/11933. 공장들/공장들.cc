//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#include <set>
#define x first
#define y second
#define MAX 500'000

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

const ll INF = 1'000'000'000'000'000'000;

int N, M; 
vector<pii> tr[MAX]; int centTr[MAX];
int p[MAX][19] = {0, }, sz[MAX], centTrRoot, dep[MAX]; ll dist[MAX];
bool factory[MAX] = {false, };
multiset<ll> distSet[MAX];
vector<int> vec, vec2;

void init() {
    fill(factory, factory+MAX, false);
    vec.clear(); vec2.clear();
}

//DFS
void dfs(int cur = 0, int prev = -1, ll depth = 0, ll distance = 0) {
    p[cur][0] = prev;
    dep[cur] = depth; dist[cur] = distance;
    for(auto &[next, w]: tr[cur]) {
        if(prev != next) dfs(next, cur, depth+1, distance+w);
    }
}

//lca 구할 때 사용할 희소 배열 생성
void buildSparse() {
    for(int i = 1; i < 19; i++) {
        for(int v = 0; v < N; v++) {
            if(p[v][i-1] == -1) p[v][i] = -1;
            else p[v][i] = p[p[v][i-1]][i-1];
        }
    }
}

int getParent(int v, int step) {
    int i = 0;
    while(step) {
        if(step&1) v = p[v][i];
        step >>= 1; i++;
    }
    return v;
}

//LCA
int lca(int a, int b) {
    int d = dep[a]-dep[b];
    if(d > 0) a = getParent(a, d);
    else b = getParent(b, -d);
    
    for(int i = 18; i >= -1; i--) {
        bool check = (i >= 0 ? p[a][i] != p[b][i] : a != b);
        if(check) {
            a = p[a][(i >= 0 ? i : 0)];
            b = p[b][(i >= 0 ? i : 0)];
        }
    }
    
    return a;
}

//두 노드 사이의 거리
ll getDist(int a, int b) {
    int l = lca(a, b);
    return dist[a]+dist[b]-2*dist[l];
}

bool visited[MAX] = {false, };
//서브트리의 크기 구하기
void getSize(int cur, int prev = -1) {
    sz[cur] = 1;
    for(auto &[next, w]: tr[cur]) {
        if(!visited[next] && prev != next) {
            getSize(next, cur);
            sz[cur] += sz[next];
        }
    }
}

//Centroid 구하기
int getCent(int cur, int prev, int size) {
    for(auto &[next, w]: tr[cur]) {
        //크기가 size/2보다 큰 서브트리가 있으면 그 쪽으로 이동
        if(!visited[next] && next != prev && sz[next] > size/2) {
            return getCent(next, cur, size);
        }
    }
    return cur; //없으면 자기 자신이 Centroid 
}

//Centroid Tree 생성
void buildCentTree(int cur = 0, int prev = -1) {
    getSize(cur);
    int cent = getCent(cur, -1, sz[cur]);
    visited[cent] = true;
    
    if(prev != -1) centTr[cent] = prev;
    else centTrRoot = cent;
    
    for(auto &[next, w]: tr[cent]) {
        if(!visited[next]) buildCentTree(next, cent);
    }
}

//x번 노드의 색 변경
void update(int x, bool v) {
    factory[x] = v; //색 변경
    int i = x;
    while(1) {
        ll d = getDist(i, x);
        if(factory[x]) distSet[i].insert(d);
        else distSet[i].erase(distSet[i].find(d));
        if(i == centTrRoot) break;
        i = centTr[i];
    }
}

//x번 노드와 가장 가까운 흰색 노드와의 거리
ll query(int x) {
    int i = x;
    ll ret = INF;
    while(1) {
        ll d = getDist(i, x);
        if(!distSet[i].empty()) {
            ret = min(ret, d+*distSet[i].begin());
        }
        if(i == centTrRoot) break;
        i = centTr[i];
    }
    if(ret == INF) return -1;
    else return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 1; i < N; i++) {
        int a, b, w; cin >> a >> b >> w;
        tr[a].push_back({b, w}); tr[b].push_back({a, w});
    }
    
    dfs(); buildSparse();
    buildCentTree();
    
    while(M--) {
        init();
        
        int s, t; cin >> s >> t;
        
        while(s--) {
            int v; cin >> v;
            vec.push_back(v);
        }
        while(t--) {
            int v; cin >> v;
            vec2.push_back(v);
            update(v, 1);
        }
        
        ll ans = INF;
        for(auto &v: vec) ans = min(ans, query(v));
        
        cout << ans << '\n';
        
        for(auto &v: vec2) update(v, 0);
    }

    return 0;
}