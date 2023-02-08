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
#define MAX_N 40'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

vector<pii> edges[MAX_N+1];
int p[MAX_N+1][16] = {0, }, w[MAX_N+1][16] = {0, };
int dep[MAX_N+1] = {0, };

bool visited[MAX_N+1] = {false, };
void dfs(int cur = 1) {
    visited[cur] = true;
    for(auto &next: edges[cur]) {
        if(!visited[next.first]) {
            dep[next.first] = dep[cur]+1;
            p[next.first][0] = cur; w[next.first][0] = next.second;
            dfs(next.first);
        }
    }
}

void makeTable(int N) {
    dfs();
    
    for(int i = 1; i <= 15; i++) {
        for(int v = 1; v <= N; v++) {
            p[v][i] = p[p[v][i-1]][i-1];
            w[v][i] = w[p[v][i-1]][i-1]+w[v][i-1];
        }
    }
}

int getParent(int v, int step) {
    int idx = 0;
    while(step != 0) {
        if(step%2) v = p[v][idx];
        
        step /= 2; idx++;
    }
    
    return v;
}

int getLCA(int x, int y) {
    int d = dep[x]-dep[y];
    
    if(d > 0) x = getParent(x, d);
    else y = getParent(y, -d);
    
    for(int i = 15; i >= -1; i--) {
        bool check;
        
        if(i >= 0) check = p[x][i] != p[y][i];
        else check = x != y;
        
        if(check) {
            x = p[x][(i < 0 ? 0 : i)]; y = p[y][(i < 0 ? 0 : i)];
        }
    }
    
    return x;
}

int getLength(int v, int step) {
    int idx = 0; int ret = 0;
    while(step != 0) {
        if(step%2) {
            ret += w[v][idx];
            v = p[v][idx];
        };
        
        step /= 2; idx++;
    }
    
    return ret;
}

int solve(int x, int y) {
    int lca = getLCA(x, y);
    
    int a = getLength(x, dep[x]-dep[lca]);
    int b = getLength(y, dep[y]-dep[lca]);
    
    return a+b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    
    makeTable(N);
    
    int M; cin >> M;
    while(M--) {
        int x, y; cin >> x >> y;
        cout << solve(x, y) << '\n';
    }

    return 0;
}