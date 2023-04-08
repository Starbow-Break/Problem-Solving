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
#define MAX_N 20'000 //정점의 최대 갯수
#define INF 1'000'000'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
int numEdge = 0;

struct edgeInfo {
    int s, f, capacity, flow, rev;
};

vector<pii> graph[MAX_N+1]; //탐색하는 그래프
edgeInfo edges[100'000];

int previous[MAX_N+1];
int path[MAX_N+1];
bool bfs(int start, int finish) {
    queue<int> q;
    
    fill(previous, previous+MAX_N+1, 0);
    q.push(start);
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(cur == finish) return true;
        
        for(auto &p: graph[cur]) {
            int next = p.first; int nextEdge = p.second;
            
            if(previous[next] == 0 && edges[nextEdge].flow < edges[nextEdge].capacity) {
                previous[next] = cur; path[next] = nextEdge;
                q.push(next);
            }
        }
    }
    
    return false;
}

int maxFlow(int source, int sink) {
    int ret = 0;
    
    while(bfs(source, sink)) {
        int curFlow = INF;
        
        int i = sink;
        while(i != source) {
            curFlow = min(curFlow, edges[path[i]].capacity-edges[path[i]].flow);
            i = previous[i];
        }
        
        i = sink;
        while(i != source) {
            edges[path[i]].flow += curFlow;
            edges[edges[path[i]].rev].flow -= curFlow;
            i = previous[i];
        }
    }
    
    for(auto &p: graph[sink]) {
        ret -= edges[p.second].flow;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M-1; c++) {
            int v = r*M+c+1; int w = v+1;
            
            numEdge += 2;
            edges[numEdge-1] = {2*v, 2*w-1, INF, 0, numEdge};
            edges[numEdge] = {2*w-1, 2*v, 0, 0, numEdge-1};
            graph[2*v].push_back({2*w-1, numEdge-1});
            graph[2*w-1].push_back({2*v, numEdge});
            
            numEdge += 2;
            edges[numEdge-1] = {2*w, 2*v-1, INF, 0, numEdge};
            edges[numEdge] = {2*v-1, 2*w, 0, 0, numEdge-1};
            graph[2*w].push_back({2*v-1, numEdge-1});
            graph[2*v-1].push_back({2*w, numEdge});
        }
    }
    
    for(int r = 0; r < N-1; r++) {
        for(int c = 0; c < M; c++) {
            int v = r*M+c+1; int w = v+M;
            
            numEdge += 2;
            edges[numEdge-1] = {2*v, 2*w-1, INF, 0, numEdge};
            edges[numEdge] = {2*w-1, 2*v, 0, 0, numEdge-1};
            graph[2*v].push_back({2*w-1, numEdge-1});
            graph[2*w-1].push_back({2*v, numEdge});
            
            numEdge += 2;
            edges[numEdge-1] = {2*w, 2*v-1, INF, 0, numEdge};
            edges[numEdge] = {2*v-1, 2*w, 0, 0, numEdge-1};
            graph[2*w].push_back({2*v-1, numEdge-1});
            graph[2*v-1].push_back({2*w, numEdge});
        }
    }
    
    int source, sink;
    for(int r = 0; r < N; r++) {
        string s; cin >> s;
        for(int c = 0; c < M; c++) {
            int v = r*M+c+1;
            
            if(s[c] == '.') {
                numEdge += 2;
                edges[numEdge-1] = {2*v-1, 2*v, 1, 0, numEdge};
                edges[numEdge] = {2*v, 2*v-1, 0, 0, numEdge-1};
                graph[2*v-1].push_back({2*v, numEdge-1});
                graph[2*v].push_back({2*v-1, numEdge});
            }
            if(s[c] == 'K') {
                numEdge += 2; source = 2*v-1;
                edges[numEdge-1] = {2*v-1, 2*v, INF, 0, numEdge};
                edges[numEdge] = {2*v, 2*v-1, 0, 0, numEdge-1};
                graph[2*v-1].push_back({2*v, numEdge-1});
                graph[2*v].push_back({2*v-1, numEdge});
            }
            if(s[c] == 'H') {
                numEdge += 2; sink = 2*v;
                edges[numEdge-1] = {2*v-1, 2*v, INF, 0, numEdge};
                edges[numEdge] = {2*v, 2*v-1, 0, 0, numEdge-1};
                graph[2*v-1].push_back({2*v, numEdge-1});
                graph[2*v].push_back({2*v-1, numEdge});
            }
        }
    }
    
    int ans = maxFlow(source, sink);
    cout << (ans == INF ? -1 : ans);

    return 0;
}