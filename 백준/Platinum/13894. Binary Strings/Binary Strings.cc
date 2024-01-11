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

const int MOD = 1'000'000'007;

ll dp[60][4] = {0, };
ll dp1[60][4] = {0, };
ll dp2[60][4] = {0, };

ll solve(ll l, ll r, ll _k) {
    vector<ll> part(4), left(4), leftTotal(4), right(4), rightTotal(4);
    
    ll k = _k; bool flag = false;
    int idx = 0;
    while(k > 0) {
        if(k&1) {
            if(flag) {
                vector<ll> temp(4);
                temp[0] += part[0]*(dp[idx][0]+dp[idx][2])+part[1]*dp[idx][0];
                temp[0] %= MOD;
                temp[1] += part[0]*(dp[idx][1]+dp[idx][3])+part[1]*dp[idx][1];
                temp[1] %= MOD;
                temp[2] += part[2]*(dp[idx][0]+dp[idx][2])+part[3]*dp[idx][0];
                temp[2] %= MOD;
                temp[3] += part[2]*(dp[idx][1]+dp[idx][3])+part[3]*dp[idx][1];
                temp[3] %= MOD;
                
                for(int i = 0; i < 4; i++) part[i] = temp[i];
            }
            else {
                for(int i = 0; i < 4; i++) {
                    part[i] = dp[idx][i];
                }
                flag = true;
            }
        }
        
        k >>= 1; idx++;
    }
    
    // for(int i = 0; i < 4; i++) cout << part[i] << ' ';
    // cout << '\n';
    
    for(int i = 0; i < 4; i++) {
        dp1[0][i] = part[i];
        dp2[0][i] = part[i];
    }
    
    for(int i = 1; i < 60; i++) {
        for(int j = 0; j < 4; j++) {
            dp1[i][j] = 0; dp2[i][j] = 0;
        }
        dp1[i][0] += dp1[i-1][0]*(dp1[i-1][0]+dp1[i-1][2])+dp1[i-1][1]*dp1[i-1][0];
        dp1[i][0] %= MOD;
        dp1[i][1] += dp1[i-1][0]*(dp1[i-1][1]+dp1[i-1][3])+dp1[i-1][1]*dp1[i-1][1];
        dp1[i][1] %= MOD;
        dp1[i][2] += dp1[i-1][2]*(dp1[i-1][0]+dp1[i-1][2])+dp1[i-1][3]*dp1[i-1][0];
        dp1[i][2] %= MOD;
        dp1[i][3] += dp1[i-1][2]*(dp1[i-1][1]+dp1[i-1][3])+dp1[i-1][3]*dp1[i-1][1];
        dp1[i][3] %= MOD;
        
        dp2[i][0] += dp2[i-1][0]*(dp1[i-1][0]+dp1[i-1][2])+dp2[i-1][1]*dp1[i-1][0];
        dp2[i][0] += dp2[i-1][0]; dp2[i][0] %= MOD;
        dp2[i][1] += dp2[i-1][0]*(dp1[i-1][1]+dp1[i-1][3])+dp2[i-1][1]*dp1[i-1][1];
        dp2[i][1] += dp2[i-1][1]; dp2[i][1] %= MOD;
        dp2[i][2] += dp2[i-1][2]*(dp1[i-1][0]+dp1[i-1][2])+dp2[i-1][3]*dp1[i-1][0];
        dp2[i][2] += dp2[i-1][2]; dp2[i][2] %= MOD;
        dp2[i][3] += dp2[i-1][2]*(dp1[i-1][1]+dp1[i-1][3])+dp2[i-1][3]*dp1[i-1][1];
        dp2[i][3] += dp2[i-1][3]; dp2[i][3] %= MOD;
    }
    
    k = r/_k; flag = false; idx = 0;
    while(k > 0) {
        if(k&1) {
            if(flag) {
                vector<ll> temp(4), tempTotal(4);
                temp[0] += dp1[idx][0]*(right[0]+right[2])+dp1[idx][1]*right[0];
                temp[0] %= MOD;
                temp[1] += dp1[idx][0]*(right[1]+right[3])+dp1[idx][1]*right[1];
                temp[1] %= MOD;
                temp[2] += dp1[idx][2]*(right[0]+right[2])+dp1[idx][3]*right[0];
                temp[2] %= MOD;
                temp[3] += dp1[idx][2]*(right[1]+right[3])+dp1[idx][3]*right[1];
                temp[3] %= MOD;

                tempTotal[0] += dp2[idx][0]*(right[0]+right[2])+dp2[idx][1]*right[0];
                tempTotal[0] += rightTotal[0]; tempTotal[0] %= MOD;
                tempTotal[1] += dp2[idx][0]*(right[1]+right[3])+dp2[idx][1]*right[1];
                tempTotal[1] += rightTotal[1]; tempTotal[1] %= MOD;
                tempTotal[2] += dp2[idx][2]*(right[0]+right[2])+dp2[idx][3]*right[0];
                tempTotal[2] += rightTotal[2]; tempTotal[2] %= MOD;
                tempTotal[3] += dp2[idx][2]*(right[1]+right[3])+dp2[idx][3]*right[1];
                tempTotal[3] += rightTotal[3]; tempTotal[3] %= MOD;
                
                for(int i = 0; i < 4; i++) {
                    right[i] = temp[i];
                    rightTotal[i] = tempTotal[i];
                }
            }
            else {
                for(int i = 0; i < 4; i++) {
                    right[i] = dp1[idx][i];
                    rightTotal[i] = dp2[idx][i];
                }
                flag = true;
            }
        }
        
        k >>= 1; idx++;
    }
    
    k = (l-1)/_k; flag = false; idx = 0;
    while(k > 0) {
        if(k&1) {
            if(flag) {
                vector<ll> temp(4), tempTotal(4);
                temp[0] += dp1[idx][0]*(left[0]+left[2])+dp1[idx][1]*left[0];
                temp[0] %= MOD;
                temp[1] += dp1[idx][0]*(left[1]+left[3])+dp1[idx][1]*left[1];
                temp[1] %= MOD;
                temp[2] += dp1[idx][2]*(left[0]+left[2])+dp1[idx][3]*left[0];
                temp[2] %= MOD;
                temp[3] += dp1[idx][2]*(left[1]+left[3])+dp1[idx][3]*left[1];
                temp[3] %= MOD;
                
                tempTotal[0] += dp2[idx][0]*(left[0]+left[2])+dp2[idx][1]*left[0];
                tempTotal[0] += leftTotal[0]; tempTotal[0] %= MOD;
                tempTotal[1] += dp2[idx][0]*(left[1]+left[3])+dp2[idx][1]*left[1];
                tempTotal[1] += leftTotal[1]; tempTotal[1] %= MOD;
                tempTotal[2] += dp2[idx][2]*(left[0]+left[2])+dp2[idx][3]*left[0];
                tempTotal[2] += leftTotal[2]; tempTotal[2] %= MOD;
                tempTotal[3] += dp2[idx][2]*(left[1]+left[3])+dp2[idx][3]*left[1];
                tempTotal[3] += leftTotal[3]; tempTotal[3] %= MOD;
                
                for(int i = 0; i < 4; i++) {
                    left[i] = temp[i];
                    leftTotal[i] = tempTotal[i];
                }
            }
            else {
                for(int i = 0; i < 4; i++) {
                    left[i] = dp1[idx][i];
                    leftTotal[i] = dp2[idx][i];
                }
                flag = true;
            }
        }
        
        k >>= 1; idx++;
    }
    
    // for(int i = 0; i < 4; i++) {
    //     cout << left[i] << ' ' << leftTotal[i] << ' ' << right[i] << ' ' << rightTotal[i] << '\n';
    // }
    
    ll ans = 0;
    for(int i = 0; i < 4; i++) {
        ans += rightTotal[i]+MOD-leftTotal[i]; ans %= MOD;
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0][0] = dp[0][3] = 1;
    dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i < 60; i++) {
        dp[i][0] += dp[i-1][0]*(dp[i-1][0]+dp[i-1][2])+dp[i-1][1]*dp[i-1][0];
        dp[i][0] %= MOD;
        dp[i][1] += dp[i-1][0]*(dp[i-1][1]+dp[i-1][3])+dp[i-1][1]*dp[i-1][1];
        dp[i][1] %= MOD;
        dp[i][2] += dp[i-1][2]*(dp[i-1][0]+dp[i-1][2])+dp[i-1][3]*dp[i-1][0];
        dp[i][2] %= MOD;
        dp[i][3] += dp[i-1][2]*(dp[i-1][1]+dp[i-1][3])+dp[i-1][3]*dp[i-1][1];
        dp[i][3] %= MOD;
    }
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        ll L, R, K; cin >> L >> R >> K;
        cout << "Case " << tc << ": " << solve(L, R, K) << '\n';
    }
    
    return 0;
}
