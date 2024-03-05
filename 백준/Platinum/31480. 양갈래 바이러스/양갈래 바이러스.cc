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

int dp[1 << 18][35] = {0, };
int virus[1 << 18][35] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, Q; cin >> N >> Q;
    while(Q--) {
        int v, p, d; cin >> v >> p >> d;
        virus[v][d] += p;
        for(int i = d; i >= 0 && v; i--) {
            dp[v][i] += p;
            v >>= 1;
        }
    }
    
    int ans[1 << 18] = {0, };
    
    for(int i = 1; i <= N; i++) {
        int cur = i, bef = i;
        int d = 0;
        while(cur) {
            if(cur == bef) {
                for(int j = 0; j < 35; j++) {
                    ans[i] += dp[i][j];
                }
            }
            else {
                int other = (cur*2 == bef ? cur*2+1 : cur*2);
                for(int j = d; j < 35; j++) {
                    ans[i] += virus[cur][j];
                    if(j > d) ans[i] += dp[other][j];
                }
            }
            
            bef = cur;
            cur = bef >> 1;
            d++;
        }
    }
    
    for(int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}
