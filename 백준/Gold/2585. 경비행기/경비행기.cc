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

int n, k; 
vector<pii> pts;
int bfs(int s, int f, int l) {
    int visited[1002];
    fill(visited, visited+n+2, -1);
    queue<int> q;
    q.push(s); visited[s] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == f) return visited[cur];
        for(int i = 1; i <= n+1; i++) {
            if(visited[i] >= 0) continue;
            int d = ceil(sqrt((pts[cur].fi-pts[i].fi)*(pts[cur].fi-pts[i].fi)
            +(pts[cur].se-pts[i].se)*(pts[cur].se-pts[i].se))/10);
            if(d <= l) {
                q.push(i);
                visited[i] = visited[cur]+1;
            }
        }
    }
    return 100'000'000;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    pts.pb({0, 0});
    repeat(n) {
        int x, y; cin >> x >> y;
        pts.pb({x, y});
    }
    pts.pb({10000, 10000});
    
    int i = 1, j = 15000;
    while(i <= j) {
        int mid = i+j >> 1;
        int result = bfs(0, n+1, mid);
        if(result <= k+1) j = mid-1;
        else i = mid+1;
    }
    
    cout << i;
    
    return 0;
}
