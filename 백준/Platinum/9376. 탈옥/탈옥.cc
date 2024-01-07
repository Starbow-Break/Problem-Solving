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

int N, M;
char arr[100][101];
pii prisoner[2];
int dist[3][100][100];

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

void bfs(int mode) {
    for(int r = 0; r < N; r++) fill(dist[mode][r], dist[mode][r]+M, 1e7);
    
    deque<pii> dq;
    
    if(mode == 0) {
        for(int c = 0; c < M; c++) {
            if(arr[0][c] == '#') {
                dq.push_back({0, c});
                dist[mode][0][c] = 1;
            }
            else if(arr[0][c] == '.' || arr[0][c] == '$') {
                dq.push_front({0, c});
                dist[mode][0][c] = 0;
            }
            
            if(arr[N-1][c] == '#') {
                dq.push_back({N-1, c});
                dist[mode][N-1][c] = 1;
            }
            else if(arr[N-1][c] == '.' || arr[N-1][c] == '$') {
                dq.push_front({N-1, c});
                dist[mode][N-1][c] = 0;
            }
        }
        for(int r = 1; r < N-1; r++) {
            if(arr[r][0] == '#') {
                dq.push_back({r, 0});
                dist[mode][r][0] = 1;
            }
            else if(arr[r][0] == '.' || arr[r][0] == '$') {
                dq.push_front({r, M-1});
                dist[mode][r][M-2] = 0;
            }
            
            if(arr[r][M-1] == '#') {
                dq.push_back({r, M-1});
                dist[mode][r][M-1] = 1;
            }
            else if(arr[r][M-1] == '.' || arr[r][M-1] == '$') {
                dq.push_front({r, M-1});
                dist[mode][r][M-1] = 0;
            }
        }
    }
    if(mode == 1) {
        dq.push_front(prisoner[0]);
        dist[mode][prisoner[0].fi][prisoner[0].se] = 0;
    }
    if(mode == 2) {
        dq.push_front(prisoner[1]);
        dist[mode][prisoner[1].fi][prisoner[1].se] = 0;
    }
    
    while(!dq.empty()) {
        pii cur = dq.front(); dq.pop_front();
        for(int k = 0; k < 4; k++) {
            int nr = cur.fi+dr[k];
            int nc = cur.se+dc[k];
            if(0 <= nr && nr < N && 0 <= nc && nc < M && dist[mode][nr][nc] == 1e7) {
                if(arr[nr][nc] == '#') {
                    dq.push_back({nr, nc});
                    dist[mode][nr][nc] = dist[mode][cur.fi][cur.se]+1;
                }
                else if(arr[nr][nc] == '.' || arr[nr][nc] == '$') {
                    dq.push_front({nr, nc});
                    dist[mode][nr][nc] = dist[mode][cur.fi][cur.se];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        prisoner[0] = {-1, -1}; prisoner[1] = {-1, -1};
        cin >> N >> M;
        for(int r = 0; r < N; r++) {
            cin >> arr[r];
            for(int c = 0; c < M; c++) {
                if(arr[r][c] == '$') {
                    if(prisoner[0].fi == -1) {
                        prisoner[0] = {r, c};
                    }
                    else prisoner[1] = {r, c};
                }
            }
        }
        
        bfs(0); bfs(1); bfs(2);
        
        int ans = dist[0][prisoner[0].fi][prisoner[0].se]+dist[0][prisoner[1].fi][prisoner[1].se];
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < M; c++) {
                ans = min(ans, dist[1][r][c]+dist[2][r][c]+dist[0][r][c]-(arr[r][c] == '#' ? 2 : 0));
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}