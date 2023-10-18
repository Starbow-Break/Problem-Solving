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

vector<int> edges[200001];

int visited[200001];
void bfs(int cur = 1) {
    fill(visited+1, visited+200001, -1);
    visited[cur] = 0;
    queue<int> q; q.push(1);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &next: edges[cur]) {
            if(visited[next] == -1) {
                visited[next] = visited[cur]+1;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        int u, v; cin >> u >> v;
        edges[u].pb(v); edges[v].pb(u);
    }
    
    bfs(1);
    
    int dep[200000] = {0, };
    for(int i = 1; i <= N; i++) dep[visited[i]]++;
    
    ll ans = 1;
    for(int i = 0; i < N; i++) {
        ans *= (1+dep[i]);
        ans %= 1'000'000'007;
    }
    ans += (1'000'000'007-1); ans %= 1'000'000'007;
    
    cout << ans;
    
    return 0;
}