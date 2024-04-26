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

// dp[i] = 0~10^i-1 에서 금민수의 갯수
int dp[10];

int solve(int v) {
    
    int idx = 0;
    int w = 1;
    int ret = 0;
    
    while(true) {
        int q = v/w;
        if(q < 10) {
            if(idx > 0)
                ret += ((q > 0)+(q > 4)+(q > 7))*dp[idx];
            else
                ret += ((q >= 4)+(q >= 7));
            if(!(q == 4 || q == 7)) break;
            
            v -= q*w;
            idx--; w /= 10;
                
            while(idx >= 0) {
                int qq = v/w;
                if(idx > 0)
                    ret += ((qq > 4)+(qq > 7))*dp[idx];
                else
                    ret += ((qq >= 4)+(qq >= 7));
                
                if(!(qq == 4 || qq == 7)) break;
                
                v -= qq*w;
                idx--; w /= 10;
            }
            break;
        }
        else {
            ret += dp[idx];
        }
        
        idx++;
        w *= 10;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0] = 0; dp[1] = 2;
    for(int i = 2; i <= 9; i++) {
        dp[i] = 2*dp[i-1];
    }

    int l, r; cin >> l >> r;
    cout << solve(r)-solve(l-1);
    
    return 0;
}
