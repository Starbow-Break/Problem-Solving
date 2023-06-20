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

int dp[301][301] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    while(N--) {
        int x, y; cin >> x >> y;
        dp[x][y] = max(0, M-x-y);
    }
    
    for(int i = 0; i <= 300; i++) {
        for(int j = 0; j <= 300; j++) {
            int t = 0;
            if(i-1 >= 0) t = max(t, dp[i-1][j]);
            if(j-1 >= 0) t = max(t, dp[i][j-1]);
            dp[i][j] += t;
        }
    }
    
    cout << dp[300][300];
    
    return 0;
}