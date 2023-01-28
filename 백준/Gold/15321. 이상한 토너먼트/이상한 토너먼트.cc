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
typedef pair<int, int> pii;
typedef pair<double, double> dd;

const int INF = 100000000;

pii dp[501][501];
int arr[501];

void init() {
    for(int i = 1; i <= 500; i++) {
        for(int j = 1; j <= 500; j++) {
            dp[i][j] = {INF, 0};
        }
    }
}

pii solve(int i, int j) {
    if(dp[i][j].first != INF) return dp[i][j];
    
    bool isAsc = true, isDesc = true; int winner = 0;
    for(int k = i; k <= j; k++) {
        winner = max(winner, arr[k]);
        
        if(k > i) {
            if(arr[k]-arr[k-1] < 0) isAsc = false;
            if(arr[k]-arr[k-1] > 0) isDesc = false;
        }
    }
    
    dp[i][j].second = winner;
    
    if(isAsc || isDesc) {
        dp[i][j].first = abs(arr[i]-arr[j]);
        return dp[i][j];
    }
    
    for(int k = i; k < j; k++) {
        pii left = solve(i, k); pii right = solve(k+1, j);
        dp[i][j].first = min(dp[i][j].first,
                left.first+right.first+abs(left.second-right.second));
    }
    
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    init();
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) { cin >> arr[i]; }
    
    cout << solve(1, N).first;

    return 0;
}