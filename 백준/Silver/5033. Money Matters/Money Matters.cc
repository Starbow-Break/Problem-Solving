#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v: vec)
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

int g[10'001] = {0, }, money[10'001];

vector<int> edges[10'000];
vector<int> group[10'001];

int ord = 0;
void dfs(int cur) {
    g[cur] = ord;
    FORIter(nxt, edges[cur]) {
        if(!g[nxt]) dfs(nxt);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    FOR(i, 0, n) {
        cin >> money[i];
    }
    
    FOR(i, 0, m) {
        int a, b; cin >> a >> b;
        edges[a].pb(b); edges[b].pb(a);
    }
    
    FOR(i, 0, n) {
        if(!g[i]) {
            ord++;
            dfs(i);
        }
    }
    
    bool check = true;
    
    FOR(i, 0, n) {
        group[g[i]].pb(i);
    }
    
    FOR(i, 1, ord+1) {
        int total = 0;
        FORIter(v, group[i]) {
            total += money[v];
        }
        
        if(total != 0) {
            check = false;
            break;
        }
    }
    
    cout << (check ? "POSSIBLE" : "IMPOSSIBLE");
    
    return 0;
}