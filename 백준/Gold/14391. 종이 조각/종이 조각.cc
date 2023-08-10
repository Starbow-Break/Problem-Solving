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

int dp[1 << 16] = {0, };
int arr[4][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int r = 0; r < N; r++) {
        int v; cin >> v;
        for(int c = M-1; c >= 0; c--) {
            arr[r][c] = v%10;
            v /= 10;
        }
    }
    
    for(int status = 0; status < 1<<(N*M); status++) {
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < M; c++) {
                int t = 0, s = 0;
                for(int rr = r; rr < N; rr++) {
                    if(status & 1<<(rr*M+c)) break;
                    t = t*10+arr[rr][c];
                    s |= 1<<(rr*M+c);
                    dp[status|s] = max(dp[status|s], dp[status]+t);
                }
                
                t = 0, s = 0;
                for(int cc = c; cc < M; cc++) {
                    if(status & 1<<(r*M+cc)) break;
                    t = t*10+arr[r][cc];
                    s |= 1<<(r*M+cc);
                    dp[status|s] = max(dp[status|s], dp[status]+t);
                }
            }
        }
    }
    
    cout << dp[(1<<(N*M))-1];
    
    return 0;
}