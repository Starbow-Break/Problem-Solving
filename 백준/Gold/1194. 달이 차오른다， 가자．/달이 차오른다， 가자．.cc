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
    int r, c, key, t;
};

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int N, M;
char maze[50][51];
bool visited[50][50][64] = {false, };

int solve(int r, int c) {
    queue<node> q;
    q.push({r, c, 0, 0});
    visited[r][c][0] = true;
    while(!q.empty()) {
        node start = q.front(); q.pop();
        int r = start.r;
        int c = start.c;
        int key = start.key;
        int t = start.t;
        
        if(maze[r][c] == '1') return t;
        
        for(int k = 0; k < 4; k++) {
            if(0 <= r+dr[k] && r+dr[k] < N && 0 <= c+dc[k] && c+dc[k] < M) {
                if('a' <= maze[r+dr[k]][c+dc[k]] && maze[r+dr[k]][c+dc[k]] <= 'f') {
                    if(!visited[r+dr[k]][c+dc[k]][key|1<<(maze[r+dr[k]][c+dc[k]]-'a')]) {
                        q.push({r+dr[k], c+dc[k], key|1<<(maze[r+dr[k]][c+dc[k]]-'a'), t+1});
                        visited[r+dr[k]][c+dc[k]][key|1<<(maze[r+dr[k]][c+dc[k]]-'a')] = true;
                    }
                }
                else if('A' <= maze[r+dr[k]][c+dc[k]] && maze[r+dr[k]][c+dc[k]] <= 'F') {
                    if(key & 1<<(maze[r+dr[k]][c+dc[k]]-'A')) {
                        if(!visited[r+dr[k]][c+dc[k]][key]) {
                            q.push({r+dr[k], c+dc[k], key, t+1});
                            visited[r+dr[k]][c+dc[k]][key] = true;
                        }
                    }
                }
                else if(maze[r+dr[k]][c+dc[k]] != '#') {
                    if(!visited[r+dr[k]][c+dc[k]][key]) {
                        q.push({r+dr[k], c+dc[k], key, t+1});
                        visited[r+dr[k]][c+dc[k]][key] = true;
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
    for(int i = 0; i < N; i++) cin >> maze[i];
    int ans;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(maze[r][c] == '0') {
                ans = solve(r, c);
                break;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
