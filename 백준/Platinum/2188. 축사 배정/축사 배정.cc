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

vector<int> vec[201];
int connect[201] = {0, };
bool visited[201];

bool dfs(int cur) {
    visited[cur] = true;
    
    for(auto &v: vec[cur]) {
        if(connect[v] == 0 || (!visited[connect[v]] && dfs(connect[v]))) {
            connect[v] = cur;
            return true;
        }
    }
    
    return false;
}

int binaryMatching(int sz) {
    int ret = 0;
    for(int i = 1; i <= sz; i++) {
        fill(visited+1, visited+sz+1, false);
        ret += dfs(i);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        int num; cin >> num;
        while(num--) {
            int v; cin >> v;
            vec[i].pb(v);
        }
    }
    
    cout << binaryMatching(N);
    
    return 0;
}