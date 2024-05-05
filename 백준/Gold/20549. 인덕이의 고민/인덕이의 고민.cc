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

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.fi > b.fi;
    }
};

int N;
int visited[50][50][16];
int arr[50][50];
int a, b, c;

int dr[3][8] = {
    {-2, -2, -1, -1, 1, 1, 2, 2},
    {-1, -1, 1, 1},
    {0, -1, 1, 0}
};

int dc[3][8] = {
    {-1, 1, -2, 2, -2, 2, -1, 1},
    {-1, 1, -1, 1},
    {-1, 0, 0, 1}
};

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({0, start}); visited[start/16/N][start/16%N][start%16] = 0;
    
    while(!pq.empty()) {
        int d = pq.top().fi;
        int cur = pq.top().se;
        pq.pop();
        
        if(visited[cur/16/N][cur/16%N][cur%16] < d) continue;
        
        // knight
        for(int k = 0; k < 8; k++) {
            int nr = cur/16/N + dr[0][k];
            int nc = cur/16%N + dc[0][k];
            
            if(0 <= nr && nr < N && 0 <= nc && nc < N) {
                int newS = (cur%16) | (arr[nr][nc] >= 0 ? (1 << arr[nr][nc]) : 0);
                if(visited[nr][nc][newS] > d + a) {
                    visited[nr][nc][newS] = d + a;
                    pq.push({visited[nr][nc][newS], (nr*N+nc)*16+newS});
                }
            }
        }
        
        // bishop
        for(int k = 0; k < 4; k++) {
            int nr = cur/16/N + dr[1][k];
            int nc = cur/16%N + dc[1][k];
            
            while(0 <= nr && nr < N && 0 <= nc && nc < N) {
                int newS = (cur%16) | (arr[nr][nc] >= 0 ? (1 << arr[nr][nc]) : 0);
                if(visited[nr][nc][newS] > d + b) {
                    visited[nr][nc][newS] = d + b;
                    pq.push({visited[nr][nc][newS], (nr*N+nc)*16+newS});
                }
                
                nr += dr[1][k]; nc += dc[1][k];
            }
        }
        
        // rook
        for(int k = 0; k < 4; k++) {
            int nr = cur/16/N + dr[2][k];
            int nc = cur/16%N + dc[2][k];
            
            while(0 <= nr && nr < N && 0 <= nc && nc < N) {
                int newS = (cur%16) | (arr[nr][nc] >= 0 ? (1 << arr[nr][nc]) : 0);
                if(visited[nr][nc][newS] > d + c) {
                    visited[nr][nc][newS] = d + c;
                    pq.push({visited[nr][nc][newS], (nr*N+nc)*16+newS});
                }
                
                nr += dr[2][k]; nc += dc[2][k];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> a >> b >> c;
    
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            arr[row][col] = -1;
            for(int k = 0; k < 16; k++) {
                visited[row][col][k] = 1e9;
            }
        }
    }
    
    int row, col; cin >> row >> col;
    int M; cin >> M;
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        arr[x][y] = i;
    }
    
    dijkstra((row*N+col)*16);
    
    int ans = 1e9;
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            ans = min(ans, visited[row][col][(1<<M)-1]);
        }
    }
    
    cout << ans;
    
    return 0;
}
