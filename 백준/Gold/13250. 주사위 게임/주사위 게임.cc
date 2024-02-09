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

double dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[1] = 1;
    int N; cin >> N;
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i-j <= 0) {
                dp[i] += (double)1/6;
            }
            else {
                dp[i] += (double)1/6*(dp[i-j]+1);
            }
        }
    }
    
    cout << fixed << setprecision(12) << dp[N];
    
    return 0;
}