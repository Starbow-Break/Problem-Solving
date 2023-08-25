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

int fibo[46];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fibo[0] = 0, fibo[1] = 1;
    for(int i = 2; i <= 45; i++) {
        fibo[i] = fibo[i-1]+fibo[i-2];
    }
    
    int T; cin >> T;
    while(T--) {
        int v; cin >> v;
        vector<int> ans;
        for(int i = 45; i >= 2; i--) {
            while(v >= fibo[i]) {
                ans.pb(fibo[i]);
                v -= fibo[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        for(auto &a: ans) cout << a << ' ';
        cout << '\n';
    }
    
    return 0;
}