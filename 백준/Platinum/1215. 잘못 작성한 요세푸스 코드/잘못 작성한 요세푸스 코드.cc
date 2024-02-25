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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    ll ans = 0;
    
    int q = floor(sqrt(k));
    
    for(int i = 1; i <= min(n, k/q); i++) {
        ans += k%i;
    }
    
    int r = n;
    for(int i = 0; i < q; i++) {
        int l = k/(i+1)+1;
        if(l <= r) {
            if(i == 0) {
                ans += 1LL*(r-l+1)*k;
            }
            else {
                int ll = k%l, rr = k%r;
                ans += 1LL*(rr+ll)*(r-l+1)/2;
            }
            
            r = l-1;
        }
    }
    
    
    cout << ans;
    
    return 0;
}