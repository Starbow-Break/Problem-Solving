#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define MOD 987654321

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

ll dp[10001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0] = 1; dp[2] = 1; dp[4] = 2;
    int N; cin >> N;
    
    for(int i = 6; i <= N; i += 2) {
        for(int j = 0; j <= i-2; j += 2) {
            dp[i] += dp[j]*dp[i-2-j];
            dp[i] %= MOD;
        }
    }
    
    cout << dp[N];
    
    return 0;
}
