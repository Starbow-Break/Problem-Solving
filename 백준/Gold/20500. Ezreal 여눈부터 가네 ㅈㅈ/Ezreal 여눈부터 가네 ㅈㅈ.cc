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

int dp[1516][15] = {0, }; //dp[i][j] = i자리 자연수 중에서 mod 15가 j인 수의 갯수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    dp[1][1] = 1; dp[1][5] = 1;
    for(int i = 2; i <= N; i++) {
        for(int j = 0;j < 15; j++) {
            dp[i][(10*j+1)%15] += dp[i-1][j]; dp[i][(10*j+1)%15] %= MOD;
            dp[i][(10*j+5)%15] += dp[i-1][j]; dp[i][(10*j+5)%15] %= MOD;
        }
    }
    
    cout << dp[N][0];

    return 0;
}