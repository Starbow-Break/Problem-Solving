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

const int MOD = 1'000'000;
int dp[304][304][304] = {0, }; // 위, 중간, 아래 행 채운 칸 수 (연속으로)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    dp[0][0][0] = 1;
    for(int a = 0; a <= 300; a++) {
        for(int b = 0; b <= 300; b++) {
            for(int c = 0; c <= 300; c++) {
                if(a == b) {
                    dp[a+2][b+2][c] += dp[a][b][c];
                    dp[a+2][b+2][c] %= MOD;
                    
                    dp[a+3][b+1][c] += dp[a][b][c];
                    dp[a+3][b+1][c] %= MOD;
                    
                    dp[a+1][b+3][c] += dp[a][b][c];
                    dp[a+1][b+3][c] %= MOD;
                }
                if(b == c) {
                    dp[a][b+2][c+2] += dp[a][b][c];
                    dp[a][b+2][c+2] %= MOD;
                    
                    dp[a][b+3][c+1] += dp[a][b][c];
                    dp[a][b+3][c+1] %= MOD;
                    
                    dp[a][b+1][c+3] += dp[a][b][c];
                    dp[a][b+1][c+3] %= MOD;
                }
                if(a == b+1) {
                    dp[a+2][b+2][c] += dp[a][b][c];
                    dp[a+2][b+2][c] %= MOD;
                    
                    dp[a+1][b+3][c] += dp[a][b][c];
                    dp[a+1][b+3][c] %= MOD;
                }
                if(b == c+1) {
                    dp[a][b+2][c+2] += dp[a][b][c];
                    dp[a][b+2][c+2] %= MOD;
                    
                    dp[a][b+1][c+3] += dp[a][b][c];
                    dp[a][b+1][c+3] %= MOD;
                }
                if(a == b && b+1 == c) {
                    dp[a+1][b+2][c+1] += dp[a][b][c];
                    dp[a+1][b+2][c+1] %= MOD;
                }
                if(a+1 == b) {
                    dp[a+2][b+2][c] += dp[a][b][c];
                    dp[a+2][b+2][c] %= MOD;
                    
                    dp[a+3][b+1][c] += dp[a][b][c];
                    dp[a+3][b+1][c] %= MOD;
                }
                if(b+1 == c) {
                    dp[a][b+2][c+2] += dp[a][b][c];
                    dp[a][b+2][c+2] %= MOD;
                    
                    dp[a][b+3][c+1] += dp[a][b][c];
                    dp[a][b+3][c+1] %= MOD;
                }
                if(a == b+1 && b == c) {
                    dp[a+1][b+2][c+1] += dp[a][b][c];
                    dp[a+1][b+2][c+1] %= MOD;
                }
                if(a == b && b == c) {
                    dp[a+1][b+2][a+1] += dp[a][b][c];
                    dp[a+1][b+2][a+1] %= MOD;
                    
                    dp[a+2][b+1][c+1] += dp[a][b][c];
                    dp[a+2][b+1][c+1] %= MOD;
                    
                    dp[a+1][b+1][c+2] += dp[a][b][c];
                    dp[a+1][b+1][c+2] %= MOD;
                }
                if(a == b+1 && b+1 == c) {
                    dp[a+1][b+2][a+1] += dp[a][b][c];
                    dp[a+1][b+2][a+1] %= MOD;
                }
                if(b == c+2) {
                    dp[a][b+1][c+3] += dp[a][b][c];
                    dp[a][b+1][c+3] %= MOD;
                }
                if(c == b+2) {
                    dp[a][b+3][c+1] += dp[a][b][c];
                    dp[a][b+3][c+1] %= MOD;
                }
                if(a == b+2) {
                    dp[a+1][b+3][c] += dp[a][b][c];
                    dp[a+1][b+3][c] %= MOD;
                }
                if(a+2 == b) {
                    dp[a+3][b+1][c] += dp[a][b][c];
                    dp[a+3][b+1][c] %= MOD;
                }
                if(a == b && c+1 == b) {
                    dp[a+1][b+1][c+2] += dp[a][b][c];
                    dp[a+1][b+1][c+2] %= MOD;
                }
                if(b == c && a+1 == b) {
                    dp[a+2][b+1][c+1] += dp[a][b][c];
                    dp[a+2][b+1][c+1] %= MOD;
                }
            }
        }
    }
    
    cout << dp[N][N][N];
    
    return 0;
}