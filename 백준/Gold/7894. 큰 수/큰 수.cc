#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MAX 100000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

double dp[10000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0] = 0;
    for(int i = 2; i <= 10000000; i++) {
        dp[i] = dp[i-1]+log10(1LL*i);
    }
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        if(N == 1) cout << 1 << '\n';
        else {
            int ans = ceil(dp[N]);
            cout << ans << '\n';
        }
    }

    return 0;
}
