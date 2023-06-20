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

int dp[1'000'001] = {0, };
int A[100'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    for(int i = 1; i <= N; i++) {
        dp[A[i]] = max(dp[A[i]], dp[A[i]-1]+1);
    }
    
    int ans = 0;
    for(int i = 1; i <= 1'000'000; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    
    return 0;
}