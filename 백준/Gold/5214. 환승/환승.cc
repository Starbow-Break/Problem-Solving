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

vector<int> edges[101001];

int bfs(int s, int f) {
    int visited[101001];
    fill(visited, visited+101001, -1);
    queue<int> q; q.push(s);
    visited[s] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == f) {
            return visited[f];
        }
        for(auto &next: edges[cur]) {
            if(visited[next] == -1) {
                visited[next] = visited[cur]+1;
                q.push(next);
            }
        }
    }
    
    return -4;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K, M; cin >> N >> K >> M;
    for(int i = 1; i <= M; i++) {
        for(int k = 1; k <= K; k++) {
            int v; cin >> v;
            edges[100000+i].pb(v);
            edges[v].pb(100000+i);
        }
    }
    
    cout << bfs(1, N)/2+1;
    
    return 0;
}
