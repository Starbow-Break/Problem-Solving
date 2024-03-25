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

const ll BASE = 1e13;
ll ans[100'000] = {0, }; int r = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ans[0] = 1;
    
    int N; cin >> N;
    for(int i = 2; i <= N; i++) {
        ll c = 0;
        for(int j = 0; j <= r; j++) {
            ans[j] = ans[j] * i + c;
            c = ans[j]/BASE;
            ans[j] %= BASE;
        }
        
        if(c) { ans[r+1] = c; r++; }
    }
    
    for(int i = r; i >= 0; i--) {
        for(ll j = BASE/10; j >= 1; j /= 10) {
            if(ans[i]/j) {
                cout << ans[i]%(10*j)/j;
            }
            else {
                if(i != r) cout << 0;
            }
        }
    }
    
    return 0;
}