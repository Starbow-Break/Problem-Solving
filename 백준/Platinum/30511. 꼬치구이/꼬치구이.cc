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

struct edge {
    int capacity, flow;
};

const int INF = 1'000'000'000;

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M;
char arr[100][101];
vector<edge> edges;
vector<pii> graph[10002];

int previous[10002];
int passEdgenum[10002];

bool bfs(int start, int finish) {
    fill(previous, previous+10002, 0);
    
    queue<int> q;
    q.push(start); previous[start] = -1;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(cur == finish) return true;
        
        for(auto &[next, num]: graph[cur]) {
            if(previous[next] == 0 && edges[num].capacity > edges[num].flow) {
                q.push(next);
                previous[next] = cur;
                passEdgenum[next] = num;
            }
        }
    }
    
    return false;
}

int maxFlow(int source, int sink) {
    while(bfs(source, sink)) {
        int curFlow = INF;
        
        int i = sink;
        while(i != source) {
            int e = passEdgenum[i];
            curFlow = min(curFlow, edges[e].capacity-edges[e].flow);
            i = previous[i];
        }
        
        i = sink;
        while(i != source) {
            int e = passEdgenum[i];
            edges[e].flow += curFlow;
            edges[e + (e%2 ? -1 : 1)].flow -= curFlow;
            i = previous[i];
        }
    }
    
    int ret = 0;
    for(auto &[next, num]: graph[sink]) {
        ret -= edges[num].flow;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int source = 10000, sink = 10001;
    
    cin >> N >> M;
    for(int r = 0; r < N; r++) cin >> arr[r];
    
    int edgeNum = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(arr[r][c] == 'M') {
                for(int k = 0; k < 8; k++) {
                    int nr = r+dr[k], nc = c+dc[k];
                    int nnr = r+2*dr[k], nnc = c+2*dc[k];
                    if(0 <= nnr && nnr < N && 0 <= nnc && nnc < M) {
                        if(arr[nr][nc] == 'S' && arr[nnr][nnc] == 'G') {
                            edges.pb({1, 0});
                            edges.pb({0, 0});
                            graph[nr*M+nc].pb({nnr*M+nnc, edgeNum});
                            edgeNum++;
                            graph[nnr*M+nnc].pb({nr*M+nc, edgeNum});
                            edgeNum++;
                        }
                        else if(arr[nr][nc] == 'G' && arr[nnr][nnc] == 'S') {
                            edges.pb({1, 0});
                            edges.pb({0, 0});
                            graph[nnr*M+nnc].pb({nr*M+nc, edgeNum});
                            edgeNum++;
                            graph[nr*M+nc].pb({nnr*M+nnc, edgeNum});
                            edgeNum++;
                        }
                    }
                }
            }
            if(arr[r][c] == 'S') {
                edges.pb({1, 0});
                edges.pb({0, 0});
                graph[source].pb({r*M+c, edgeNum});
                edgeNum++;
                graph[r*M+c].pb({source, edgeNum});
                edgeNum++;
            }
            if(arr[r][c] == 'G') {
                edges.pb({1, 0});
                edges.pb({0, 0});
                graph[r*M+c].pb({sink, edgeNum});
                edgeNum++;
                graph[sink].pb({r*M+c, edgeNum});
                edgeNum++;
            }
        }
    }
    
    // for(int i = 0; i < N*M; i++) {
    //     for(auto &[next, num]: graph[i]) {
    //         cout << next << ' ';
    //     }
    //     cout << '\n';
    // }
    
    cout << maxFlow(source, sink);
    
    return 0;
}
