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

int N;
int arr[1000][1000];
int dp[1000][1000][4][2] = {0, };

int dr[4] = {1, 0, 1, 1};
int dc[4] = {0, 1, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) cin >> arr[r][c];
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(!arr[r][c]) continue;
            for(int k = 0; k < 4; k++) {
                int row = r, col = c, change = (arr[r][c] == 2), cnt = 1;
                while(1) {
                    if(dp[row][col][k][change]) break;
                    
                    dp[row][col][k][change] = cnt;
                    row += dr[k], col += dc[k]; cnt++;
                    if(row < 0 || row >= N || col < 0 || col >= N) break;
                    if(arr[row][col] == 0) break;
                    
                    if(arr[row][col] == 2) change++;
                    if(change >= 2) break;
                }
            }
        }
    }
    
    int ans = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            for(int k = 0; k < 4; k++) {
                ans = max({ans, dp[r][c][k][0], dp[r][c][k][1]});
            }
        }
    }
    
    cout << ans;
    
    return 0;
}