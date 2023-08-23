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

const int UP = 0;
const int DOWN = 1;
const int LEFT= 2;
const int RIGHT = 3;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int N, K, R;
int road[101][101] = {0, };
int cow[101][101] = {0, };
pii pos[10001];
int parent[10001];
int visited[101][101] = {0, };

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

int ord = 0;
void bfs(int v) {
    ord++;
    queue<pii> q;
    q.push(pos[v]); visited[pos[v].fi][pos[v].se] = ord;
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        if(cow[cur.fi][cur.se]) {
            merge(v, cow[cur.fi][cur.se]);
        }
        for(int k = 0; k < 4; k++) {
            if(1 <= cur.fi+dr[k] && cur.fi+dr[k] <= N && 1 <= cur.se+dc[k] && cur.se+dc[k] <= N) {
                if(!(road[cur.fi][cur.se] & 1<<k) && visited[cur.fi+dr[k]][cur.se+dc[k]] != ord) {
                    q.push({cur.fi+dr[k], cur.se+dc[k]});
                    visited[cur.fi+dr[k]][cur.se+dc[k]] = ord;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K >> R;
    repeat(R) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if(r1 == r2) {
            if(c1 < c2) {
                road[r1][c1] |= 1<<RIGHT;
                road[r2][c2] |= 1<<LEFT;
            }
            else {
                road[r1][c1] |= 1<<LEFT;
                road[r2][c2] |= 1<<RIGHT;
            }
        }
        else {
            if(r1 < r2) {
                road[r1][c1] |= 1<<DOWN;
                road[r2][c2] |= 1<<UP;
            }
            else {
                road[r1][c1] |= 1<<UP;
                road[r2][c2] |= 1<<DOWN;
            }
        }
    }
    
    for(int i = 1; i <= K; i++) {
        int r, c; cin >> r >> c;
        pos[i] = {r, c};
        cow[r][c] = i;
    }
    
    for(int i = 1; i <= K; i++) parent[i] = i;
    
    for(int i = 1; i <= K; i++) {
        if(i == parent[i]) {
            bfs(i);
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= K; i++) {
        for(int j = i+1; j <= K; j++) {
            ans += findRoot(i) != findRoot(j);
        }
    }
    cout << ans;
    
    return 0;
}