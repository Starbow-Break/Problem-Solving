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

int dp[1000][1000] = {0, };
int N;
vector<int> score;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        int s; cin >> s;
        score.push_back(s);
    }
    
    for(int l = 1; l <= N; l++) {
        for(int s = 0; s <= N-l; s++) {
            int f = s+l-1;
            
            int m = 10000; int M = 0;
            for(int i = s; i <= f; i++) {
                m = min(m, score[i]);
                M = max(M, score[i]);
            }
            
            dp[s][f] = M-m;
            for(int t = s; t < f; t++) {
                dp[s][f] = max(dp[s][f], dp[s][t]+dp[t+1][f]);
            }
        }
    }
    
    cout << dp[0][N-1];

    return 0;
}