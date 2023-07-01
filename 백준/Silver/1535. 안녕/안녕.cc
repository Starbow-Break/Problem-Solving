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

int L[20], J[20];

int dp[101][21];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    for(int i = 0; i <= 100; i++) fill(dp[i], dp[i]+21, -1);
    for(int i = 0; i < N; i++) cin >> L[i];
    for(int i = 0; i < N; i++) cin >> J[i];
    
    dp[100][0] = 0;
    for(int j = 1; j <= N; j++) {
        for(int i = 0; i <= 100; i++) {
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
            if(i >= L[j-1] && dp[i][j-1] >= 0) {
                dp[i-L[j-1]][j] = max(dp[i-L[j-1]][j], dp[i][j-1]+J[j-1]);
            }
        }
    }
    
    int ans = 0;
    for(int j = 1; j <= 100; j++) ans = max(ans, dp[j][N]);
    cout << ans;

    return 0;
}