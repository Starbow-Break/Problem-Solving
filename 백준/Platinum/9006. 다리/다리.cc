#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v: vec)
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
    while(T--) {
        int N, M; cin >> N >> M;
        
        vector<pii> pos;
        repeat(N) {
            int v; cin >> v;
            pos.pb({v, 'L'});
        }
        repeat(M) {
            int v; cin >> v;
            pos.pb({v, 'R'});
        }
        
        sort(all(pos));
        
        ll slope = -2LL*N*M ; float x = -1e9;
        FORIter(v, pos) {
            slope += 2 * (v.se == 'L' ? M : N); x = v.fi;
            if(slope >= 0) break;
        }
        
        cout << fixed << setprecision(1) << x << '\n';
    }
    
    return 0;
}
