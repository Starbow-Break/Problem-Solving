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

bool status[1 << 12][2] = {false, };
int dp[12][12];

void generateStatus(int step, int n, int idx) {
    for(int i = 0; i < n; i++) status[dp[step][i]][idx] = true;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) dp[step+1][j] = 0;
        for(int j = 0; j < i; j++) {
            dp[step+1][i-1-j] |= dp[step][j];
        }
        for(int j = i; j < n; j++) {
            dp[step+1][j-i] |= dp[step][j];
        }
        generateStatus(step+1, max(n-i, i), idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    int arr[12][12];
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            cin >> arr[r][c];
        }
    }
    
    for(int i = 0; i < N; i++) {
        dp[0][i] = 1<<i;
    }
    generateStatus(0, N, 0);
    for(int i = 0; i < M; i++) {
        dp[0][i] = 1<<i;
    }
    generateStatus(0, M, 1);
    
    int ans = arr[0][0];
    for(int r = 0; r < 1<<N; r++) {
        for(int c = 0; c < 1<<M; c++) {
            if(status[r][0] && status[c][1]) {
                int cur = 0;
                for(int row = 0; row < N; row++) {
                    for(int col = 0; col < M; col++) {
                        if((r & 1<<row) && (c & 1<<col)) {
                            cur += arr[row][col];
                        }
                    }
                }
                ans = max(ans, cur);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
