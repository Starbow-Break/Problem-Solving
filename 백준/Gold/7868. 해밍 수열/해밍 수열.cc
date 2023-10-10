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
    
    ll p[3], i;
    cin >> p[0] >> p[1] >> p[2] >> i;
    vector<ll> H, num[3];
    
    ll cur = 1;
    while(cur >= 1 && cur <= 1e18) {
        num[0].pb(cur);
        cur *= p[0];
    }
    cur = 1;
    while(cur >= 1 && cur <= 1e18) {
        num[1].pb(cur);
        cur *= p[1];
    }
    cur = 1;
    while(cur >= 1 && cur <= 1e18) {
        num[2].pb(cur);
        cur *= p[2];
    }
    
    for(int i = 0; i < num[0].size(); i++) {
        for(int j = 0; j < num[1].size(); j++) {
            for(int k = 0; k < num[2].size(); k++) {
                if(num[0][i]*num[1][j]*num[2][k] < 0) break;
                H.pb(num[0][i]*num[1][j]*num[2][k]);
            }
        }
    }
    
    sort(all(H));
    
    cout << H[i];
    
    return 0;
}