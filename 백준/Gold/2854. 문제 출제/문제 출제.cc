#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N;
ll dp[100001][3] = {0, };

int cnt[100001] = {0, };
int cnt2[100001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) { cin >> cnt[i]; }
    for(int i = 1; i < N; i++) { cin >> cnt2[i]; }
    
    dp[1][0] = cnt[1]; dp[1][2] = cnt2[1];
    for(int i = 2; i <= N; i++) {
        dp[i][0] += 1LL*dp[i-1][0]*cnt[i];
        dp[i][0] %= MOD;
        dp[i][0] += 1LL*dp[i-1][1]*cnt[i];
        dp[i][0] %= MOD;
        dp[i][0] += 1LL*dp[i-1][2]*cnt[i];
        dp[i][0] %= MOD;
        
        dp[i][1] += 1LL*dp[i-1][0]*cnt2[i-1];
        dp[i][1] %= MOD;
        dp[i][1] += 1LL*dp[i-1][1]*cnt2[i-1];
        dp[i][1] %= MOD;
        if(cnt2[i-1] > 0) dp[i][1] += 1LL*dp[i-1][2]*(cnt2[i-1]-1);
        dp[i][1] %= MOD;
        
        dp[i][2] += 1LL*dp[i-1][0]*cnt2[i];
        dp[i][2] %= MOD;
        dp[i][2] += 1LL*dp[i-1][1]*cnt2[i];
        dp[i][2] %= MOD;
        dp[i][2] += 1LL*dp[i-1][2]*cnt2[i];
        dp[i][2] %= MOD;
    }
    
    cout << (dp[N][0]+dp[N][1]+dp[N][2])%MOD;

    return 0;
}