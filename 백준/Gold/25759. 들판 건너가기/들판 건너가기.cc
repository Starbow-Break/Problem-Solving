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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int dp[100001][101];
int A[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i <= 100000; i++) fill(dp[i], dp[i]+101, -1);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) { cin >> A[i]; }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= 100; j++) {
            if(A[i] == j) dp[i][j] = 0;
            
            if(dp[i-1][j] != -1) dp[i][j] = dp[i-1][j];
        }
        
        for(int j = 1; j <= 100; j++) {
            if(dp[i-1][j] != -1)
                dp[i][A[i]] = max(dp[i][A[i]], dp[i-1][j]+(A[i]-j)*(A[i]-j));
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= 100; i++) {
        ans = max(ans, dp[N][i]);
    }
    
    cout << ans;

    return 0;
}