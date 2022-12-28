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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N; 
ll dp[100001];
int arr[100001][2];

bool solve() {
    for(int i = 2; i <= N; i++) {
        if(dp[i-1] != -1 && dp[i-1] <= arr[i][0]) {
            if(dp[i] == -1) dp[i] = dp[i-1]+arr[i][1];
            else dp[i] = min(dp[i], dp[i-1]+arr[i][1]);
        }
        
        if(dp[i-2] != -1 && dp[i-2] <= arr[i][0]) {
            if(dp[i-1] == -1) dp[i-1] = dp[i-2]+arr[i][1];
            else dp[i-1] = min(dp[i-1], dp[i-2]+arr[i][1]);
        }
        
        if(dp[i-1] == -1 && dp[i-2] == -1) return false;
    }
    
    return (dp[N-1] != -1 || dp[N] != -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(dp+1, dp+100001, -1);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    
    dp[0] = 0; dp[1] = arr[1][1];
    
    cout << (solve() ? "Kkeo-eok" : "Zzz") << '\n';
    
    /*for(int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }*/

    return 0;
}