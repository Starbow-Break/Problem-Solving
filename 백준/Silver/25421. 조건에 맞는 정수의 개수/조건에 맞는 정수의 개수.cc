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
#define MOD 987'654'321

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

int dp[100000][10] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for(int i = 1; i <= 9; i++) dp[0][i] = 1;
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= 9; j++) {
            for(int k = -2; k <= 2; k++) {
                if(1 <= j+k && j+k <= 9) {
                    dp[i][j+k] += dp[i-1][j];
                    dp[i][j+k] %= MOD;
                }
            }
        }
    }
    
    int ans = 0;
    for(int j = 1; j <= 9; j++) {
        ans += dp[n-1][j];
        ans %= MOD;
    }
    
    cout << ans;

    return 0;
}