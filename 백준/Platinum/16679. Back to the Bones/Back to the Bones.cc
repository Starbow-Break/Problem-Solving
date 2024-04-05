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

ll dp[21][121] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i <= 20; i++) {
        if(i == 0) {
            dp[0][0] = 1;
        }
        else {
            for(int j = 1; j <= 6; j++) {
                for(int k = i-1; k <= 6*(i-1); k++) {
                    dp[i][j+k] += dp[i-1][k];
                }
            }
        }
    }
    
    for(int i = 0; i <= 20; i++) {
        for(int k = 6*i-1; k >= i; k--) {
            dp[i][k] += dp[i][k+1];
        }
    }
    
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        int dice[N+1]; dice[0] = 0;
        vector<pii> vec;
        for(int i = 1; i <= N; i++) {
            cin >> dice[i];
            vec.pb({dice[i], i});
        }
        sort(dice+1, dice+N+1);
        sort(all(vec));
        for(int i = 1; i <= N; i++) dice[i] += dice[i-1];
        
        ll ans = 0, w = 1, idx = 0;
        for(int i = 1; i <= N; i++) w *= 6;
        
        // cout << dice[N] << ' ' << K << '\n';
        if(dice[N] >= K) {
            cout << w << '\n';
            for(int i = 0; i < N; i++) cout << 0 << ' ';
            continue;
        }
        
        for(int i = 1; i <= N; i++) {
            w /= 6;
            
            if(dice[N]-dice[i]+6*i < K) continue;
            
            int target = max(K-(dice[N]-dice[i]), i);
            
            if(ans < w * dp[i][target]) {
                ans = w * dp[i][target];
                idx = i;
            }
        }
        
        bool change[20] = {false, };
        cout << ans << '\n';
        
        for(int i = 0; i < idx; i++) {
            change[vec[i].se-1] = true;
        }
        
        for(int i = 0; i < N; i++) cout << change[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}