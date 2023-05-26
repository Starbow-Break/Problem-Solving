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

const int INF = 1'000'000'000;

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.first > b.first;
    }
};

vector<pii> edges[100'001], vec, queries;
vector<int> festival, val;
int arr[100'000][2];
int parent[100'001], invComp[100'000];

bool cmp1(int a, int b) {
    return (arr[a][0]+arr[a][1])/2 < (arr[b][0]+arr[b][1])/2;
}

int findRoot(int v) {
    if(v == parent[v]) return v;
    
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a), rb = findRoot(b);
    if(ra > rb) swap(ra, rb);
    
    parent[rb] = ra;
}

bool sameSet(int a, int b) {
    return findRoot(a) == findRoot(b);
}

void init(int N) {
    for(int i = 1; i <= N; i++) parent[i] = i;
}

int d[100'001] = {0, };
void dijkstra() {
    priority_queue<pii, vector<pii>, cmp> pq;
    
    for(auto &f: festival) {
        d[f] = 0; pq.push({0, f});
    }
    
    while(!pq.empty()) {
        int cur = pq.top().second; int dist = pq.top().first; pq.pop();
        if(d[cur] < dist) continue;
        
        for(auto &e: edges[cur]) {
            if(d[e.first] > d[cur]+e.second) {
                pq.push({d[cur]+e.second, e.first});
                d[e.first] = d[cur]+e.second;
            }
        }
    }
}

void compress() {
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    
    for(auto &v: vec) {
        int t = lower_bound(val.begin(), val.end(), v.first)-val.begin();
        invComp[t] = v.first; v.first = t; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    
    while(M--) {
        int a, b, w; cin >> a >> b >> w;
        edges[a].push_back({b, w}); edges[b].push_back({a, w});
    }
    
    while(K--) {
        int v; cin >> v;
        festival.push_back(v);
    }
    
    for(int q = 0; q < Q; q++) {
        int a, b; cin >> a >> b;
        queries.push_back({a, b});
    }
    
    fill(d, d+100'001, INF);
    dijkstra(); //다익스트라로 각 노드별로 축제도시와의 거리 중 최솟값을 구함
    
    for(int i = 1; i <= N; i++) {
        vec.push_back({d[i], i});
        val.push_back(d[i]);
    }
    
    compress(); //좌표압축
    sort(vec.rbegin(), vec.rend()); //거리가 큰 순서대로 정렬
    
    for(int q = 0; q < Q; q++) { arr[q][0] = 0; arr[q][1] = val.size()-1; }
    
    bool visited[100'001]; vector<int> ord[100'000];
    for(int i = 0; i < Q; i++) {
        ord[(arr[i][0]+arr[i][1])/2].push_back(i);
    }
    
    queue<pii> que;
    while(1) {
        bool flag = false; int idx = 0;
        fill(visited, visited+100'001, false);
        init(N);
        
        for(int mid = val.size()-1; mid >= 0; mid--) {
            for(auto &q: ord[mid]) {
                flag = true;
                    
                while(idx < vec.size() && vec[idx].first >= mid) {
                    visited[vec[idx].second] = true;
                    for(auto &p: edges[vec[idx].second]) {
                        int next = p.first;
                        if(visited[next]) merge(vec[idx].second, next);
                    }
                    idx++;
                }
                    
                if(sameSet(queries[q].first, queries[q].second)) arr[q][0] = mid+1;
                else arr[q][1] = mid-1;
                    
                if(arr[q][0] <= arr[q][1]) que.push({(arr[q][0]+arr[q][1])/2, q});
            }
            
            ord[mid].clear();
        }
        
        while(!que.empty()) {
            pii p = que.front(); que.pop();
            ord[p.first].push_back(p.second);
        }
        
        if(!flag) break; //이분 탐색이 전부 끝나면 종료
    }
    
    for(int q = 0; q < Q; q++) cout << invComp[arr[q][1]] << '\n';

    return 0;
}