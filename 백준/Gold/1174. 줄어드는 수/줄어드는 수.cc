#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int dp[11][10] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i < 10; i++) { dp[1][i] = 1; }
    
    for(int i = 2; i <= 10; i++) {
        for(int j = i-1; j < 10; j++) {
            for(int k = 0; k < j; k++) {
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    
    int N; cin >> N;
    
    int l;
    for(l = 1; l <= 10; l++) {
        int s = 0;
        for(int j = 0; j < 10; j++) {
            s += dp[l][j];
        }
        
        if(s >= N) break;
        
        N -= s;
    }
    
    if(l > 10) cout << -1;
    else {
        while(l > 0) {
            int s = 0; int j;
            for(j = 0; j < 10; j++) {
                s += dp[l][j];
                if(s >= N) break;
            }
            
            cout << j;
            N -= (s-dp[l][j]);
            
            l--;
        }
    }

    return 0;
}