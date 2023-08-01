#include <bits/stdc++.h>
#define repeat(i, s, e) for(int i = s; i < e; i++)
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

ll modPow(ll A, ll X) {
    ll w = A, ret = 1;
    while(X > 0) {
        if(X%2) {
            ret *= w;
            ret %= MOD;
        }
        
        w *= w; w %= MOD;
        X /= 2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll A, X; cin >> A >> X;
    cout << modPow(A%MOD, X);
    
    return 0;
}