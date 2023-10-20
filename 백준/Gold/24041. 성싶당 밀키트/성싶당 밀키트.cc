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

struct ingredient {
    int S, L, O;
};

vector<ingredient> ingredients;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, G, K; cin >> N >> G >> K;
    for(int i = 0; i < N; i++) {
        int S, L, O; cin >> S >> L >> O;
        ingredients.pb({S, L, O});
    }
    
    ll l = 0, r = 2e9;
    while(l <= r) {
        ll mid = l+r >> 1;
        vector<ll> vec;
        ll total = 0;
        for(auto &i : ingredients) {
            int S = i.S, L = i.L, O = i.O;
            ll num = 1LL*S*max(1LL, mid-L);
            if(O) vec.pb(num);
            else total += num;
        }
        
        sort(rall(vec));
        for(int i = K; i < vec.size(); i++) {
            total += vec[i];
        }
        
        if(total > G) r = mid-1;
        else l = mid+1;
    }
    
    cout << r;
    
    return 0;
}