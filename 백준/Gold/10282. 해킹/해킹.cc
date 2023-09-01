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

ostream& operator<< (ostream &out, const pii &p) {
    out << p.fi << " " << p.se;
	return out;
}

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.se > b.se;
    }
};

const int INF = 1'000'000'000;

vector<pii> edges[10001];

void init() {
    for(int i = 1; i <= 10000; i++) edges[i].clear();
}

pii dijkstra(int start) {
    pii ret = {0, 0};
    int d[10001]; fill(d, d+10001, INF);
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({start, 0}); d[start] = 0;
    while(!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        if(d[cur.fi] < cur.se) continue;
        ret.fi++; ret.se = cur.se;
        for(auto &[next, w]: edges[cur.fi]) {
            if(d[next] > w+cur.se) {
                d[next] = w+cur.se;
                pq.push({next, d[next]});
            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        init();
        int n, d, c; cin >> n >> d >> c;
        while(d--) {
            int a, b, s; cin >> a >> b >> s;
            edges[b].pb({a, s});
        }
        cout << dijkstra(c) << '\n';
    }
    
    return 0;
}
