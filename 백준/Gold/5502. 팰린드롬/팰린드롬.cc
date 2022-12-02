#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MAX 100000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int dp[5000][5000] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; string s;
    cin >> N >> s;
    for(int len = 1; len <= N; len++) {
        for(int i = 0; i <= N-len; i++) {
            int j = i+len-1;
            if(len == 1) { dp[i][j] = 0; }
            else {
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1;
                }
            }
        }
    }
    
    cout << dp[0][N-1];

    return 0;
}
