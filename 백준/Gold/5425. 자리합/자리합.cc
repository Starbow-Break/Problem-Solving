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

ll arr[15];

ll solve(ll b) {
    if(b <= 0) return 0;
    if(b > 0 && b < 10) return b*(b+1)/2;
    
    ll cnt = 0, q, r = 0, w = 1;
    while(b >= 10) {
        cnt++;
        r += w*(b%10);
        b /= 10;
        w *= 10;
    }
    q = b;
    
    return (q-1)*q/2*(ll)pow(10, cnt)+q*arr[cnt]+q*(r+1)+solve(r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    arr[1] = 45;
    for(int i = 2; i < 16; i++) {
        arr[i] = arr[i-1]*10+45*(ll)pow(10, i-1);
    }
    
    int T; cin >> T;
    while(T--) {
        ll a, b; cin >> a >> b;
        cout << solve(b)-solve(a-1) << '\n';
    }
    
    return 0;
}