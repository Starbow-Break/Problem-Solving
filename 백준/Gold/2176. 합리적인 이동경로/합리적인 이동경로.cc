#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end();
#define rall(vec) vec.rbegin(), vec.rend();
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using int128 = __int128_t;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

const int INF = 1'000'000'000;

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.second > b.second;
    }
};

int d[1001];
int dp[1001] = {0, };
vector<pii> edges[1001];

struct cmp1 {
    bool operator()(pii &a, pii &b) {
        return d[a.first] < d[b.first];
    }
};

void dijkstra(int start) {
    fill(d, d+1001, INF);
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({start, 0}); d[start] = 0;
    while(!pq.empty()) {
        int cur = pq.top().first;
        int dist = pq.top().second;
        pq.pop();
        if(d[cur] < dist) continue;
        for(auto &[next, w]: edges[cur]) {
            if(d[next] > dist+w) {
                pq.push({next, dist+w});
                d[next] = dist+w;
            }
        }
    }
}

void solve(int start) {
    priority_queue<pii, vector<pii>, cmp1> pq;
    pq.push({start, 1}); dp[start] = 1;
    while(!pq.empty()) {
        int cur = pq.top().first;
        int num = pq.top().second;
        pq.pop();
        if(dp[cur] > num) continue;
        for(auto &[next, w]: edges[cur]) {
            if(d[cur] > d[next]) {
                dp[next] += dp[cur];
                pq.push({next, dp[next]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }
    
    dijkstra(2);
    
    solve(1);
    
    cout << dp[2];

    return 0;
}