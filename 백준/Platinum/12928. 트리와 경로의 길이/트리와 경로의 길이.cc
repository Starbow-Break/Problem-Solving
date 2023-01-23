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
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

bool dp[51][1001][50] = {false, };

bool solve(int N, int S) {
    if(N <= 2) return (S == 0);
    
    dp[1][0][0] = true; dp[2][0][1] = true;
    for(int n = 2; n < N; n++) {
        for(int s = 0; s <= 1000; s++) {
            for(int ord = 0; ord < n; ord++) {
                if(dp[n][s][ord] && s+ord <= 1000) {
                    dp[n+1][s+ord][1] = true;
                    dp[n+1][s+ord][ord+1] = true;
                }
            }
        }
    }
    
    return dp[N][S][1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, S; cin >> N >> S;
    cout << solve(N, S);

    return 0;
}