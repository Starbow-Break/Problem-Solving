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

set<ll> visited;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll x, N; cin >> x >> N;
    
    visited.insert(x);
    while(N > 0) {
        N--;
        if(x%2) x = (2*x)^6LL;
        else x = (x/2)^6LL;
        
        if(visited.find(x) != visited.end()) {
            break;
        }
        visited.insert(x);
    }
    
    if(N) {
        vector<ll> loop;
        visited.clear();
        visited.insert(x);
        loop.pb(x);
        while(1) {
            if(x%2) x = (2*x)^6;
            else x = (x/2)^6;
        
            if(visited.find(x) != visited.end()) {
                break;
            }
            visited.insert(x);
            loop.pb(x);
        }
        
        cout << loop[N%((int)loop.size())];
    }
    else cout << x;
    
    return 0;
}
