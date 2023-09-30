#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int dp[1'000'000][4] = {0, };
int A[1'000'001], N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    
    dp[0][0] = -A[0];
    dp[1][1] = A[1]-A[0];
    dp[2][2] = -A[2]+A[1]-A[0];
    dp[3][3] = A[3]-A[2]+A[1]-A[0];
    
    for(int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i-1][0], -A[i]);
    }
    for(int i = 2; i < N; i++) {
        dp[i][1] = max(dp[i-1][1], A[i]+dp[i-1][0]);
    }
    for(int i = 3; i < N; i++) {
        dp[i][2] = max(dp[i-1][2], -A[i]+dp[i-1][1]);
    }
    for(int i = 4; i < N; i++) {
        dp[i][3] = max(dp[i-1][3], A[i]+dp[i-1][2]);
    }
    
    cout << dp[N-1][3];
    
    return 0;
}