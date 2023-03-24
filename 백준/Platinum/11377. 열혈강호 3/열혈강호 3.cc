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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int INF = 1'000'000'000;

int capacity[2005][2005] = {0, };
int flow[2005][2005] = {0, };
int previous[2005];
vector<int> edges[2005];

bool bfs(int start, int finish) {
    fill(previous, previous+2005, 0);
    
    queue<int> q; q.push(start); previous[start] = -1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(cur == finish) return true;
        
        for(auto &next: edges[cur]) {
            if(previous[next] == 0 && capacity[cur][next] > flow[cur][next]) {
                previous[next] = cur; q.push(next);
            }
        }
    }
    
    return false;
}

int maximumFlow(int s, int f) {
    while(bfs(s, f)) {
        int curFlow = INF;
        
        int i = f;
        while(i != s) {
            curFlow = min(curFlow, capacity[previous[i]][i]-flow[previous[i]][i]);
            i = previous[i];
        }
        
        i = f;
        while(i != s) {
            flow[previous[i]][i] += curFlow;
            flow[i][previous[i]] -= curFlow;
            i = previous[i];
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= 1000; i++) {
        ans += flow[1000+i][2004];
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K; cin >> N >> M >> K;
    
    for(int i = 1; i <= N; i++) {
        int n; cin >> n;
        while(n--) {
            int v; cin >> v;
            capacity[i][1000+v] = INF;
            edges[i].push_back(1000+v); edges[1000+v].push_back(i);
        }
    }
    
    for(int i = 1001; i <= 2000; i++) {
        capacity[i][2004] = 1;
        edges[i].push_back(2004); edges[2004].push_back(i);
    }
    
    for(int i = 1; i <= N; i++) {
        capacity[2001][i] = 1; capacity[2003][i] = 1;
        edges[2003].push_back(i); edges[i].push_back(2003);
        edges[2001].push_back(i); edges[i].push_back(2001);
    }
    
    capacity[2002][2001] = INF; edges[2001].push_back(2002); edges[2002].push_back(2001);
    capacity[2002][2003] = K; edges[2003].push_back(2002); edges[2002].push_back(2003);
    
    cout << maximumFlow(2002, 2004);

    return 0;
}