#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int parent[500'001];
double p[500'001], sum[500'001][2] = {0, };
double ans = 0;

vector<int> graph[500'001];

bool visited[500'001] = {false, };
void dfs(int cur = 1) {
    visited[cur] = true;
    ans += p[cur];
    for(auto &next: graph[cur]) {
        if(!visited[next]) {
            parent[next] = cur; ans += p[cur]*(1-p[next])+(1-p[cur])*p[next];
            sum[cur][0] += p[next]; sum[cur][1] += 1-p[next];
            dfs(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> p[i];
    
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    parent[1] = -1;
    dfs();
    
    cout << fixed << setprecision(12);
    
    cout << ans << '\n';
    int Q; cin >> Q;
    while(Q--) {
        int v; double newP; cin >> v >> newP;
        ans += (newP-p[v])*(sum[v][1]+1)-(newP-p[v])*sum[v][0];
        
        if(parent[v] != -1) {
            ans += p[parent[v]]*(p[v]-newP)+(1-p[parent[v]])*(newP-p[v]);
            sum[parent[v]][0] += (newP-p[v]);
            sum[parent[v]][1] += (p[v]-newP);
        }
        
        p[v] = newP;
        
        cout << ans << '\n';
    }

    return 0;
}