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

vector<int> edges[300'001];
int dep[300'001] = {0, };
ll sumDep[300'001] = {0, };
int sz[300'001] = {0, };

ll ans = 0;
void dfs(int cur, int bef = -1) {
    sz[cur]++;
    vector<ll> vec, vecSz;
    vec.pb(0); vecSz.pb(0);
    
    for(auto &next: edges[cur]) {
        if(bef != next) {
            dep[next] = dep[cur] + 1;
            dfs(next, cur);
            sz[cur] += sz[next];
            sumDep[cur] += sumDep[next]+sz[next];
            vec.pb(sumDep[next]+sz[next]);
            vecSz.pb(sz[next]);
        }
    }
    
    for(int i = 1; i < vec.size(); i++) {
        vec[i] += vec[i-1];
        vecSz[i] += vecSz[i-1];
    }
    
    for(int i = 1; i < vec.size(); i++) {
        ans += (vecSz.back()-vecSz[i])*(vec[i]-vec[i-1])+(vecSz[i]-vecSz[i-1])*(vec.back()-vec[i]);
        ans += (vecSz.back()-vecSz[i])*(vecSz[i]-vecSz[i-1])*dep[cur];
    }
    ans += vec.back()+vecSz.back()*dep[cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        edges[a].pb(b); edges[b].pb(a);
    }
    
    dfs(1);
    
    cout << ans;
    
    return 0;
}