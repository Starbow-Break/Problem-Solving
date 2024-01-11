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

ll dp[26][51] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; ll K; cin >> N >> K;
    for(int i = N/2; i >= 1; i--) {
        for(int j = 2*i-1; j >= i; j--) {
            if(i == N/2) dp[i][j] = 1;
            else {
                for(int k = j+1; k <= N; k++) {
                    dp[i][j] += dp[i+1][k];
                }
            }
        }
    }
    
    vector<int> ans(N+1); char arr[2] = {')', '('};
    if(K >= dp[1][1]) cout << -1;
    else {
        int idx = 1;
        for(int i = 1; i <= N/2; i++) {
            while(idx <= N) {
                if(K >= dp[i][idx]) { K -= dp[i][idx]; idx++; }
                else { ans[idx] = 1; idx++; break; }
            }
        }
        
        for(int i = 1; i <= N; i++) cout << arr[ans[i]];
    }
    
    return 0;
}
