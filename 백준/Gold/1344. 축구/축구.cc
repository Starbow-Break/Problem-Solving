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

bool isPrime[19] = {false, };
double dp[19][19][19] = {0, }; //dp[i][j][k] == 5*k분에 i:j일 확률

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    isPrime[2] = isPrime[3] = isPrime[5] = isPrime[7] = true;
    isPrime[11] = isPrime[13] = isPrime[17] = true;
    
    int pA, pB; cin >> pA >> pB;
    dp[0][0][0] = 1;
    
    for(int k = 1; k <= 18; k++) {
        for(int a = 0; a <= k; a++) {
            for(int b = 0; b <= k; b++) {
                dp[a][b][k] += dp[a][b][k-1]*(100-pA)*(100-pB)/10000;
                if(a > 0) dp[a][b][k] += dp[a-1][b][k-1]*(pA)*(100-pB)/10000;
                if(b > 0)dp[a][b][k] += dp[a][b-1][k-1]*(100-pA)*pB/10000;
                if(a*b > 0)dp[a][b][k] += dp[a-1][b-1][k-1]*pA*pB/10000;
            }
        }
    }
    
    double ans = 0;
    
    for(int a = 0; a <= 18; a++) {
        for(int b = 0; b <= 18; b++) {
            if(isPrime[a] || isPrime[b]) {
                ans += dp[a][b][18];
            }
        }
    }
    
    cout << fixed; cout.precision(15);
    cout << ans;

    return 0;
}