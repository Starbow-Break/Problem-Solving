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

struct node {
    bool isCannon;
    pdd pos;
};

vector<node> nodes;


double calc(int a, int b) {
    double d = sqrt(pow(nodes[a].pos.fi-nodes[b].pos.fi, 2)+pow(nodes[a].pos.se-nodes[b].pos.se, 2));
    double ret = d/5;
    if(nodes[a].isCannon) ret = min(ret, abs(d-50)/5+2);
    return ret;
}

double dijkstra(int s, int e) {
    double dist[102];
    fill(dist, dist+102, 1e9);
    priority_queue<pdd> pq;
    pq.push({0, s}); dist[s] = 0;
    while(!pq.empty()) {
        double d = -pq.top().fi;
        int cur = pq.top().se;
        pq.pop();
        
        if(dist[cur] < d) continue;
        
        if(cur == e) return dist[e];
        
        for(int next = 0; next < nodes.size(); next++) {
            if(next != cur) {
                double delta = calc(cur, next);
                if(delta+d < dist[next]) {
                    dist[next] = delta+d;
                    pq.push({-dist[next], next});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    double x, y;
    cin >> x >> y;
    nodes.pb({false, {x, y}});
    cin >> x >> y;
    nodes.pb({false, {x, y}});
    
    int n; cin >> n;
    while(n--) {
        cin >> x >> y;
        nodes.pb({true, {x, y}});
    }
    
    cout << fixed << setprecision(12) << dijkstra(0, 1);
    
    return 0;
}
