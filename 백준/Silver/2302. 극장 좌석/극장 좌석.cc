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

int N, M;
int dp[41] = {0, };
bool vip[41] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0] = 1;
    cin >> N >> M;
    while(M--) {
        int v; cin >> v;
        vip[v] = true;
    }
    
    for(int i = 1; i <= N; i++) {
        dp[i] += dp[i-1];
        if(i >= 2 && !vip[i] && !vip[i-1]) {
            dp[i] += dp[i-2];
        }
    }
    
    cout << dp[N];

    return 0;
}