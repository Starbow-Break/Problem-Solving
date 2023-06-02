//#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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
vector<pii> tr[MAX]; //트리
int p[MAX][19] = {0, }, dep[MAX]; ll dist[MAX]; //sparse table, 깊이, 루트까지의 거리
bool inS[MAX] = {false, }, inT[MAX] = {false, }; //S 혹은 T에 속하는지 여부
int in[MAX]; //ETT
vector<pll> compTr[MAX]; //압축된 트리
ll dpS[MAX], dpT[MAX];

bool cmp(int &a, int &b) {
    return in[a] < in[b];
}

struct cmpq {
    bool operator()(pll &a, pll &b) {
        return a.x > b.x;
    }
};

//DFS
int ord = 0;
void dfs(int cur = 0, int prev = -1, ll depth = 0, ll distance = 0) {
    in[cur] = ++ord;
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

//트리 압축
void compress(vector<int> &vec) {
    //압축된 트리를 생성
    for(int i = 1; i < vec.size(); i++) {
        int per = lca(vec[i-1], vec[i]);
        compTr[per].push_back({vec[i], dist[vec[i]]-dist[per]});
        compTr[vec[i]].push_back({per, dist[vec[i]]-dist[per]});
    }
}

void dijkstraS(vector<int> &S) {
    fill(dpS, dpS+MAX, INF);
    priority_queue<pll, vector<pll>, cmpq> pq;
    for(auto &s: S) { pq.push({0, s}); dpS[s] = 0; } 
    
    while(!pq.empty()) {
        ll d = pq.top().x; int cur = pq.top().y; pq.pop();
        if(d > dpS[cur]) continue;
        
        for(auto &[next, w]: compTr[cur]) {
            if(d+w >= dpS[next]) continue;

            dpS[next] = d+w;
            pq.push({dpS[next], next});
        }
    }
}

void dijkstraT(vector<int> &T) {
    fill(dpT, dpT+MAX, INF);
    priority_queue<pll, vector<pll>, cmpq> pq;
    for(auto &t: T) { pq.push({0, t}); dpT[t] = 0; } 
    
    while(!pq.empty()) {
        ll d = pq.top().x; int cur = pq.top().y; pq.pop();
        if(d > dpT[cur]) continue;
        
        for(auto &[next, w]: compTr[cur]) {
            if(d+w >= dpT[next]) continue;
            
            dpT[next] = d+w;
            pq.push({dpT[next], next});
        }
    }
}

ll solve(vector<int> &S, vector<int> &T) {
    //다익스트라를 사용해서 dpS와 dpT를 구한다.
    dijkstraS(S); dijkstraT(T);
    
    ll ret = INF;
    for(int i = 0; i < N; i++) ret = min(ret, dpS[i]+dpT[i]);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    //트리 생성
    for(int i = 1; i < N; i++) {
        int a, b, w; cin >> a >> b >> w;
        tr[a].push_back({b, w}); tr[b].push_back({a, w});
    }
    
    //DFS 돌면서 원래 트리에서 필요한 값을 얻는다.
    dfs(); buildSparse();
    
    vector<int> S, T, ST; 
    while(M--) {
        //S 또는 T에 속하는 정점 받기
        int n, m; cin >> n >> m;
        for(int i = 0; i < n; i++) {
            int v; cin >> v;
            inS[v] = true; S.push_back(v); ST.push_back(v);
        }
        for(int i = 0; i < m; i++) {
            int v; cin >> v;
            inT[v] = true; T.push_back(v); ST.push_back(v);
        }
        
        //in[] 값 순으로 정렬, 이 후 인접한 점끼리의 lca를 구해서 넣는다.
        sort(ST.begin(), ST.end(), cmp);
        for(int i = 0; i < n+m-1; i++) {
            ST.push_back(lca(ST[i], ST[i+1]));
        }
        //재 정렬 후 중복 제거
        sort(ST.begin(), ST.end(), cmp);
        ST.erase(unique(ST.begin(), ST.end()), ST.end());
        
        compress(ST); //선별한 정점을 사용해서 트리 압축
        
        cout << solve(S, T) << '\n'; //압축된 트리에서 답을 구한다.
        
        //다음 테스트 케이스를 위해 초기화
        for(auto &s: S) inS[s] = false;
        for(auto &t: T) inT[t] = false;
        for(auto &v: ST) compTr[v].clear();
        S.clear(); T.clear(); ST.clear();
    }

    return 0;
}