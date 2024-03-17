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

struct status {
    int cur, per, startDir;
};

const int INF = 1e9;

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

int N;
char chocolate[1000][1001];
vector<int> ans;

int order[1'000'000]; // 방문 순서
int low[1'000'000]; // 각 정점에서 방문할 수 있는 정점 중 최소 order
int child[1'000'000]; // 자식 수
int curOrd = 0;
stack<status> s;
// DFS
void dfs(int start) {
    s.push({start, -1, 0});
    while(!s.empty()) {
        status curStatus = s.top(); s.pop();
        int cur = curStatus.cur;
        int per = curStatus.per;
        int startDir = curStatus.startDir;
        
        // 첫 시작이면
        if(startDir == 0) {
            // 방문 순서 기록
            curOrd++;
            order[cur] = curOrd;
            low[cur] = curOrd;
        }
        // 이어하는 경우면
        else {
            int nr = cur / N + dr[startDir - 1];
            int nc = cur % N + dc[startDir - 1];
            child[cur]++;
            
            // 단절점을 만족하면 기록
            if(per == -1 && child[cur] >= 2) {
                chocolate[cur / N][cur % N] = '*';
            }
            else if(per != -1 && low[nr*N+nc] >= order[cur]) {
                chocolate[cur / N][cur % N] = '*';
            }
            
            low[cur] = min(low[cur], low[nr*N+nc]);
        }
        
        for(int k = startDir; k < 4; k++) {
            int nr = cur / N + dr[k];
            int nc = cur % N + dc[k];
            
            if(
                0 <= nr && nr < N && 0 <= nc && nc < N
                && chocolate[nr][nc] != '.'
            ) {
                // 방문 안한 격자칸이면 방문
                if(order[nr*N+nc] == INF) {
                    s.push({cur, per, k+1});
                    s.push({nr*N+nc, cur, 0});
                    break;
                }
                // 방문 한 격자칸이면
                else {
                    // 이전 칸이 아니면
                    if(nr*N+nc != per) {
                        low[cur] = min(low[cur], low[nr*N+nc]);
                    }
                }
            }
        }
    }
}

// 단절점을 초콜릿에 기록
void writeArticulationPoint() {
    // 초기화
    fill(order, order+N*N, INF);
    fill(low, low+N*N, INF);
    fill(child, child+N*N, 0);
    curOrd = 0;
    
    for(int i = 0; i < N*N; i++) {
        // 처음으로 초콜릿 칸을 찾으면 
        if(chocolate[i / N][i % N] == '#') {
            // DFS
            dfs(i);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int r = 0; r < N; r++) cin >> chocolate[r];
    
    // 단절점을 초콜릿에 기록
    // 해당 칸들은 떼면 안된다 (2단계에서 어긋남)
    writeArticulationPoint();
    
    // 정점/간선 수 구하기
    int vertex = 0, edges = 0;
    for(int i = 0; i < N*N; i++) {
        if(chocolate[i / N][i % N] != '.') {
            vertex++;
            for(int k = 0; k < 4; k++) {
                int nr = i / N + dr[k];
                int nc = i % N + dc[k];
                
                if(0 <= nr && nr < N && 0 <= nc && nc < N) {
                    if(chocolate[nr][nc] != '.') {
                        edges++;
                    }
                }
            }
        }
    }
    edges /= 2;
    
    // 단절점이 아닌 칸들을 떼 보면서 트리가 되는지 확인
    for(int i = 0; i < N*N; i++) {
        // 단절점이 아닌 초콜릿 칸이면
        if(chocolate[i / N][i % N] == '#') {
            int eCnt = 0;
            
            // 제거되는 간선 수 확인
            for(int k = 0; k < 4; k++) {
                int nr = i / N + dr[k];
                int nc = i % N + dc[k];
                
                if(0 <= nr && nr < N && 0 <= nc && nc < N) {
                    if(chocolate[nr][nc] != '.') {
                        eCnt++;
                    }
                }
            }
            
            // 트리가 되는지 확인
            if(vertex - 2 == edges - eCnt) {
                ans.pb(i);
            }
        }
    }
    
    cout << ans.size() << '\n';
    for(auto &v: ans) {
        cout << v / N + 1 << ' ' << v % N + 1 << '\n';
    }
    
    return 0;
}