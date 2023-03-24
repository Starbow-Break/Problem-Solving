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

int dp[500'001][51];
int h[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i <= 500'000; i++) fill(dp[i], dp[i]+51, -1);
    dp[0][0] = 0;
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> h[i];
        
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= 500'000; j++) {
            if(dp[j][i-1] >= 0) {
                int a = dp[j][i-1]-j; int b = dp[j][i-1];
                
                if(a+h[i] > b) {
                    dp[a+h[i]-b][i] = max(dp[a+h[i]-b][i], a+h[i]);
                }
                else {
                    dp[b-(a+h[i])][i] = max(dp[b-(a+h[i])][i], b);
                }
                
                dp[b+h[i]-a][i] = max(dp[b+h[i]-a][i], b+h[i]);
            
                dp[j][i] = max(dp[j][i], dp[j][i-1]);
            }
        }
    }
    
    cout << (dp[0][N] ? dp[0][N] : -1);

    return 0;
}