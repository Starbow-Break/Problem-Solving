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

ll dp[60][32][32] = {0, };
ll ans[32][32] = {0, };

bool check(int sz, int l, int r) {
    for(int i = 0; i < sz-1; i++) {
        int v = 1<<i | 1<<(i+1);
        if((l & v) == v && (r & v) == v) {
            return false;
        }
        
        if((~l & v) == v && (~r & v) == v) {
            return false;
        }
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, M; cin >> N >> M;
    for(int i = 0; i < (1<<M); i++) {
        dp[0][i][i] = 1;
    }
    
    for(int i = 1; i < 60; i++) {
        for(int l = 0; l < (1<<M); l++) {
            for(int r = 0; r < (1<<M); r++) {
                if(check(M, l, r)) {
                    for(int a = 0; a < (1<<M); a++) {
                        for(int b = 0; b < (1<<M); b++) {
                            dp[i][a][b] += dp[i-1][a][l]*dp[i-1][r][b];
                            dp[i][a][b] %= MOD;
                        }
                    }
                }
            }
        }
    }
    
    int idx = 0; bool flag = false;
    while(N) {
        if(N&1) {
            if(flag) {
                ll temp[32][32] = {0, };
                for(int l = 0; l < (1<<M); l++) {
                    for(int r = 0; r < (1<<M); r++) {
                        if(check(M, l, r)) {
                            for(int a = 0; a < (1<<M); a++) {
                                for(int b = 0; b < (1<<M); b++) {
                                    temp[a][b] += ans[a][l]*dp[idx][r][b];
                                    temp[a][b] %= MOD;
                                }
                            }
                        }
                    }
                }
                
                for(int l = 0; l < (1<<M); l++) {
                    for(int r = 0; r < (1<<M); r++) {
                        ans[l][r] = temp[l][r];
                    }
                }
            }
            else {
                for(int l = 0; l < (1<<M); l++) {
                    for(int r = 0; r < (1<<M); r++) {
                        ans[l][r] = dp[idx][l][r];
                    }
                }
            }
            
            flag = true;
        }
        
        N >>= 1;
        idx++;
    }
    
    ll total = 0;
    for(int l = 0; l < (1<<M); l++) {
        for(int r = 0; r < (1<<M); r++) {
            total += ans[l][r];
            total %= MOD;
        }
    }
    
    cout << total;
    
    return 0;
}