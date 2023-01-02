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

const int w = 16000;

int n, k, x;
int arr[81];
bool dp[81][81][32001] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i <= 80; i++) dp[i][0][w] = true;
    
    cin >> n >> k >> x;
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        arr[i] = a-b;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            for(int k = -16000; k <= 16000; k++) {
                if(dp[i-1][j][k+w]
                    || (-16000 <= k-arr[i] && k-arr[i] <= 16000 && dp[i-1][j-1][k-arr[i]+w]))
                    dp[i][j][k+w] = true;
            }
        }
    }
    
    int t;
    for(t = 0; t <= 16000; t++) {
        if(dp[n][k][w+t] || dp[n][k][w-t]) break;
    }
    cout << (x*k*x*k-t*t)/4;

    return 0;
}