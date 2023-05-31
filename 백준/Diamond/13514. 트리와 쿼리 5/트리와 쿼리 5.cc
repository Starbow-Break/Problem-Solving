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
#define MAX 100'000
#define INF 100'000'000

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

int N; 
vector<int> tr[MAX+1], centTr[MAX+1];
int p[MAX+1][17] = {0, }, sz[MAX+1], centTrRoot, dep[MAX+1];
bool isWhite[MAX+1] = {false, };
multiset<int> distSet[MAX+1];

//DFS
void dfs(int cur = 1, int prev = -1, int depth = 0) {
    p[cur][0] = prev;
    dep[cur] = depth;
    for(auto &next: tr[cur]) {
        if(prev != next) dfs(next, cur, depth+1);
    }
}

//lca 구할 때 사용할 희소 배열 생성
void buildSparse() {
    for(int i = 1; i <= 16; i++) {
        for(int v = 1; v <= N; v++) {
            if(p[v][i-1] == -1) p[v][i] = -1;
            else p[v][i] = p[p[v][i-1]][i-1];
        }
    }
}

int getParent(int v, int step) {
    int i = 0;
    while(step) {
        if(step%2) v = p[v][i];
        step /= 2; i++;
    }
    return v;
}

//LCA
int lca(int a, int b) {
    int d = dep[a]-dep[b];
    if(d > 0) a = getParent(a, d);
    else b = getParent(b, -d);
    
    for(int i = 16; i >= -1; i--) {
        bool check = (i >= 0 ? p[a][i] != p[b][i] : a != b);
        if(check) {
            a = p[a][(i >= 0 ? i : 0)];
            b = p[b][(i >= 0 ? i : 0)];
        }
    }
    
    return a;
}

//두 노드 사이의 거리
int getDist(int a, int b) {
    int l = lca(a, b);
    return dep[a]+dep[b]-2*dep[l];
}

bool visited[MAX+1] = {false, };
//서브트리의 크기 구하기
void getSize(int cur, int prev = -1) {
    sz[cur] = 1;
    for(auto &next: tr[cur]) {
        if(!visited[next] && prev != next) {
            getSize(next, cur);
            sz[cur] += sz[next];
        }
    }
}

//Centroid 구하기
int getCent(int cur, int prev, int size) {
    for(auto &next: tr[cur]) {
        //크기가 size/2보다 큰 서브트리가 있으면 그 쪽으로 이동
        if(!visited[next] && next != prev && sz[next] > size/2) {
            return getCent(next, cur, size);
        }
    }
    return cur; //없으면 자기 자신이 Centroid 
}

//Centroid Tree 생성
void buildCentTree(int cur = 1, int prev = -1) {
    getSize(cur);
    int cent = getCent(cur, -1, sz[cur]);
    visited[cent] = true;
    
    if(prev != -1) centTr[cent].push_back(prev);
    else centTrRoot = cent;
    
    for(auto &next: tr[cent]) {
        if(!visited[next]) buildCentTree(next, cent);
    }
}

//x번 노드의 색 변경
void query1(int x) {
    isWhite[x] = !isWhite[x]; //색 변경
    int i = x;
    while(1) {
        int d = getDist(i, x);
        if(isWhite[x]) distSet[i].insert(d);
        else distSet[i].erase(distSet[i].find(d));
        if(i == centTrRoot) break;
        i = centTr[i][0];
    }
}

//x번 노드와 가장 가까운 흰색 노드와의 거리
int query2(int x) {
    int i = x;
    int ret = INF;
    while(1) {
        int d = getDist(i, x);
        if(!distSet[i].empty()) {
            ret = min(ret, d+*distSet[i].begin());
        }
        if(i == centTrRoot) break;
        i = centTr[i][0];
    }
    if(ret == INF) return -1;
    else return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        tr[a].push_back(b); tr[b].push_back(a);
    }
    
    dfs(); buildSparse();
    buildCentTree();
    
    int M; cin >> M;
    while(M--) {
        int q, x; cin >> q >> x;
        if(q == 1) query1(x);
        else cout << query2(x) << '\n';
    }

    return 0;
}