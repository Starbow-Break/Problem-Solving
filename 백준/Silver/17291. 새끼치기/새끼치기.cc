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

int dp[21][2] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[1][0] = 1; dp[1][1] = 1;
    
    int N; cin >> N;
    for(int i = 2; i <= N; i++) {
        dp[i][0] += 2*dp[i-1][0];
        dp[i][1] += dp[i-1][0];
        
        if(i%2 == 0 && i >= 4) {
            dp[i][0] -= dp[i-3][1];
            dp[i][0] -= dp[i-4][1];
        }
    }
    
    cout << dp[N][0];

    return 0;
}