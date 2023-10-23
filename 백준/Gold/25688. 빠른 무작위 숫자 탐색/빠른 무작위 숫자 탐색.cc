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

int arr[5][5];

int visited[25][64];
int solve(int r, int c) {
    for(int i = 0; i < 25; i++) {
        fill(visited[i], visited[i]+64, -1);
    }
    
    queue<pii> q;
    q.push({r*5+c, 0}); visited[r*5+c][0] = 0;
    while(!q.empty()) {
        int cur = q.front().fi;
        int status = q.front().se;
        
        q.pop();
        
        for(int k = 0; k < 4; k++) {
            int nr = cur/5+dr[k];
            int nc = cur%5+dc[k];
            if(0 <= nr && nr < 5 && 0 <= nc && nc < 5 && arr[nr][nc] != -1) {
                int ns = status;
                if(arr[nr][nc]) {
                    ns |= 1<<(arr[nr][nc]-1);
                }
                
                if(visited[5*nr+nc][ns] == -1) {
                    q.push({5*nr+nc, ns});
                    visited[5*nr+nc][ns] = visited[cur][status]+1;
                }
            }
        }
    }
    
    int ret = -1;
    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++) {
            if(visited[5*r+c][63] != -1) {
                if(ret == -1) ret = visited[5*r+c][63];
                else ret = min(ret, visited[5*r+c][63]);
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++) cin >> arr[r][c];
    }
    
    int r, c; cin >> r >> c;
    
    cout << solve(r, c);
    
    return 0;
}
