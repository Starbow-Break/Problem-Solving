#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N;
int dp[1<<10][10];
int W[10][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }
    
    for(int i = 0; i < (1<<N); i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
    }
    
    dp[1][0] = 0;
    
    for(int state = 3; state < (1<<N); state += 2) {
        for(int j = 1; j < N; j++) {
            if(state & (1<<j)) {
                for(int bef = 0; bef < N; bef++) {
                    if(W[bef][j] > 0 &&bef != j && state & (1<<bef)) {
                        dp[state][j] = min(dp[state][j], dp[state^(1<<j)][bef]+W[bef][j]);
                    }
                }
            }
        }
    }
    
    int ans = INF; 
    for(int i = 1; i < N; i++) {
        if(W[i][0] > 0)
            ans = min(ans, dp[(1<<N)-1][i]+W[i][0]);
    }
    
    cout << ans;

    return 0;
}
