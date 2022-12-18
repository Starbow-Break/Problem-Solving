#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll INF = 100000000000;

struct edge {
    int f, w;
};

struct compare {
    bool operator()(pll &A, pll &B) {
        return A.second > B.second;
    }
};

int V, E;
int yakult[10]; int start;
vector<edge> edges[10001];

ll A[10];

ll D[10001];
void dijkstra(int s) {
    fill(D+1, D+V+1, INF);
    priority_queue<pll, vector<pll>, compare> pq;
    pq.push({s, 0}); D[s] = 0;
    
    while(!pq.empty()) {
        ll cur = pq.top().first; ll d = pq.top().second; pq.pop();
        if(D[cur] < d) continue;
        
        for(auto &next: edges[cur]) {
            if(D[next.f] <= d+next.w) continue;
            
            pq.push({next.f, d+next.w});
            D[next.f] = d+next.w;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> V >> E;
    while(E--) {
        ll v1, v2, w; cin >> v1 >> v2 >> w;
        edges[v1].push_back({v2, w});
        edges[v2].push_back({v1, w});
    }
    
    for(int i = 0; i < 10; i++) { cin >> yakult[i]; }
    cin >> start;
    
    A[0] = 0;
    fill(A+1, A+10, INF); int bef = 0;
    for(int i = 1; i < 10; i++) {
        dijkstra(yakult[bef]);
        if(D[yakult[i]] == INF) continue;
        
        A[i] = min(A[i], A[bef]+D[yakult[i]]);
        bef = i;
    }
    
    dijkstra(start);
    
    int ans = V+1;
    for(int i = 0; i < 10; i++) {
        if(A[i] != INF && A[i] >= D[yakult[i]]) ans = min(ans, yakult[i]);
    }
    
    cout << ((ans > V) ? -1 : ans);

    return 0;
}
