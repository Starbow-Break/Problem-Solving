#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N;
int arr[100][100];
ll dp[100][100] = {0, };

void solve() {
    dp[0][0] = 1;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == N-1 && j == N-1) continue;
            
            if(i+arr[i][j] < N) dp[i+arr[i][j]][j] += dp[i][j];
            if(j+arr[i][j] < N) dp[i][j+arr[i][j]] += dp[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) { cin >> arr[i][j]; }
    }
    
    solve();
    
    cout << dp[N-1][N-1];

    return 0;
}