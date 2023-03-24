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

//1~200:사람, 201~300:음식, 301:유량 시작점, 302: 유량 종착점
int capacity[303][303] = {0, }, flow[303][303] = {0, };
vector<int> edges[303]; int previous[303];

bool bfs(int start, int finish) {
    fill(previous, previous+303, 0);
    
    queue<int> q; q.push(start);
    previous[start] = -1;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(cur == finish) return true;
        
        for(auto &next: edges[cur]) {
            if(previous[next] == 0 && capacity[cur][next] > flow[cur][next]) {
                previous[next] = cur;
                q.push(next);
            }
        }
    }
    
    return false;
}

int maxFlow(int start, int finish) {
    while(bfs(start, finish)) {
        int curFlow = INF;
        
        int i = finish;
        while(i != start) {
            curFlow = min(curFlow, capacity[previous[i]][i]-flow[previous[i]][i]);
            i = previous[i];
        }
        
        i = finish;
        while(i != start) {
            flow[previous[i]][i] += curFlow;
            flow[i][previous[i]] -= curFlow;
            i = previous[i];
        }
    }
    
    int ret = 0;
    for(auto &p: edges[finish]) ret += flow[p][finish];
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K, D; cin >> N >> K >> D;
    
    for(int i = 1; i <= D; i++) {
        int v; cin >> v;
        capacity[200+i][302] = v;
        edges[200+i].push_back(302); edges[302].push_back(200+i);
    }
    
    for(int i = 1; i <= N; i++) {
        capacity[301][i] = K;
        edges[301].push_back(i); edges[i].push_back(301);
        
        int n; cin >> n;
        while(n--) {
            int d; cin >> d;
            capacity[i][200+d] = 1;
            edges[200+d].push_back(i); edges[i].push_back(200+d);
        }
    }
    
    cout << maxFlow(301, 302);
    
    return 0;
}