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

int dp[1001][1001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, t; cin >> s >> t;
    
    for(int i = 0; i <= s.length(); i++) {
        for(int j = 0; j <= t.length(); j++) {
            if(i == 0 || j == 0) dp[i][j] = max(i, j);
            
            else {
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                    dp[i][j]++;
                }
            }
        }
    }
    
    cout << dp[s.length()][t.length()];

    return 0;
}