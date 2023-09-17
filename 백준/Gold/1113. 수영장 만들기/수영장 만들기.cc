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

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int N, M; 
int height[50][50];
int visited[50][50];

int bfs(int r, int c) {
    int area = 0;
    int curH = height[r][c];
    int wallH = 10;
    vector<pii> vec;
    
    queue<pii> q;
    q.push({r, c}); visited[r][c] = height[r][c];
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        vec.pb(cur);
        area++;
        for(int k = 0; k < 4; k++) {
            int nr = cur.fi+dr[k];
            int nc = cur.se+dc[k];
            if(0 <= nr && nr < N && 0 <= nc && nc < M) {
                if(height[nr][nc] != curH) {
                    wallH = min(wallH, height[nr][nc]);
                }
                else {
                    if(visited[nr][nc] == -1) {
                        q.push({nr, nc});
                        visited[nr][nc] = height[nr][nc];
                    }
                }
            }
            else {
                wallH = 0;
            }
        }
    }
    
    if(wallH > curH) {
        for(auto &p: vec) {
            visited[p.fi][p.se] = wallH;
        }
    }
    
    return max((wallH-curH)*area, 0);
}

int progress() {
    for(int r = 0; r < N; r++) {
        fill(visited[r], visited[r]+M, -1);
    }
    
    int ret = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(visited[r][c] == -1) ret += bfs(r, c);
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            height[r][c] = visited[r][c];
        }
    }
    
    return ret;
}

int solve() {
    int ret = 0;
    while(true) {
        int result = progress();
        if(!result) break;
        ret += result;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j < M; j++) {
            height[i][j] = s[j]-'0';
        }
    }
    
    // for(int r = 0; r < N; r++) {
    //     for(int c = 0; c < M; c++) cout << height[r][c];
    //     cout << '\n';
    // }
    
    cout << solve() << '\n';
    
    // for(int r = 0; r < N; r++) {
    //     for(int c = 0; c < M; c++) cout << height[r][c];
    //     cout << '\n';
    // }
    
    return 0;
}