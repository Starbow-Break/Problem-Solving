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

ll powA[60];
ll sumA[60];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll m, a, c, X0, n, g; cin >> m >> a >> c >> X0 >> n >> g;
    
    powA[0] = a%m;
    for(int i = 1; i < 60; i++) {
        powA[i] = (int128)powA[i-1]*powA[i-1]%m;
    }
    
    sumA[0] = 1;
    for(int i = 1; i < 60; i++) {
        sumA[i] = ((int128)powA[i-1]*sumA[i-1]+sumA[i-1])%m;
    }
    
    int128 Xn = 0;
    ll temp = n; int128 value = 1; int idx = 0;
    while(temp) {
        if(temp&1) {
            value *= powA[idx];
            value %= m;
        }
        
        temp >>= 1;
        idx++;
    }
    
    Xn += value*X0; Xn %= m;
    
    temp = n; value = 0; idx = 0;
    int128 w = 1;
    while(temp) {
        if(temp&1) {
            value += w*sumA[idx];
            value %= m;
            
            w *= powA[idx];
            w %= m;
        }
        
        temp >>= 1;
        idx++;
    }
    
    Xn += value*c; Xn %= m;
    
    ll ans = Xn%g;
    cout << ans;
    
    return 0;
}