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
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int dp[101][20000][2];

void init() {
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j < 20000; j++) {
            dp[i][j][0] = -1; dp[i][j][1] = -1;
        }
    }
}

void solve(int N) {
    init();
    if(N == 1) { cout << 1; return; }
    
    dp[1][1][1] = 0;
    for(int n = 2; n <= 100; n++) {
        for(int j = 0; j < N; j++) {
            if(dp[n-1][j][0] != -1 || dp[n-1][j][1] != -1) {
                dp[n][(j*10)%N][0] = j;
                dp[n][(j*10+1)%N][1] = j;
            }
        }
    }
    
    int idx;
    for(idx = 1; idx <= 100; idx++) {
        if(dp[idx][0][0] != -1 || dp[idx][0][1] != -1) break;
    }
    
    if(idx > 100) { cout << "BRAK"; return; }
    
    vector<int> ans; int cur = 0;
    while(idx > 0) {
        if(dp[idx][cur][0] != -1) {ans.push_back(0); cur = dp[idx][cur][0];}
        else {ans.push_back(1); cur = dp[idx][cur][1];}
        
        idx--;
    }
    
    for(int i = ans.size()-1; i >= 0; i--) cout << ans[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        solve(N); cout << '\n';
    }

    return 0;
}