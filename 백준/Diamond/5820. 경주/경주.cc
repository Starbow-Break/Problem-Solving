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

struct edge {
    int v, w;
};

int N, K; 
int sz[200'000]; //서브트리의 크기
bool visited[200'000] = {false, }; //Centroid로 사용 여부
vector<edge> edges[200'000];

//서브트리의 사이즈 얻기
int getSize(int cur, int prev = -1) {
    sz[cur] = 1;
    for(auto &e: edges[cur]) {
        int next = e.v;
        if(next != prev && !visited[next]) sz[cur] += getSize(next, cur);
    }
    
    return sz[cur];
}

//Centroid 얻기
int getCent(int cur, int prev, int size) {
    for(auto &e: edges[cur]) {
        int next = e.v, w = e.w;
        //크기가 size/2를 넘는 서브 트리가 있으면 그쪽으로 이동
        if(next != prev && !visited[next] && sz[next] > size/2) return getCent(next, cur, size);
    }
    
    //없으면 현재 정점이 Centroid가 된다.
    return cur;
}

int minRoad[1'000'001];
vector<pii> temp; vector<int> visit; 

void dfs(int cur, int d, int prev = -1, int dep = 1) {
    if(d > K) return;
    
    temp.push_back({d, dep});
    
    for(auto &e: edges[cur]) {
        int next = e.v, w = e.w;
        if(next != prev && !visited[next]) {
            dfs(next, d+w, cur, dep+1);
        }
    }
}

//Centroid를 중심으로 Divide and Conquer
int dnc(int cur) {
    int cent = getCent(cur, -1, getSize(cur)); //Centroid를 얻는다.
    visited[cent] = true; //해당 정점이 Centroid로 사용됐음을 표시
    
    int ret = INF;
    for(auto &e: edges[cent]) {
        int next = e.v, w = e.w; 
        if(!visited[next]) {
            dfs(next, w); //서브트리 탐색
            for(auto &p: temp) { //다른 서브트리의 결과를 사용해서 ans를 업데이트
                if(K-p.first >= 0) ret = min(ret, minRoad[K-p.first]+p.second);
            }
            for(auto &p: temp) { //해당 서브트리 반영
                minRoad[p.first] = min(minRoad[p.first], p.second);
                visit.push_back(p.first);
            }
            temp.clear();
        }
    }
    
    for(auto &v: visit) minRoad[v] = INF;
    visit.clear();
    
    for(auto &e: edges[cent]) {
        int next = e.v;
        if(!visited[next]) ret = min(dnc(next), ret);
    }
    
    return ret;
}

int solve() {
    return dnc(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(minRoad, minRoad+1'000'001, INF); minRoad[0] = 0;
    
    cin >> N >> K;
    for(int i = 1; i < N; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }
    
    int ans = solve();
    cout << (ans == INF ? -1 : ans);

    return 0;
}