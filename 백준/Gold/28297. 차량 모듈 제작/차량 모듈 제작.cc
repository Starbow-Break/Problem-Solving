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

const double PI = acos(-1);

struct gear {
    int x, y, r;
};

struct edge {
    int u, v; double d;
    
    bool operator<(edge &e) {
        return d < e.d;
    }
};

vector<edge> edges;
int parent[1000] = {0, };

int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
    
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<gear> gears(N);
    
    for(int i = 0; i < N; i++) {
        int x, y, r; cin >> x >> y >> r;
        gears[i] = {x, y, r};
        parent[i] = i;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            double d = sqrt(
                (gears[i].x-gears[j].x)*(gears[i].x-gears[j].x)
                +(gears[i].y-gears[j].y)*(gears[i].y-gears[j].y)
            );
            
            if(d <= gears[i].r+gears[j].r) {
                edges.pb({i, j, 0});
            }
            else {
                double theta = acos(abs(gears[i].r-gears[j].r)/d);
                double len = 0;
                len += 2*d*sin(theta);
                int r1 = max(gears[i].r, gears[j].r);
                int r2 = min(gears[i].r, gears[j].r);
                len += r1*(2*PI-2*theta);
                len += r2*(2*theta);
                edges.pb({i, j, len});
            }
        }
    }
    
    sort(all(edges));
    
    double ans = 0; int cnt = 0;
    for(auto &e: edges) {
        if(cnt == N-1) break;
        if(findRoot(e.u) != findRoot(e.v)) {
            ans += e.d;
            merge(e.u, e.v);
            cnt++;
        }
    }
    
    cout << fixed << setprecision(12) << ans;
    
    return 0;
}