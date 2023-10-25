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

int visited[500001][2];

void bfs(int start) {
    visited[start][0] = 0;
    queue<pii> q; q.push({start, 0});
    
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        if(cur.fi+1 <= 500000 && visited[cur.fi+1][1-cur.se] == -1) {
            q.push({cur.fi+1, 1-cur.se});
            visited[cur.fi+1][1-cur.se] = visited[cur.fi][cur.se]+1;
        }
        if(cur.fi-1 >= 0 && visited[cur.fi-1][1-cur.se] == -1) {
            q.push({cur.fi-1, 1-cur.se});
            visited[cur.fi-1][1-cur.se] = visited[cur.fi][cur.se]+1;
        }
        if(2*cur.fi <= 500000 && visited[2*cur.fi][1-cur.se] == -1) {
            q.push({2*cur.fi, 1-cur.se});
            visited[2*cur.fi][1-cur.se] = visited[cur.fi][cur.se]+1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    
    for(int i = 0; i <= 500000; i++) {
        visited[i][0] = visited[i][1] = -1;
    }
    
    bfs(N);
    
    for(int i = 0; ; i++) {
        K += i;
        if(K > 500000) break;
        if(visited[K][i%2] <= i) {
            cout << i;
            return 0;
        }
    }
    
    cout << -1;
    return 0;
}
