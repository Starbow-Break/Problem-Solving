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
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N;
int dp[50001][4] = {0, };
int S[50001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N; S[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> S[i];
        S[i] += S[i-1];
    }
    
    int l; cin >> l;
    for(int i = 1; i <= N; i++) {
        if(i <= l) {
            dp[i][1] = dp[i][2] = dp[i][3] = S[i];
        }
        else if(i <= l*2) {
            dp[i][2] = dp[i][3] = S[i];
            dp[i][1] = max(dp[i][1], S[i]-S[i-l]);
        }
        else if(i <= l*3) {
            dp[i][3] = S[i];
            dp[i][2] = max(dp[i-1][2], dp[i-l][1]+S[i]-S[i-l]);
            dp[i][1] = max(dp[i-1][1], S[i]-S[i-l]);
        }
        else {
            dp[i][3] = max(dp[i-1][3], dp[i-l][2]+S[i]-S[i-l]);
            dp[i][2] = max(dp[i-1][2], dp[i-l][1]+S[i]-S[i-l]);
            dp[i][1] = max(dp[i-1][1], S[i]-S[i-l]);
        }
    }
    
    cout << dp[N][3];

    return 0;
}