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

vector<int> edges[328001];

int visited[328001];
void bfs(int start) {
    fill(visited, visited+328001, -1);
    queue<int> q; q.push(start);
    visited[start] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &next: edges[cur]) {
            if(visited[next] == -1) {
                q.push(next);
                visited[next] = visited[cur]+1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, S, P; cin >> N >> S >> P;
    for(int i = 1; i <= N-1; i++) {
        int a, b; cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    
    bfs(P);
    
    vector<int> vec;
    for(int i = 1; i <= S; i++) {
        vec.pb(visited[i]);
    }
    sort(all(vec));
    
    cout << N-vec[0]-vec[1]-1;
    
    return 0;
}