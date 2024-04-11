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

const int MOD = 1'000'000'007;

int fib[100'002];

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    return (b ? gcd(b, a%b) : a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    fib[1] = 1; fib[2] = 1;
    
    for(int i = 3; i <= N+1; i++) {
        fib[i] = (fib[i-1]+fib[i-2])%MOD;
    }
    
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += fib[gcd(i+1, N+1)];
        ans %= MOD;
    }
    
    cout << ans;
    
    return 0;
}