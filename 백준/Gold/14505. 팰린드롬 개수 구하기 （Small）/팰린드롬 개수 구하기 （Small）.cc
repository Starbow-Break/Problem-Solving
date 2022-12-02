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

int dp[30][30] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    for(int len = 1; len <= s.length(); len++) {
        for(int i = 0; i <= s.length()-len; i++) {
            if(len == 1) {dp[i][i] = 1;}
            else {
                int j = i+len-1;
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j]+dp[i][j-1]+1;
                }
                else {
                    dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                }
            }
        }
    }
    
    cout << dp[0][s.length()-1];

    return 0;
}