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
#define MOD 1'000'000'009

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

int dp[100'001][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[1][0] = 0; dp[1][1] = 1;
    dp[2][0] = 1; dp[2][1] = 1;
    dp[3][0] = 2; dp[3][1] = 2;
    
    for(int i = 4; i <= 100'000; i++) {
        dp[i][0] = ((dp[i-1][1]+dp[i-2][1])%MOD+dp[i-3][1])%MOD;
        dp[i][1] = ((dp[i-1][0]+dp[i-2][0])%MOD+dp[i-3][0])%MOD;
    }
    
    int T; cin >> T;
    while(T--) {
        int v; cin >> v;
        cout << dp[v][1] << ' ' << dp[v][0] << '\n';
    }

    return 0;
}