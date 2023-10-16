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

pii solve(int N, ll K, int s, int e, int r) {
    ll t = (1LL << N-1) - 1;
    if(K <= t) {
        return solve(N-1, K, s, r, e);
    }
    
    K -= t;
    if(K == 1) {
        return {s, e};
    }
    
    K--;
    return solve(N-1, K, r, e, s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; ll K; cin >> N >> K;
    pii result = solve(N, K, 1, 3, 2);
    cout << result.fi << ' ' << result.se;
    
    return 0;
}