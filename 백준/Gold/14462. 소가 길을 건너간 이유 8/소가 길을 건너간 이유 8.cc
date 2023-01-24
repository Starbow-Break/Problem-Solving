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
#define MAX 1000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int L[MAX+1], R[MAX+1];
int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) { cin >> L[i]; }
    for(int i = 1; i <= N; i++) { cin >> R[i]; }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(abs(L[i]-R[j]) <= 4) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    
    cout << dp[N][N];

    return 0;
}