#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

const int MAX = 610;
const int INF = 1'000'000'000;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

//source : 601, sink : 602
//승리 정점 : i, 패배 정점 : 300+i
vector<int> edges[MAX+1]; //그래프
int flow[MAX+1][MAX+1], capacity[MAX+1][MAX+1], cost[MAX+1][MAX+1]; //현재 유량, 용량, 비용
int A[MAX+1], H[MAX+1], L[MAX+1]; //실력, 피로도, 최대 경기 횟수

//SPFA 알고리즘
int dist[MAX+1], previous[MAX+1]; //최단 거리, 이전 노드
bool inQueue[MAX+1]; //큐에 존재하는지 여부
bool spfa(int start, int finish) {
    queue<int> q;
    
    //dist, previous, inQueue 초기화
    fill(dist, dist+MAX+1, INF);
    fill(previous, previous+MAX+1, -1);
    fill(inQueue, inQueue+MAX+1, false);
    
    //시작점 반영
    dist[start] = 0;
    q.push(start); inQueue[start] = true;
    
    //큐가 빌때까지 반복
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        inQueue[cur] = false;
        
        for(auto &next: edges[cur]) {
            if(flow[cur][next] < capacity[cur][next]) { //유량을 더 흘려 보낼 수 있으면
                if(dist[next] > dist[cur]+cost[cur][next]) { //비용이 더 적게 들면
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

pii mcmf(int source, int sink) {
    int totFlow = 0, totCost = 0; //총 유량, 총 비용

    //source에서 sink까지 유량을 흘려보낼 수 있을 때 까지 반복
    while(spfa(source, sink)) {
        int curFlow = INF; //현재 단계에서 흘려보낸 유량
        
        int i = sink;
        while(i != source) {
            curFlow = min(curFlow, capacity[previous[i]][i]-flow[previous[i]][i]);
            i = previous[i];
        }
        
        //현재 단계에서의 유량 반영
        i = sink;
        while(i != source) {
            flow[previous[i]][i] += curFlow;
            flow[i][previous[i]] -= curFlow;
            totCost += cost[previous[i]][i]*curFlow;
            i = previous[i];
        }
    }
    
    for(int i = 1; i <= MAX; i++) {
        totFlow += flow[i][sink];
    }
    
    return {totFlow, totCost};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, winner = 1; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        if(A[winner] < A[i]) winner = i;
    }
    for(int i = 1; i <= N; i++) cin >> H[i];
    for(int i = 1; i <= N; i++) cin >> L[i];
    
    //그래프 생성
    for(int i = 1; i <= N; i++) {
        //source랑 승리 정점 연결
        edges[601].push_back(i);
        capacity[601][i] = (winner == i ? L[i] : L[i]-1);
        cost[601][i] = H[i];
        edges[i].push_back(601);
        cost[i][601] = -H[i];
        //sink랑 패배 정점 연결
        edges[300+i].push_back(602);
        capacity[300+i][602] = 1;
        cost[300+i][602] = H[i];
        edges[602].push_back(300+i);
        cost[602][300+i] = -H[i];
    }
    //승리, 패배 정점 연결
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            if(A[i] > A[j]) {
                edges[i].push_back(300+j);
                capacity[i][300+j] = 1;
                cost[i][300+j] = -(A[i]^A[j]);
                edges[300+j].push_back(i);
                cost[300+j][i] = A[i]^A[j];
            }
            else {
                edges[j].push_back(300+i);
                capacity[j][300+i] = 1;
                cost[j][300+i] = -(A[i]^A[j]);
                edges[300+i].push_back(j);
                cost[300+i][j] = A[i]^A[j];
            }
        }
    }
    
    //MCMF
    pii result = mcmf(601, 602);
    
    //최소 비용의 -1배가 정답
    cout << -result.second;

    return 0;
}