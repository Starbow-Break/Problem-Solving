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
#define MAX_N 1'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

vector<int> graph[MAX_N];

void init() {
    for(int i = 0; i < MAX_N; i++) graph[i].clear();
}

bool visited[MAX_N+1]; int conn[MAX_N+1];
bool dfs(int cur) {
    for(auto &next: graph[cur]) {
        if(visited[next]) continue;
        
        visited[next] = true;
        
        if(conn[next] == -1 || dfs(conn[next])) {
            conn[next] = cur;
            return true;
        }
    }
    
    return false;
}

int binary_matching(int n) {
    int ret = 0;
    fill(conn, conn+MAX_N, -1);
    
    for(int i = 0; i < n; i++) {
        fill(visited, visited+MAX_N, false);
        ret += dfs(i);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        init();
        
        int n, m; cin >> n >> m;
        
        while(m--) {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
        }
        
        cout << binary_matching(n) << '\n';
    }

    return 0;
}