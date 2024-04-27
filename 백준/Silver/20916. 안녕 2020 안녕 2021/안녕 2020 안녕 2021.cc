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
    
    int hello[12] = {
        202021, 20202021, 202002021, 202012021,
        202022021, 202032021, 202042021, 202052021, 
        202062021, 202072021, 202082021, 202092021,
    };
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        unordered_map<int, int> cnt;
        while(N--) {
            int v; cin >> v;
            
            auto t = cnt.find(v);
            if(t == cnt.end()) {
                cnt.insert({v, 1});
            }
            else t->se++;
        }
        
        ll ans = 0;
        for(auto &[v, w]: cnt) {
            for(int i = 0; i < 12; i++) {
                auto t = cnt.find(hello[i]-v);
                if(t != cnt.end()) {
                    ans += 1LL*w*t->se;
                }
            }
        }
        
        ans /= 2;
        
        cout << ans << '\n';
    }
    
    return 0;
}