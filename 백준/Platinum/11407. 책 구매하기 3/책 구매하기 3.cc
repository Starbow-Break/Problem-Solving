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
#define MAX_N 202 //정점의 최대 갯수
#define INF 1'000'000'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int capacity[MAX_N+1][MAX_N+1] = {0, }; //용량
int flow[MAX_N+1][MAX_N+1] = {0, }; //현재 유량
int cost[MAX_N+1][MAX_N+1] = {0, }; //비용

vector<int> graph[MAX_N+1]; //탐색하는 그래프

//MCMF문제에서는 음수 사이클이 존재하지 않으므로 
//음수 사이클을 판별하는 부분은 제외했습니다.
//---------------------------SPFA---------------------------
int dist[MAX_N+1], previous[MAX_N+1];
bool inQueue[MAX_N+1];
bool spfa(int start, int finish) {
    queue<int> q;
    
    fill(dist, dist+MAX_N+1, INF);
    fill(previous, previous+MAX_N+1, 0);
    fill(inQueue, inQueue+MAX_N+1, false);
    
    dist[start] = 0;
    q.push(start); inQueue[start] = true;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        inQueue[cur] = false;
        
        for(auto &next: graph[cur]) {
            if(flow[cur][next] < capacity[cur][next]) {
                if(dist[cur]+cost[cur][next] < dist[next]) {
                    dist[next] = dist[cur]+cost[cur][next];
                    previous[next] = cur;
                    
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
pii mcmf(int source = 201, int sink = 202) {
    int totFlow = 0, totCost = 0;

    while(spfa(source, sink)) {
        int curFlow = INF;
        
        int i = sink;
        while(i != source) {
            curFlow = min(curFlow, capacity[previous[i]][i]-flow[previous[i]][i]);
            i = previous[i];
        }
        
        i = sink;
        while(i != source) {
            flow[previous[i]][i] += curFlow;
            flow[i][previous[i]] -= curFlow;
            totCost += cost[previous[i]][i]*curFlow;
            i = previous[i];
        }
    }
    
    for(int i = 1; i <= MAX_N; i++) {
        totFlow += flow[i][sink];
    }
    
    return {totFlow, totCost};
}
//---------------------------MCMF---------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        int a; cin >> a;
        capacity[201][i] = a;
        graph[201].push_back(i); graph[i].push_back(201);
    }
    
    for(int i = 1; i <= M; i++) {
        int b; cin >> b;
        capacity[100+i][202] = b;
        graph[202].push_back(100+i); graph[100+i].push_back(202);
    }
    
    for(int j = 1; j <= M; j++) {
        for(int i = 1; i <= N; i++) {
            int c; cin >> c;
            capacity[i][100+j] = c;
            graph[i].push_back(100+j); graph[100+j].push_back(i);
        }
    }
    
    for(int j = 1; j <= M; j++) {
        for(int i = 1; i <= N; i++) {
            int c; cin >> c;
            cost[i][100+j] = c; cost[100+j][i] = -c;
        }
    }
    
    pii ans = mcmf();
    
    cout << ans.first << '\n' << ans.second;

    return 0;
}