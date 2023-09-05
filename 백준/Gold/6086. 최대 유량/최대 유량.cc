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

int capacity[60][60] = {0, };
int flow[60][60] = {0, };
int previous[60];
vector<int> edges[60];

bool bfs(int start, int finish) {
    fill(previous, previous+60, -1);
    
    queue<int> q; q.push(start); previous[start] = -1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(cur == finish) return true;
        
        for(auto &next: edges[cur]) {
            if(previous[next] == -1 && capacity[cur][next] > flow[cur][next]) {
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
    for(int i = 0; i < 60; i++) {
        ans += flow[i][25];
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        char a, b; int w;
        cin >> a >> b >> w;
        capacity[a-'A'][b-'A'] += w;
        capacity[b-'A'][a-'A'] += w;
        edges[a-'A'].push_back(b-'A');
        edges[b-'A'].push_back(a-'A');
    }
    
    cout << maximumFlow(0, 25);

    return 0;
}