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

int dp[31];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    dp[0] = 1; dp[1] = 1; dp[2] = 3;
    for(int i = 3; i <= N; i++) {
        dp[i] = dp[i-1]+2*dp[i-2];
    }
    
    cout << ((N%2) ? (0LL+dp[N]+dp[N/2])/2 : (0LL+dp[N]+dp[N/2]+2*dp[N/2-1])/2);

    return 0;
}