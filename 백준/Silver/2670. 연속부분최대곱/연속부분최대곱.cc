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

double dp[10000];
double A[10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) { cin >> A[i]; }
    
    dp[0] = A[0];
    for(int i = 1; i < N; i++) {
        dp[i] = max(A[i], A[i]*dp[i-1]);
    }
    
    double ans = dp[0];
    for(int i = 1; i < N; i++) {
        ans = max(ans, dp[i]);
    }
    
    cout << fixed; cout.precision(3);
    cout << ans;

    return 0;
}