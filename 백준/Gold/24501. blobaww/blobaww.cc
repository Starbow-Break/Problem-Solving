#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, M;
char ESM[3000][3001];
ll dp[3000][3000][3] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> ESM[i];
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < 3; k++) {
                if(i > 0) dp[i][j][k] += dp[i-1][j][k];
                if(j > 0) dp[i][j][k] += dp[i][j-1][k];
                if(i > 0 && j > 0) dp[i][j][k] += (MOD-dp[i-1][j-1][k]);
                dp[i][j][k] %= MOD;
            }
            
            if(ESM[i][j] == 'E') {
                dp[i][j][0]++;
                dp[i][j][0] %= MOD;
            }
            else if(ESM[i][j] == 'S') {
                if(i > 0) dp[i][j][1] += dp[i-1][j][0];
                if(j > 0) dp[i][j][1] += dp[i][j-1][0];
                if(i > 0 && j > 0) dp[i][j][1] += (MOD-dp[i-1][j-1][0]);
                dp[i][j][1] %= MOD;
            }
            else {
                if(i > 0) dp[i][j][2] += dp[i-1][j][1];
                if(j > 0) dp[i][j][2] += dp[i][j-1][1];
                if(i > 0 && j > 0) dp[i][j][2] += (MOD-dp[i-1][j-1][1]);
                dp[i][j][2] %= MOD;
            }
        }
    }
    
    cout << dp[N-1][M-1][2] << '\n';
    
    return 0;
}