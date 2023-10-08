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

const int OFFSET_X = 7;
const int OFFSET_Y = 14;
int dp[15][15][29] = {0, };

int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {1, -1, 2, -2, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0][OFFSET_X][OFFSET_Y] = 1;
    for(int i = 0; i < 14; i++) {
        for(int x = -7; x <= 7; x++) {
            for(int y = -14; y <= 14; y++) {
                for(int k = 0; k < 6; k++) {
                    if(-7 <= x+dx[k] && x+dx[k] <= 7 && -14 <= y+dy[k] && y+dy[k] <= 14) {
                        dp[i+1][OFFSET_X+x+dx[k]][OFFSET_Y+y+dy[k]]
                        += dp[i][OFFSET_X+x][OFFSET_Y+y];
                    }
                }
            }
        }
    }
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        cout << dp[N][OFFSET_X][OFFSET_Y] << '\n';
    }
    
    return 0;
}