#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

struct edge {
    int f, w;
};

struct info {
    int d, cur, bef;
};

struct comp {
    bool operator()(info &A, info &B) {
        return A.d > B.d;
    }
};

int N, M;
vector<edge> edges[1001];
int before[1001] = {0, };
vector<ii> recEdges;

void dijkstra(int start = 1) {
    int D[N+1]; fill(D+1, D+N+1, INF);
    D[start] = 0;
    priority_queue<info, vector<info>, comp> pq;
    pq.push({0, start, -1});
    
    while(!pq.empty()) {
        int cur = pq.top().cur;
        int d = pq.top().d;
        int bef = pq.top().bef;
        pq.pop();
        
        if(before[cur] != 0) continue;
        
        before[cur] = bef;
        for(auto &e: edges[cur]) {
            if(before[e.f] == 0 && D[e.f] > D[cur]+e.w) {
                D[e.f] = D[cur]+e.w;
                pq.push({D[e.f], e.f, cur});
            }
        }
    }
}

void recoverEdges() {
    for(int i = N; i > 1; i--) {
        recEdges.push_back({before[i], i});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    while(M--) {
        int s, f, w; cin >> s >> f >> w;
        edges[s].push_back({f, w});
        edges[f].push_back({s, w});
    }
    
    dijkstra();
    recoverEdges();
    
    cout << recEdges.size() << '\n';
    for(auto &e: recEdges) {
        cout << e.first << " " << e.second << '\n';
    }

    return 0;
}