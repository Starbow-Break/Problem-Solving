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

//dp[i] = 0000000...0을 1000000...0으로 만들기 위한 최소횟수
ll dp[32] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[1] = 1;
    for(int i = 2; i <= 30; i++) {
        dp[i] = 2*dp[i-1]+1;
    }
    
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        int len = s.length();
        ll ans = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] == '1') {
                int t = 0;
                for(int j = i; j < len; j++) {
                    if('0'+t != s[j]) {
                        ans += dp[len-j-1]+1;
                        t = 1;
                    }
                    else t = 0;
                }
                
                break;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
