#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int dp[44] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 43; i++) {
        dp[i] = dp[i-1]+dp[i-2]+1;
    }
    
    int T; cin >> T;
    while(T--) {
        int V; cin >> V;
        for(int h = 1; h <= 43; h++) {
            if(V < dp[h]) {
                cout << h-1 << '\n';
                break;
            }
        }
    }
    
    return 0;
}
