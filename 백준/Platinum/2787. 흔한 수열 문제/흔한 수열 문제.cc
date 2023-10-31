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

int N, M; 
int minV[201], maxV[201];
int connect[201] = {0, };
bool visited[201] = {false, };
bool check[201][201];

bool dfs(int cur) {
    visited[cur] = true;
    
    for(int i = minV[cur]; i <= maxV[cur]; i++) {
        if(!check[cur][i]) continue;
        if(!connect[i] || (!visited[connect[i]] && dfs(connect[i]))) {
            connect[i] = cur;
            return true;
        }
    }
    
    return false;
}

int binaryMatching() {
    int ret = 0;
    for(int i = 1; i <= N; i++) {
        fill(visited+1, visited+N+1, false);
        ret += dfs(i);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    fill(minV+1, minV+N+1, 1); fill(maxV+1, maxV+N+1, N);
    
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) check[r][c] = true;
    }
    
    while(M--) {
        int q, x, y, v; cin >> q >> x >> y >> v;
        if(q == 1) {
            for(int i = x; i <= y; i++) {
                maxV[i] = min(maxV[i], v);
            }
        }
        else {
            for(int i = x; i <= y; i++) {
                minV[i] = max(minV[i], v);
            }
        }
        for(int i = 1; i <= N; i++) {
            if(i < x || i > y) check[i][v] = false;
        }
    }
    
    int cnt = binaryMatching();
    
    if(cnt == N) {
        int ans[N+1];
        for(int i = 1; i <= N; i++) {
            ans[connect[i]] = i;
        }
        for(int i = 1; i <= N; i++) cout << ans[i] << ' ';
    }
    else {
        cout << -1;
    }
    
    return 0;
}