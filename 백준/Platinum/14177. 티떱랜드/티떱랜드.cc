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

const int INF = 2e9;

int u[4001][4001];
int sum[4001][4001] = {0, };
int dp[4001][801] = {0, };

void dnc(int step, int left, int right, int p, int q) {
    if(left > right) return;
    
    int mid = (left+right) >> 1;
    int k = 0;
    
    dp[mid][step] = INF;
    for(int i = p; i <= q & i <= mid; i++) {
        if(dp[mid][step] > dp[i-1][step-1]+sum[i][mid]) {
            k = i;
            dp[mid][step] = dp[i-1][step-1]+sum[i][mid];
        }
    }
    
    dnc(step, left, mid-1, p, k);
    dnc(step, mid+1, right, k, q);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cin >> u[i][j];
    }
    
    for(int l = 1; l < N; l++) {
        for(int i = 1; i <= N-l; i++) {
            sum[i][i+l] = sum[i][i+l-1]+sum[i+1][i+l]-sum[i+1][i+l-1]+u[i][i+l];
        }
    }
    
    for(int k = 1; k <= K; k++) {
        if(k == 1) {
            for(int n = 1; n <= N; n++) {
                dp[n][k] = sum[1][n];
            }
        }
        else {
            dnc(k, k, N, k, N);
        }
    }
    
    // for(int k = 1; k <= K; k++) {
    //     for(int n = 1; n <= N; n++) {
    //         cout << dp[n][k] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    cout << dp[N][K];
    
    return 0;
}
