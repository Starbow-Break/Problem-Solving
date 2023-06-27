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

int dp[100'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    dp[1] = 1; dp[2] = 1; dp[3] = 2; dp[4] = 2; dp[5] = 1; 
    dp[6] = 2; dp[7] = 1;
    for(int i = 8; i <= N; i++) {
        dp[i] = min({dp[i-1]+1, dp[i-2]+1, dp[i-5]+1, dp[i-7]+1});
    }
    
    cout << dp[N];

    return 0;
}