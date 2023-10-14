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

int N;
string s;
vector<pii> edges[200'001];
bool visited[200'001] = {false, };

int dfs(int cur) {
    int ret = 0;
    for(auto &[next, num]: edges[cur]) {
        if(!visited[num]) {
            visited[num] = true;
            if(s[next-1] == '0') ret += dfs(next);
            else ret++;
        }
    }
    
    return ret+(s[cur-1] == '1');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> s;
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        edges[a].pb({b, i});
        edges[b].pb({a, i});
    }
    
    
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        if(s[i-1] == '1') {
            int t = dfs(i);
            ans += 1LL*t*(t-1);
        }
    }
    
    cout << ans;
    
    return 0;
}
