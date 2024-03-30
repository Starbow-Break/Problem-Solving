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

const int INF = 1e9;

int dr[4] = {-1, -1, 1, 1};
int dc[4] = {-1, 1, 1, -1};

int N, M;
char arr[500][501];

int dist[501][501];

int bfs01(int start, int finish) {
    for(int i = 0; i <= N; i++) fill(dist[i], dist[i]+M+1, INF);
    deque<pii> dq; dq.push_back({start, 0});
    dist[start/(M+1)][start%(M+1)] = 0;
    
    while(!dq.empty()) {
        int cur = dq.front().fi;
        int d = dq.front().se;
        dq.pop_front();
        
        if(cur == finish) return d;
        
        if(dist[cur/(M+1)][cur%(M+1)] < d) continue;
        
        for(int k = 0; k < 4; k++) {
            int nr = cur/(M+1) + dr[k];
            int nc = cur%(M+1) + dc[k];
            
            if(0 <= nr && nr <= N && 0 <= nc && nc <= M) {
                if(arr[cur/(M+1)+(dr[k]-1)/2][cur%(M+1)+(dc[k]-1)/2] == '\\') {
                    if(dist[nr][nc] > dist[cur/(M+1)][cur%(M+1)]+k%2) {
                        dist[nr][nc] = dist[cur/(M+1)][cur%(M+1)]+k%2;
                        
                        if(k%2) dq.push_back({nr*(M+1)+nc, dist[nr][nc]});
                        else dq.push_front({nr*(M+1)+nc, dist[nr][nc]});
                    }
                }
                else {
                    if(dist[nr][nc] > dist[cur/(M+1)][cur%(M+1)]+1-k%2) {
                        dist[nr][nc] = dist[cur/(M+1)][cur%(M+1)]+1-k%2;
                        
                        if(k%2) dq.push_front({nr*(M+1)+nc, dist[nr][nc]});
                        else dq.push_back({nr*(M+1)+nc, dist[nr][nc]});
                    }
                }
            }
        }
    }
    
    return INF;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    int ans = bfs01(0, (N+1)*(M+1)-1);
    
    if(ans == INF) cout << "NO SOLUTION";
    else cout << ans;
    
    return 0;
}