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

vector<pii> edges[1002][10];
vector<int> ricecake[1001];
vector<pii> route;
int visited[1002][10] = {0, };

void bfs(pii start) {
    queue<pii> q;
    q.push(start);
    visited[start.fi][start.se] = -1;
    
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        for(auto &next: edges[cur.fi][cur.se]) {
            if(!visited[next.fi][next.se]) {
                q.push(next);
                visited[next.fi][next.se] = (cur.se == 0 ? -1 : cur.se);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int n; cin >> n;
        while(n--) {
            int v; cin >> v;
            ricecake[i].pb(v);
        }
    }
    
    for(int i = 1; i <= N; i++) {
        for(auto &v: ricecake[i]) {
            if(i == 1) {
                edges[0][0].pb({1, v});
            }
            else {
                for(auto &w: ricecake[i-1]) {
                    if(v != w) {
                        edges[i-1][w].pb({i, v});
                    }
                }
            }
        }
    }
    
    for(auto &v: ricecake[N]) {
        edges[N][v].pb({N+1, 0});
    }
    
    bfs({0, 0});
    
    if(!visited[N+1][0]) cout << -1;
    else {
        vector<int> route;
        pii cur = {N+1, 0};
        while(cur.fi > 0) {
            cur = {cur.fi-1, visited[cur.fi][cur.se]};
            if(cur.se != -1) route.pb(cur.se);
        }
        reverse(route.begin(), route.end());
        for(auto &v: route) cout << v<< '\n';
    }
    
    return 0;
}