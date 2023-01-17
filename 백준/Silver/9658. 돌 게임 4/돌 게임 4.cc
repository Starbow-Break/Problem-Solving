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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    dp[1] = true; dp[2] = false; dp[3] = true; dp[4] = false;
    for(int i = 5; i <= N; i++) {
        dp[i] = (!dp[i-1] && !dp[i-3] && !dp[i-4]);
    }
    
    cout << (dp[N] ? "CY" : "SK");

    return 0;
}