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

vector<int> pretty;
int dp[5001][900] = {0, };

void getPretty(int v) {
    for(int i = 1; i <= v; i++) {
        int s = 0;
        int A = i;
        while(A > 0) {
            s += A%10; A /= 10;
        }
        
        if(!(i%s)) { pretty.push_back(i); }
    }
}

void solve(int M, int K) {
    fill(dp[0], dp[0]+900, 1);
    getPretty(M);
    
    for(int i = 1; i <= M; i++) {
        for(int j = 0; j < pretty.size(); j++) {
            if(j > 0) {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= K;
            }
            
            if(pretty[j] <= i) {
                dp[i][j] += dp[i-pretty[j]][j];
                dp[i][j] %= K;
            }
        }
    }
    
    cout << dp[M][pretty.size()-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M, K; cin >> M >> K;
    solve(M, K);

    return 0;
}