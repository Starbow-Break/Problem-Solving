#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    ll ans = 0; ll w = 1;
    for(int i = N; i >= 0; i--) {
        if(i%2) {
            ans += (MOD-w);
            ans %= MOD;
        }
        else {
            ans += w;
            ans %= MOD;
        }
        
        w *= i; w %= MOD;
    }
    
    cout << ans;

    return 0;
}