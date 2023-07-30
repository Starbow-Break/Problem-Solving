#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define push_back pb
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

const int INF = 1'000'000'000;

int w[100][100];
int d[100][100][3];

struct node {
    int r, c, s, dist;
};

struct cmp {
    bool operator()(node &a, node &b) {
        return a.dist > b.dist;
    }
};

void dijkstra(int N, int T) {
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({0, 0, 0, 0}); d[0][0][0] = 0;
    
    while(!pq.empty()) {
        node cur = pq.top(); pq.pop();
        int r = cur.r, c = cur.c, s = cur.s, dist = cur.dist;
        if(d[r][c][s] < dist) continue;
        if(r-1 >= 0 && d[r-1][c][(s+1)%3] > d[r][c][s]+T+((s+1)%3 ? 0 : w[r-1][c])) {
            d[r-1][c][(s+1)%3] = d[r][c][s]+T+((s+1)%3 ? 0 : w[r-1][c]);
            pq.push({r-1, c, (s+1)%3, d[r-1][c][(s+1)%3]});
        }
        if(r+1 < N && d[r+1][c][(s+1)%3] > d[r][c][s]+T+((s+1)%3 ? 0 : w[r+1][c])) {
            d[r+1][c][(s+1)%3] = d[r][c][s]+T+((s+1)%3 ? 0 : w[r+1][c]);
            pq.push({r+1, c, (s+1)%3, d[r+1][c][(s+1)%3]});
        }
        if(c-1 >= 0 && d[r][c-1][(s+1)%3] > d[r][c][s]+T+((s+1)%3 ? 0 : w[r][c-1])) {
            d[r][c-1][(s+1)%3] = d[r][c][s]+T+((s+1)%3 ? 0 : w[r][c-1]);
            pq.push({r, c-1, (s+1)%3, d[r][c-1][(s+1)%3]});
        }
        if(c+1 < N && d[r][c+1][(s+1)%3] > d[r][c][s]+T+((s+1)%3 ? 0 : w[r][c+1])) {
            d[r][c+1][(s+1)%3] = d[r][c][s]+T+((s+1)%3 ? 0 : w[r][c+1]);
            pq.push({r, c+1, (s+1)%3, d[r][c+1][(s+1)%3]});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, T; cin >> N >> T;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            cin >> w[r][c];
            fill(d[r][c], d[r][c]+3, INF);
        }
    }
    
    dijkstra(N, T);
    
    cout << min({d[N-1][N-1][0], d[N-1][N-1][1], d[N-1][N-1][2]});
    
    return 0;
}