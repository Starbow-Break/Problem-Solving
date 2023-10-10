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
    
    int N; cin >> N;
    vector<pii> vec;
    repeat(N) {
        int t, s; cin >> t >> s;
        vec.pb({s, t});
    }
    
    sort(rall(vec));
    
    int ans = 1e9;
    for(auto &v: vec) {
        if(v.fi < ans) {
            ans = v.fi;
        }
        ans -= v.se;
    }
    
    cout << (ans < 0 ? -1 : ans);
    
    return 0;
}