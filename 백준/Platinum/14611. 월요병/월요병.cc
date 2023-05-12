#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll INF = 1e18;

ll dist[302][302];
int arr[302][302] = {0, };

struct cmp {
    bool operator()(pair<pii, ll> a, pair<pii, ll> b) {
        return a.y >= b.y;
    }
};

bool valid(int N, int M, int r, int c) {
    if(1 <= r && r <= N && 1 <= c && c <= M) {
        return arr[r][c] != -1;
    }
    if(c == 0) return 2 <= r && r <= N+1;
    if(c == M+1) return 0 <= r && r <= N-1;
    if(r == 0) return 2 <= c && c <= M+1;
    if(r == N+1) return 0 <= c && c <= M-1;
    
    return false;
}

ll solve(int N, int M, pii start) {
    ll ret = INF;
    
    for(int i = 0; i <= 301; i++) fill(dist[i], dist[i]+302, INF);
    priority_queue<pair<pii, ll>, vector<pair<pii, ll>>, cmp> pq;
    pq.push({start, 0}); dist[start.x][start.y] = 0;
    
    while(!pq.empty()) {
        pii cur = pq.top().x; ll d = pq.top().y; pq.pop();
        if(dist[cur.x][cur.y] < d) continue;
        
        if(valid(N, M, cur.x+1, cur.y)) {
            ll dd = d+(arr[cur.x+1][cur.y] == -2 ? 0 : arr[cur.x+1][cur.y]);
            if(dist[cur.x+1][cur.y] > dd) {
                dist[cur.x+1][cur.y] = dd;
                pq.push({{cur.x+1, cur.y}, dd});
            }
        }
        if(valid(N, M, cur.x-1, cur.y)) {
            ll dd = d+(arr[cur.x-1][cur.y] == -2 ? 0 : arr[cur.x-1][cur.y]);
            if(dist[cur.x-1][cur.y] > dd) {
                dist[cur.x-1][cur.y] = dd;
                pq.push({{cur.x-1, cur.y}, dd});
            }
        }
        if(valid(N, M, cur.x, cur.y-1)) {
            ll dd = d+(arr[cur.x][cur.y-1] == -2 ? 0 : arr[cur.x][cur.y-1]);
            if(dist[cur.x][cur.y-1] > dd) {
                dist[cur.x][cur.y-1] = dd;
                pq.push({{cur.x, cur.y-1}, dd});
            }
        }
        if(valid(N, M, cur.x, cur.y+1)) {
            ll dd = d+(arr[cur.x][cur.y+1] == -2 ? 0 : arr[cur.x][cur.y+1]);
            if(dist[cur.x][cur.y+1] > dd) {
                dist[cur.x][cur.y+1] = dd;
                pq.push({{cur.x, cur.y+1}, dd});
            }
        }
        if(valid(N, M, cur.x+1, cur.y+1)) {
            ll dd = d+(arr[cur.x+1][cur.y+1] == -2 ? 0 : arr[cur.x+1][cur.y+1]);
            if(dist[cur.x+1][cur.y+1] > dd) {
                dist[cur.x+1][cur.y+1] = dd;
                pq.push({{cur.x+1, cur.y+1}, dd});
            }
        }
        if(valid(N, M, cur.x-1, cur.y+1)) {
            ll dd = d+(arr[cur.x-1][cur.y+1] == -2 ? 0 : arr[cur.x-1][cur.y+1]);
            if(dist[cur.x-1][cur.y+1] > dd) {
                dist[cur.x-1][cur.y+1] = dd;
                pq.push({{cur.x-1, cur.y+1}, dd});
            }
        }
        if(valid(N, M, cur.x+1, cur.y-1)) {
            ll dd = d+(arr[cur.x+1][cur.y-1] == -2 ? 0 : arr[cur.x+1][cur.y-1]);
            if(dist[cur.x+1][cur.y-1] > dd) {
                dist[cur.x+1][cur.y-1] = dd;
                pq.push({{cur.x+1, cur.y-1}, dd});
            }
        }
        if(valid(N, M, cur.x-1, cur.y-1)) {
            ll dd = d+(arr[cur.x-1][cur.y-1] == -2 ? 0 : arr[cur.x-1][cur.y-1]);
            if(dist[cur.x-1][cur.y-1] > dd) {
                dist[cur.x-1][cur.y-1] = dd;
                pq.push({{cur.x-1, cur.y-1}, dd});
            }
        }
    }
    
    for(int j = 2; j <= M; j++) {
        ret = min(ret, dist[0][j]);
    }
    for(int i = 1; i < N; i++) {
        ret = min(ret, dist[i][M+1]);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     
     
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    
    ll ans = INF;
    ans = min(ans, solve(N, M, {2, 0}));
    
    cout << (ans == INF ? -1 : ans);

    return 0;
}