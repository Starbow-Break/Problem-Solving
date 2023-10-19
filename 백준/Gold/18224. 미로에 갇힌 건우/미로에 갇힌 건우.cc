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

int visited[500][500][20];
int N, M, arr[500][500];

int bfs() {
    queue<int> q;
    q.push(0); visited[0][0][0] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        int r = cur/(N*2*M);
        int c = cur%(N*2*M)/(2*M);
        int k = cur%(2*M);
        
        if(r == N-1 && c == N-1) return visited[r][c][k];
        
        for(int d = 0; d < 4; d++) {
            int nr = r+dr[d];
            int nc = c+dc[d];
            if(0 <= nr && nr < N && 0 <= nc && nc < N) {
                if(arr[nr][nc] && k >= M) {
                    while(0 <= nr && nr < N && 0 <= nc && nc < N && arr[nr][nc]) {
                        nr = nr+dr[d];
                        nc = nc+dc[d];
                    }
                    if(0 <= nr && nr < N && 0 <= nc && nc < N) {
                        if(visited[nr][nc][(k+1)%(2*M)] == -1) {
                            q.push(nr*(N*2*M)+nc*2*M+(k+1)%(2*M));
                            visited[nr][nc][(k+1)%(2*M)] = visited[r][c][k]+1;
                        }
                    }
                }
                else if(!arr[nr][nc]) {
                    if(visited[nr][nc][(k+1)%(2*M)] == -1) {
                        q.push(nr*(N*2*M)+nc*2*M+(k+1)%(2*M));
                        visited[nr][nc][(k+1)%(2*M)] = visited[r][c][k]+1;
                    }
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            cin >> arr[r][c];
            for(int k = 0; k < 2*M; k++) visited[r][c][k] = -1;
        }
    }
    
    int t = bfs();
    if(t >= 0)
        cout << t/(2*M)+1 << ' ' << (t%(2*M) >= M ? "moon" : "sun");
    else
        cout << -1;
    
    return 0;
}
