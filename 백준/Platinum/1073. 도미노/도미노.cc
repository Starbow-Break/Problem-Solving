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

int order[10] = {0, };
ll dp[45] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int v; cin >> v;
        order[v/10]++; order[v%10]++;
    }
    
    dp[0] = 1;
    for(int i = 2; i <= 44; i += 2) {
        dp[i] = dp[i-2] * (i-1);
    }
    
    ll ans = 1;
    FOR(i, 0, 10) {
        ans *= dp[order[i]];
    }
    
    cout << ans;
    
    return 0;
}