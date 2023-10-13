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

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.se > b.se;
    }
};

int N, M;
char field[50][51];
int w[50][50] = {0, };

int dijkstra(pii s, pii f) {
    int dist[50][50];
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) dist[r][c] = 1e9;
    }
    
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({s.fi*M+s.se, 0}); dist[s.fi][s.se] = 0;
    while(!pq.empty()) {
        int cur = pq.top().fi, d = pq.top().se; pq.pop();
        if(cur == f.fi*M+f.se) return dist[f.fi][f.se];
        
        int r = cur/M, c = cur%M;
        for(int k = 0; k < 4; k++) {
            int nr = r+dr[k];
            int nc = c+dc[k];
            if(0 <= nr && nr < N && 0 <= nc && nc < M) {
                if(dist[nr][nc] > dist[r][c]+w[nr][nc]) {
                    dist[nr][nc] = dist[r][c]+w[nr][nc];
                    pq.push({nr*M+nc, dist[nr][nc]});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int r = 0; r < N; r++) cin >> field[r];
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(field[r][c] == 'g') {
                w[r][c] = max(w[r][c], 10'000);
                for(int k = 0; k < 4; k++) {
                    int nr = r+dr[k];
                    int nc = c+dc[k];
                    if(0 <= nr && nr < N && 0 <= nc && nc < M) w[nr][nc] = max(w[nr][nc], 1);
                }
            }
        }
    }
    
    pii s, f;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(field[r][c] == 'S') {
                w[r][c] = 0;
                s = {r, c};
            }
            if(field[r][c] == 'F') {
                w[r][c] = 0;
                f = {r, c};
            }
        }
    }
    
    int result = dijkstra(s, f);
    cout << result/10000 << ' ' << result%10000;
    
    return 0;
}
