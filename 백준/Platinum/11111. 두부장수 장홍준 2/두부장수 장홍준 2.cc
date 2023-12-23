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
#define MAX_N 2502 //정점의 최대 갯수
#define INF 1'000'000'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

int capacity[MAX_N][MAX_N] = {0, }; //용량
int flow[MAX_N][MAX_N] = {0, }; //현재 유량
int cost[MAX_N][MAX_N] = {0, }; //비용

vector<int> graph[MAX_N]; //탐색하는 그래프

//MCMF문제에서는 음수 사이클이 존재하지 않으므로 
//음수 사이클을 판별하는 부분은 제외했습니다.
//---------------------------SPFA---------------------------
int dist[MAX_N], previous[MAX_N];
bool inQueue[MAX_N];
bool spfa(int start, int finish) {
    queue<int> q;
    
    fill(dist, dist+MAX_N+1, INF);
    fill(previous, previous+MAX_N+1, -1);
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
int mcmf(int source, int sink) {
    int totFlow = 0, totCost = 0;
    int ret = 0;

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
        
        ret = max(ret, -totCost);
    }
    
    return ret;
}
//---------------------------MCMF---------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int source = 2500, sink = 2501;
    int ct[6][6] = {
        {10, 8, 7, 5, 0, 1},
        {8, 6, 4, 3, 0, 1},
        {7, 4, 3, 2, 0, 1},
        {5, 3, 2, 2, 0, 1},
        {0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0},
    };
    
    int N, M; cin >> N >> M;
    char arr[50][51];
    
    for(int r = 0; r < N; r++) cin >> arr[r];
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if((r+c)%2) {
                graph[r*M+c].push_back(sink);
                graph[sink].push_back(r*M+c);
                capacity[r*M+c][sink] = 1;
            }
            else {
                graph[source].push_back(r*M+c);
                graph[r*M+c].push_back(source);
                capacity[source][r*M+c] = 1;
                
                for(int k = 0; k < 4; k++) {
                    int nr = r+dr[k], nc = c+dc[k];
                    if(0 <= nr && nr < N && 0 <= nc && nc < M) {
                        graph[r*M+c].push_back(nr*M+nc);
                        graph[nr*M+nc].push_back(r*M+c);
                        capacity[r*M+c][nr*M+nc] = 1;
                        cost[r*M+c][nr*M+nc] = -ct[arr[r][c]-'A'][arr[nr][nc]-'A'];
                        cost[nr*M+nc][r*M+c] = ct[arr[r][c]-'A'][arr[nr][nc]-'A'];
                    }
                }
            }
        }
    }
    
    cout << mcmf(source, sink);

    return 0;
}