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

const int INF = 1e9;
const int SOURCE = 2500;
const int SINK = 2501;

vector<int> edges[2502];
int capacity[2502][2502] = {0, };
int flow[2502][2502] = {0, };

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

void init(int N, int M) {
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if((r+c)%2) {
                edges[r*M+c].pb(SINK);
                edges[SINK].pb(r*M+c);
            }
            else {
                edges[SOURCE].pb(r*M+c);
                edges[r*M+c].pb(SOURCE);
                for(int k = 0; k < 4; k++) {
                    int nr = r+dr[k], nc = c+dc[k];
                    if(0 <= nr && nr < N && 0 <= nc && nc < M) {
                        edges[r*M+c].pb(nr*M+nc);
                        edges[nr*M+nc].pb(r*M+c);
                        capacity[r*M+c][nr*M+nc] = INF;
                    }
                }
            }
        }
    }
}

int input(int N, int M) {
    int ret = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            int v; cin >> v;
            ret += v;
            if((r+c)%2) {
                capacity[r*M+c][SINK] = v;
            }
            else {
                capacity[SOURCE][r*M+c] = v;
            }
        }
    }
    
    return ret;
}

int previous[2502];

bool bfs() {
    fill(previous, previous+2502, -1);
    queue<int> q;
    q.push(SOURCE); previous[SOURCE] = -2;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(cur == SINK) return true;
        
        for(auto &next: edges[cur]) {
            if(previous[next] == -1 && capacity[cur][next] > flow[cur][next]) {
                q.push(next);
                previous[next] = cur;
            }
        }
    }
    
    return false;
}

int maxFlow() {
    while(bfs()) {
        int curFlow = INF;
        
        int i = SINK;
        while(i != SOURCE) {
            curFlow = min(curFlow, capacity[previous[i]][i]-flow[previous[i]][i]);
            i = previous[i];
        }
        
        i = SINK;
        while(i != SOURCE) {
            flow[previous[i]][i] += curFlow;
            flow[i][previous[i]] -= curFlow;
            i = previous[i];
        }
    }
    
    int ret = 0;
    for(auto &v: edges[SINK]) {
        ret += flow[v][SINK];
    }
    
    return ret;
}

void reset(int N, int M) {
    for(int i = 0; i < N*M; i++) edges[i].clear();
    edges[SOURCE].clear(); edges[SINK].clear();
    
    for(int i = 0; i < N*M; i++) {
        capacity[SOURCE][i] = 0;
        flow[SOURCE][i] = 0;
        flow[i][SOURCE] = 0;
        
        capacity[i][SINK] = 0;
        flow[i][SINK] = 0;
        flow[SINK][i] = 0;
        
        for(int j = 0; j < N*M; j++) {
            capacity[i][j] = 0;
            flow[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        init(N, M);
        int total = input(N, M);
        int mf = maxFlow();
        cout << total - mf << '\n';
        reset(N, M);
    } 
    
    return 0;
}
