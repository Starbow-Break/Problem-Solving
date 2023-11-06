#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

const int INF = 1'000'000'000;
const int SOURCE = 201;
const int SINK = 202;

int flow[203][203] = {0, }; // 현재 유량
int capacity[203][203] = {0, }; // 용량
int previous[203];

bool bfs(int source, int sink) {
    fill(previous, previous+203, 0);
    queue<int> q; q.push(source); previous[source] = -1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == sink) return true;
        
        for(int i = 1; i <= 202; i++) {
            if(previous[i] == 0 && capacity[cur][i] > flow[cur][i]) {
                q.push(i);
                previous[i] = cur;
            }
        }
    }
    
    return false;
}

int maxFlow(int source, int sink) {
    int ret = 0;
    
    //BFS로 유량을 더 흘려보낼 수 있는지 판단 
    while(bfs(source, sink)) {
        // 더 흘려 보낼 수 있으면 갱신
        int cur = sink;
        int curFlow = INF;
        while(cur != source) {
            curFlow = min(curFlow, capacity[previous[cur]][cur]-flow[previous[cur]][cur]);
            cur = previous[cur];
        }
        
        cur = sink;
        while(cur != source) {
            flow[previous[cur]][cur] += curFlow;
            flow[cur][previous[cur]] -= curFlow;
            cur = previous[cur];
        }
        
        ret += curFlow;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> capacity[SOURCE][i];
    for(int i = 1; i <= M; i++) cin >> capacity[100+i][SINK];
    
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) cin >> capacity[j][100+i];
    }
    
    cout << maxFlow(SOURCE, SINK);
    
    return 0;
}
