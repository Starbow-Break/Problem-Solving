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
    
    int T; cin >> T;
    FOR(tc, 1, T+1) {
        int N, K; cin >> N >> K;
        vector<int> vec;
        repeat(N) {
            int v; cin >> v;
            vec.pb(v);
        }
        vector<int> d;
        
        for(auto &v: vec) {
            auto t = lower_bound(d.begin(), d.end(), v);
            if(t == d.end()) d.pb(v);
            else *t = v;
        }
        
        cout << "Case #" << tc << '\n';
        cout << (d.size() >= K) << '\n';
    }
    
    return 0;
}