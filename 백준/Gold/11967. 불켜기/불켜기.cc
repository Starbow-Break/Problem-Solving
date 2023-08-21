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

vector<pii> edges[101][101];
bool visited[101][101] = {false, };
int light[101][101] = {0, };

bool bfs(int sz) {
    queue<pii> q;
    q.push({1, 1});
    visited[1][1] = true;
    vector<pii> vec;
    
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        int r = cur.fi, c = cur.se;

        for(auto &e: edges[r][c]) {
            light[e.fi][e.se] = max(1, light[e.fi][e.se]);
        }
        for(int k = 0; k < 4; k++) {
            if(1 <= r+dr[k] && r+dr[k] <= sz && 1 <= c+dc[k] && c+dc[k] <= sz) {
                if(!visited[r+dr[k]][c+dc[k]]) {
                    if(light[r+dr[k]][c+dc[k]] == 2) {
                        q.push({r+dr[k], c+dc[k]});
                        visited[r+dr[k]][c+dc[k]] = true;
                    }
                    else {
                        vec.pb({r+dr[k], c+dc[k]});
                        visited[r+dr[k]][c+dc[k]] = true;
                    }
                }
            }
        }
    }
    
    for(auto &v: vec) {
        if(light[v.fi][v.se]) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    repeat(M) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        edges[x1][y1].pb({x2, y2});
    }
    
    light[1][1] = 2;
    while(true) {
        if(!bfs(N)) break;
        for(int r = 1; r <= N; r++) {
            for(int c = 1; c <= N; c++) {
                if(light[r][c]) light[r][c] = 2;
                visited[r][c] = false;
            }
        }
    }
    
    int ans = 0;
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            ans += (light[r][c] > 0);
        }
    }
    
    cout << ans;
    
    return 0;
}
