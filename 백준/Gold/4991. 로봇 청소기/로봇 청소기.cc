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

const int INF = 1'000'000'000;

int N, M;
char _room[20][21];
int room[20][20];
vector<pii> vec;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int d[11][11];
int dp[1 << 11][11];

int visited[20][20];
void bfs(pii start, int num) {
    FOR(r, 0, N) {
        FOR(c, 0, M) {
            visited[r][c] = -1;
        }
    }
    
    queue<pii> q;
    q.push(start); visited[start.fi][start.se] = 0;
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        int r = cur.fi, c = cur.se;
        if(room[r][c] >= 0) {
            d[num][room[r][c]] = visited[r][c];
        }
        for(int k = 0; k < 4; k++) {
            if(0 <= r+dr[k] && r+dr[k] < N && 0 <= c+dc[k] && c+dc[k] < M && visited[r+dr[k]][c+dc[k]] == -1 && _room[r+dr[k]][c+dc[k]] != 'x') {
                visited[r+dr[k]][c+dc[k]] = visited[r][c]+1;
                q.push({r+dr[k], c+dc[k]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(cin >> M >> N) {
        if(!N && !M) break;
        
        vec.clear();
        for(int i = 0; i < N; i++) cin >> _room[i];
        
        vec.pb({0, 0});
        
        FOR(r, 0, N) {
            FOR(c, 0, M) {
                if(_room[r][c] == '*'){
                    vec.pb({r, c});
                }
                if(_room[r][c] == 'o') {
                    vec[0] = {r, c};
                }
            }
        }
        
        FOR(r, 0, N) {
            FOR(c, 0, M) {
                room[r][c] = -1;
            }
        }
        
        FOR(i, 0, vec.size()) {
            room[vec[i].fi][vec[i].se] = i;
        }
        
        FOR(i, 0, vec.size()) {
            FOR(j, 0, vec.size()) {
                d[i][j] = INF;
            }
        }
        
        FOR(i, 0, vec.size()) {
            bfs(vec[i], i);
        }
        
        FOR(s, 0, 1<<11) {
            fill(dp[s], dp[s]+11, INF);
        }
        
        dp[1][0] = 0;
        for(int s = 0; s < 1<<vec.size(); s++) {
            for(int i = 0; i < vec.size(); i++) {
                for(int j = 0; j < vec.size(); j++) {
                    if(!(s & 1<<j)) {
                        dp[s|1<<j][j] = min(dp[s|1<<j][j], dp[s][i]+d[i][j]);
                    }
                }
            }
        }
        
        int ans = INF;
        for(int i = 0; i < vec.size(); i++) {
            ans = min(ans, dp[(1<<vec.size())-1][i]);
        }
        cout << (ans == INF ? -1 : ans) << '\n';
    }
    
    return 0;
}