#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
#define MAX_N 2002 //정점의 최대 갯수
#define INF 1'000'000'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
int numEdge = 0;

struct edgeInfo {
    int s, f, capacity, flow, cost;
};

vector<pii> graph[MAX_N+1]; //탐색하는 그래프
edgeInfo edges[30'000];

void init() {
    numEdge = 0;
    for(int i = 1; i <= MAX_N; i++) graph[i].clear();
}

void addEdge(int s, int f, int ca, int co = 0) {
    numEdge++;
    edges[numEdge] = {s, f, ca, 0, co};
    edges[15000+numEdge] = {f, s, 0, 0, -co};
    graph[s].push_back({f, numEdge});
    graph[f].push_back({s, 15000+numEdge});
}

//MCMF문제에서는 음수 사이클이 존재하지 않으므로 
//음수 사이클을 판별하는 부분은 제외했습니다.
//---------------------------SPFA---------------------------
int dist[MAX_N+1], previous[MAX_N+1];
bool inQueue[MAX_N+1]; int path[MAX_N+1];
bool spfa(int start, int finish) {
    queue<int> q;
    
    fill(dist, dist+MAX_N+1, INF);
    fill(previous, previous+MAX_N+1, 0);
    fill(inQueue, inQueue+MAX_N+1, false);
    
    dist[start] = 0;
    q.push(start); inQueue[start] = true;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        inQueue[cur] = false;
        
        for(auto &p: graph[cur]) {
            int next = p.first; int nextEdge = p.second;
            
            if(edges[nextEdge].flow < edges[nextEdge].capacity) {
                if(dist[cur]+edges[nextEdge].cost < dist[next]) {
                    dist[next] = dist[cur]+edges[nextEdge].cost;
                    previous[next] = cur; path[next] = nextEdge;
                    
                    if(!inQueue[next]) {
                        q.push(next);
                        inQueue[next] = true;
                    }
                }
            }
        }
    }
    
    return dist[finish] != INF;
}
//---------------------------SPFA---------------------------

//---------------------------MCMF---------------------------
pii mcmf(int source, int sink) {
    int totFlow = 0, totCost = 0;
    
    int cnt = 2;
    while(cnt--) {
        spfa(source, sink);
        
        int curFlow = INF;
        
        int i = sink;
        while(i != source) {
            curFlow = min(curFlow, edges[path[i]].capacity-edges[path[i]].flow);
            i = previous[i];
        }
        
        i = sink;
        while(i != source) {
            edges[path[i]].flow += curFlow;
            edges[(path[i] > 15000 ? path[i]-15000 : path[i]+15000)].flow -= curFlow;
            i = previous[i];
        }
    }
    
    for(auto &p: graph[sink]) {
        totFlow -= edges[p.second].flow;
    }
    for(int i = 1; i <= numEdge; i++) {
        totCost += edges[i].flow*edges[i].cost;
    }
    
    return {totFlow, totCost};
}
//---------------------------MCMF---------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int v, e;
    
    while(cin >> v >> e) {
        init();
        
        addEdge(2001, 1, 2); addEdge(1, 2, 2); addEdge(2*v-1, 2*v, 2);
        for(int i = 2; i < v; i++) addEdge(2*i-1, 2*i, 1);
        
        while(e--) {
            int a, b, c; cin >> a >> b >> c;
            addEdge(2*a, 2*b-1, 1, c);
        }
        
        addEdge(2*v, 2002, 2);
        
        cout << mcmf(2001, 2002).second << '\n';
    }

    return 0;
}