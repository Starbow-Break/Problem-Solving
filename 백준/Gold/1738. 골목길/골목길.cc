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

vector<pii> edges[101];
int dist[101];
int previous[101] = {0, };
bool possible;

const int INF = 1'000'000'000;

void progress(int cur) {
    for(auto &[next, w]: edges[cur]) {
        if(dist[next] > dist[cur]+w) {
            dist[next] = dist[cur]+w;
            previous[next] = cur;
        }
    }
}

bool checkPossible(int num) {
    int temp; temp = dist[num];
    
    for(int cnt = 1; cnt <= 3000; cnt++) {
        for(int i = 1; i <= num; i++) {
            progress(i);
        }
    }
    
    if(temp != dist[num]) return false;
    
    return true;
}

void bellmanFord(int num) {
    fill(dist+1, dist+num+1, INF);
    dist[1] = 0;
    
    for(int cnt = 1; cnt <= num; cnt++) {
        for(int i = 1; i <= num; i++) {
            progress(i);
        }
    }
    
    possible = checkPossible(num);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    while(M--) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].pb({v, -w});
    }
    
    bellmanFord(N);
    
    if(possible) {
        vector<int> ans;
        int cur = N; bool check = false;
        while(cur != 0) {
            ans.pb(cur);
            if(cur == 1) check = true;
            cur = previous[cur];
        }
        if(check) {
            reverse(all(ans));
            for(auto &v: ans) cout << v << ' ';
        }
        else cout << -1;
    }
    else {
        cout << -1;
    }
    
    return 0;
}