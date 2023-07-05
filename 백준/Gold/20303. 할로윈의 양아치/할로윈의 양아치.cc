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

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

struct info {
    int sz, candy;
};

int parent[30'001];
int sz[30'001];
int candy[30'001];
vector<int> edges[30'001];
bool visited[30'001] = {false, };

int findRoot(int v) {
    if(v == parent[v]) return v;
    
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
    if(ra == rb) return;
    
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
    sz[ra] += sz[rb];
    candy[ra] += candy[rb];
}

void dfs(int cur) {
    visited[cur] = true;
    for(auto &next: edges[cur]) {
        if(!visited[next]) {
            merge(next, cur);
            dfs(next);
        }
    }
}

vector<info> infos;
int dp[30001][3001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K; cin >> N >> M >> K;
    for(int k = 0; k <= K; k++) {
        fill(dp[k], dp[k]+N, -1);
    }
    
    for(int i = 1; i <= N; i++) {
        cin >> candy[i]; parent[i] = i;
        sz[i] = 1;
    }
    
    for(int i = 1; i <= M; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) dfs(i);
    }
    
    for(int i = 1; i <= N; i++) {
        if(i == parent[i]) {
            infos.push_back({sz[i], candy[i]});
        }
    }
    
    dp[0][K-1] = 0;
    for(int i = 1; i <= infos.size(); i++) {
        for(int j = 0; j <= K-1; j++) {
            if(dp[i-1][j] != -1) {
                if(j-infos[i-1].sz >= 0) {
                    dp[i][j-infos[i-1].sz] = max(dp[i][j-infos[i-1].sz], dp[i-1][j]+infos[i-1].candy);
                }
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i <= K-1; i++) ans = max(ans, dp[infos.size()][i]);
    cout << ans;

    return 0;
}