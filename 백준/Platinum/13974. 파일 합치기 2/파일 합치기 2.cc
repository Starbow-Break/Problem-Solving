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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

ll dp[5001][5001] = {0, };
int opt[5001][5001] = {0, };
ll sum[5001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        sum[0] = 0;
        
        int N; cin >> N;
        for(int i = 1; i <= N; i++) {
            cin >> sum[i]; sum[i] += sum[i-1]; opt[i][i] = i;
        }
        
        for(int d = 1; d < N; d++) {
            for(int r = 1; r+d <= N; r++) {
                int a = opt[r][r+d-1], b = opt[r+1][r+d];
                opt[r][r+d] = a; dp[r][r+d] = dp[r][a]+dp[a+1][r+d]+(sum[r+d]-sum[r-1]);
                for(int k = a; k <= b; k++) {
                    if(dp[r][r+d] > dp[r][k]+dp[k+1][r+d]+(sum[r+d]-sum[r-1])) {
                        opt[r][r+d] = k;
                        dp[r][r+d] = dp[r][k]+dp[k+1][r+d]+(sum[r+d]-sum[r-1]);
                    }
                }
            }
        }
        
        cout << dp[1][N] << '\n';
        
        for(int r = 1; r <= N; r++) fill(dp[r], dp[r]+N+1, 0);
    }

    return 0;
}