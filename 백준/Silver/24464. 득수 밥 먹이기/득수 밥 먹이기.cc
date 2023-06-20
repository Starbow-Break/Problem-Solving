#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>
#define MOD 1'000'000'007

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

ll dp[200'001][5] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i <= 4; i++) dp[1][i] = 1;
    
    for(int i = 2; i <= N; i++) {
        dp[i][1] += dp[i-1][0];
        dp[i][2] += dp[i-1][0];
        dp[i][3] += dp[i-1][0];
        dp[i][4] += dp[i-1][0];
        dp[i][0] += dp[i-1][1];
        dp[i][3] += dp[i-1][1];
        dp[i][4] += dp[i-1][1];
        dp[i][0] += dp[i-1][2];
        dp[i][4] += dp[i-1][2];
        dp[i][0] += dp[i-1][3];
        dp[i][1] += dp[i-1][3];
        dp[i][0] += dp[i-1][4];
        dp[i][1] += dp[i-1][4];
        dp[i][2] += dp[i-1][4];
        
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i][2] %= MOD;
        dp[i][3] %= MOD;
        dp[i][4] %= MOD;
    }
    
    cout << ((((dp[N][0]+dp[N][1])%MOD+dp[N][2])%MOD+dp[N][3])%MOD+dp[N][4])%MOD;
    
    return 0;
}