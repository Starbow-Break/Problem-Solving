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

struct node {
    int cur, bef, k;
};

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

int N, M;
char arr[2'000][2'001];
int id[2'000][2'000] = {0, };
bool isArticulation[4'000'001] = {false, };
int order[4'000'001] = {0, };
int low[4'000'001] = {0, };
int child = 0;
bool isDangerous[4'000'001] = {false, };

vector<int> edges[4'000'001];

int islandNum = 0;
void bfs(int start) {
    queue<int> q;
    q.push(start); id[start / M][start % M] = ++islandNum;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            int nr = cur / M + dr[k], nc = cur % M + dc[k];
            if(
                0 <= nr && nr < N && 0 <= nc && nc < M
                && arr[nr][nc] == '#' && !id[nr][nc]
            ) {
                id[nr][nc] = islandNum;
                q.push(nr * M + nc);
            }
        }
    }
}

int curOrd = 0;
vector<int> dfsTree[4'000'001];
queue<int> check;
stack<node> s;
void dfs(int start) {
    s.push({start, -1, 0});
    while(!s.empty()) {
        node n = s.top(); s.pop();
        int cur = n.cur, bef = n.bef, k = n.k;
        
        if(k == 0) {
            order[cur] = ++curOrd;
            low[cur] = curOrd;
        }
        else {
            if(bef == -1 && child > 1) {
                isArticulation[cur] = true;
            }
            else if(bef != -1 && low[edges[cur][k-1]] >= order[cur]) {
                isArticulation[cur] = true;
                check.push(edges[cur][k-1]);
            }
            
            low[cur] = min(low[cur], low[edges[cur][k-1]]);
        }
        
        for(int idx = k; idx < edges[cur].size(); idx++) {
            int next = edges[cur][idx];
            
            if(!order[next]) {
                if(bef == -1) child++;
                dfsTree[cur].pb(next);
                s.push({cur, bef, idx+1});
                s.push({next, cur, 0});
                break;
            }
            else {
                if(next != bef) low[cur] = min(low[cur], order[next]);
            }
        }
    }
}

bool visited[4'000'001] = {false, };
void bfs1(int start) {
    queue<int> q; q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(0 < cur && cur <= islandNum) {
            isDangerous[cur] = true;
        }
        
        for(auto &next: dfsTree[cur]) {
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    // 그래프 만들기
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(arr[r][c] == '#' && !id[r][c]) {
                bfs(r*M+c);
            }
        }
    }
    
    int temp = islandNum;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(arr[r][c] == '.') {
                id[r][c] = ++temp;
            }
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if(
                    0 <= nr && nr < N && 0 <= nc && nc < M
                    && id[r][c] != id[nr][nc]
                ) {
                    edges[id[r][c]].pb(id[nr][nc]);
                }
            }
        }
    }
    
    for(int r = 0; r < N; r++) {
        edges[0].pb(id[r][0]);
        edges[0].pb(id[r][M-1]);
        edges[id[r][0]].pb(0);
        edges[id[r][M-1]].pb(0);
    }
    for(int c = 1; c < M-1; c++) {
        edges[0].pb(id[0][c]);
        edges[id[0][c]].pb(0);
        edges[0].pb(id[N-1][c]);
        edges[id[N-1][c]].pb(0);
    }
    
    // 단절점 구하기
    dfs(0);
    
    // 섬들의 위험 여부 구하기
    while(!check.empty()) {
        bfs1(check.front());
        check.pop();
    }
    
    // 답 출력
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(arr[r][c] == '#') {
                cout << (isDangerous[id[r][c]] ? 'X' : 'O');
            }
            else cout << arr[r][c];
        }
        cout << '\n';
    }
    
    return 0;
}