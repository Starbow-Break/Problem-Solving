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

struct stamp {
    int H, W;
    vector<string> vec;
};

struct query {
    int t, y, x;
};

char ans[1002][1002];
int parent[1002][1002];
vector<stamp> stamps;

int findRoot(int idx, int v) {
    if(parent[idx][v] == v) return v;
    parent[idx][v] = findRoot(idx, parent[idx][v]);
    return parent[idx][v];
}

void merge(int idx, int a, int b) {
    int ra = findRoot(idx, a);
    int rb = findRoot(idx, b);
    if(ra < rb) swap(ra, rb);
    parent[idx][rb] = ra;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            parent[i][j] = j;
            ans[i][j] = '.';
        }
    }
    
    int K; cin >> K;
    while(K--) {
        int H, W; cin >> H >> W;
        vector<string> vec;
        repeat(H) {
            string s; cin >> s;
            vec.pb(s);
        }
        stamps.pb({H, W, vec});
    }
    
    vector<query> queries;
    int Q; cin >> Q;
    repeat(Q) {
        int t, y, x; cin >> t >> y >> x;
        queries.pb({t, y, x});
    }
    reverse(all(queries));
    
    for(auto &q: queries) {
        int t = q.t, y = q.y, x = q.x;
        int u = q.y, d = q.y+stamps[q.t-1].H;
        for(int y = u; y < d; y++) {
            int l = q.x, r = q.x+stamps[q.t-1].W;
            for(int x = l; x < r; x++) {
                while(x < r && findRoot(y, x) != x) x = parent[y][x];
                if(x >= r) break;
                ans[y][x] = stamps[q.t-1].vec[y-u][x-l];
                merge(y, x, x+1);
            }
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) cout << ans[r][c];
        cout << '\n';
    }

    return 0;
}
