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
#define MOD 998'244'353

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    int A[N], dp[N] = {0, };
    for(int i = 0; i < N; i++) cin >> A[i];
    
    dp[0] = 1;
    for(int i = 1; i < N; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(A[j] < A[i]) {
                dp[i] += dp[j]; dp[i] %= MOD;
            }
        }
    }
    
    for(int i = 0; i < N; i++) cout << dp[i] << ' ';

    return 0;
}