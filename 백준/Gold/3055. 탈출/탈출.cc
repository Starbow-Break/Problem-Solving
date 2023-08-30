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

int R, C;
char field[50][51];
int arr[50][50];

void bfsWater() {
    queue<pii> q;
    
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(field[r][c] == '*') {
                q.push({r, c}); arr[r][c] = 0;
            }
        }
    }
    
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            if(0 <= cur.fi+dr[k] && cur.fi+dr[k] < R) {
                if(0 <= cur.se+dc[k] && cur.se+dc[k] < C) {
                    if(arr[cur.fi+dr[k]][cur.se+dc[k]] == -1) {
                        q.push({cur.fi+dr[k], cur.se+dc[k]});
                        arr[cur.fi+dr[k]][cur.se+dc[k]] = arr[cur.fi][cur.se]+1;
                    }
                }
            }
        }
    }
}

int solve() {
    int visited[50][50];
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            visited[r][c] = -1;
        }
    }
    
    queue<pii> q;
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(field[r][c] == 'S') {
                q.push({r, c});
                visited[r][c] = 0;
            }
        }
    }
    
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        if(arr[cur.fi][cur.se] == -2) {
            return visited[cur.fi][cur.se];
        }
        
        for(int k = 0; k < 4; k++) {
            if(0 <= cur.fi+dr[k] && cur.fi+dr[k] < R) {
                if(0 <= cur.se+dc[k] && cur.se+dc[k] < C) {
                    if(visited[cur.fi+dr[k]][cur.se+dc[k]] == -1) {
                        if(arr[cur.fi+dr[k]][cur.se+dc[k]] == -2 ||
                        arr[cur.fi+dr[k]][cur.se+dc[k]] == -1 ||
                        arr[cur.fi+dr[k]][cur.se+dc[k]] > visited[cur.fi][cur.se]+1) {
                            q.push({cur.fi+dr[k], cur.se+dc[k]});
                            visited[cur.fi+dr[k]][cur.se+dc[k]] = visited[cur.fi][cur.se]+1;
                        }
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
    
    cin >> R >> C;
    for(int r = 0; r < R; r++) cin >> field[r];
    
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(field[r][c] == 'D') arr[r][c] = -2;
            if(field[r][c] == 'S') arr[r][c] = -1;
            if(field[r][c] == '*') arr[r][c] = 0;
            if(field[r][c] == 'X') arr[r][c] = -3;
            if(field[r][c] == '.') arr[r][c] = -1;
        }
    }
    
    bfsWater();
    
    // for(int r = 0; r < R; r++) {
    //     for(int c = 0; c < C; c++) {
    //         cout << arr[r][c] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    int result = solve();
    if(result == -1) cout << "KAKTUS";
    else cout << result;
    
    return 0;
}