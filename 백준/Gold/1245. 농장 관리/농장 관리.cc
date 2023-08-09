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

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M;
int h[100][70];
bool visited[100][70] = {false, };

bool bfs(int r, int c) {
    queue<pii> q;
    q.push({r, c}); visited[r][c] = true;
    int t = h[r][c];
    
    bool ret = true;
    while(!q.empty()) {
        int r = q.front().fi, c = q.front().se; q.pop();
        for(int k = 0; k < 8; k++) {
            if(0 <= r+dr[k] && r+dr[k] < N && 0 <= c+dc[k] && c+dc[k] < M) {
                if(!visited[r+dr[k]][c+dc[k]] && h[r+dr[k]][c+dc[k]] == t) {
                    q.push({r+dr[k], c+dc[k]});
                    visited[r+dr[k]][c+dc[k]] = true;
                }
                else if(h[r+dr[k]][c+dc[k]] > t) ret = false;
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) cin >> h[r][c];
    }
    
    int cnt = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(!visited[r][c]) {
                cnt += bfs(r, c);
            }
        }
    }
    
    cout << cnt;
    
    return 0;
}