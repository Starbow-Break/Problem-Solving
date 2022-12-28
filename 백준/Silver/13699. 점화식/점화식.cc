#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll dp[35] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    dp[0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j]*dp[(i-1)-j];
        }
    }
    
    cout << dp[N]; 

    return 0;
}