#include <bits/stdc++.h>

using namespace std;

const int INF = 1'000'000'000;
const int SOURCE = 501;
const int SINK = 502;

int N;
int team[501], w[501][501];
int f[503][503] = {0, }, c[503][503] = {0, }; //f: 유량, c: 용량
int turn[503];

vector<int> edges[503];

int level[503]; //정점의 레벨
vector<int> A, B;
bool isA[503] = {false, };

//bfs를 돌면서 레벨 그래프를 구해준다.
bool bfs() {
    fill(level, level+503, INF);
    level[SOURCE] = 0;
    
    queue<int> q; q.push(SOURCE);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &i: edges[cur]) {
            //유량을 흘려보낼 수 있으면 진행
            if(level[i] == INF && c[cur][i]-f[cur][i] > 0) { 
                level[i] = level[cur]+1;
                q.push(i);
            }
        }
    }
    
    return level[SINK] != INF; //sink에 도달 가능하면 true
}

void bfs1(int start) {
    queue<int> q; q.push(start);
    isA[start] = true;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &i: edges[cur]) {
            if(!isA[i] && c[cur][i]-f[cur][i] > 0) { 
                q.push(i); isA[i] = true;
            }
        }
    }
}

//레벨 그래프 위에서 dfs를 돌면서 유량 계산
int dfs(int start, int end, int flow) {
    if(start == end) return flow; //시작점과 끝점이 같으면 flow 반환
    
    for(int &j = turn[start]; j < edges[start].size(); j++) {
        int i = edges[start][j];
        
        //유량이 흐를 수 있으면
        if(level[i] == level[start]+1 && c[start][i] > f[start][i]) {
            //유량 계산
            int fl = dfs(i, end, min(flow, c[start][i]-f[start][i]));
            
            if(fl > 0) {
                f[start][i] += fl;
                f[i][start] -= fl;
                
                return fl;
            }
        }
    }
    
    return 0;
}

//디닉 알고리즘
int dinic() {
    int ret = 0;
    
    //레벨 그래프를 통해 싱크에 도달 가능할 때 까지 반복
    while(bfs()) {
        fill(turn, turn+503, 0);
        while(1) {
            //DFS를 통해서 경로 탐색
            int flow = dfs(SOURCE, SINK, INF);
            if(flow == 0) break; //경로가 없으면 중지
            ret += flow;
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> team[i];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> c[i][j];
            if(i != j) edges[i].push_back(j);
        }
    }
    
    for(int i = 1; i <= N; i++) {
        if(team[i] == 1) { 
            c[SOURCE][i] = INF; //source랑 직접 연결
            edges[i].push_back(SOURCE);
            edges[SOURCE].push_back(i);
        }
        if(team[i] == 2) { 
            c[i][SINK] = INF; //sink랑 직접 연결
            edges[i].push_back(SINK);
            edges[SINK].push_back(i);
        }
    }
    
    //minimum cut maximum flow theorem에 의하여 maximum flow는 minimum cut이랑 동일
    int minCut = dinic();
    
    cout << minCut << '\n';
    
    bfs1(SOURCE);
    
    for(int i = 1; i <= N; i++) {
        if(isA[i]) A.push_back(i);
        else B.push_back(i);
    }
    
    for(auto &v: A) cout << v << ' ';
    cout << '\n';
    for(auto &v: B) cout << v << ' ';
    cout << '\n';
    
    return 0;
}