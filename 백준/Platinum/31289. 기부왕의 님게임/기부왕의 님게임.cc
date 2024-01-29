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

int dp[201][201][201];

int mindpx[201][201][201], _mindpx[201][201][201];
int mindpy[201][201][201], _mindpy[201][201][201];
int mindpz[201][201][201], _mindpz[201][201][201];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0][0][0] = 0;
    mindpx[0][0][0] = mindpy[0][0][0] = mindpz[0][0][0] = 0;
    _mindpx[0][0][0] = _mindpy[0][0][0] = _mindpz[0][0][0] = 0;
                    
    for(int x = 0; x <= 200; x++) {
        for(int y = 0; y <= 200; y++) {
            for(int z = 0; z <= 200; z++) {
                if(!x && !y && !z) continue;
                
                dp[x][y][z] = 0;
                
                if(x) {
                    if(x^y^z) dp[x][y][z] = max(dp[x][y][z], 10000*(x+y+z)-_mindpx[x-1][y][z]);
                    else dp[x][y][z] = max(dp[x][y][z], 10000*(x+y+z)-mindpx[x-1][y][z]);
                }
                if(y) {
                    if(x^y^z) dp[x][y][z] = max(dp[x][y][z], 10000*(x+y+z)-_mindpy[x][y-1][z]);
                    else dp[x][y][z] = max(dp[x][y][z], 10000*(x+y+z)-mindpy[x][y-1][z]);
                }
                if(z) {
                    if(x^y^z) dp[x][y][z] = max(dp[x][y][z], 10000*(x+y+z)-_mindpz[x][y][z-1]);
                    else dp[x][y][z] = max(dp[x][y][z], 10000*(x+y+z)-mindpz[x][y][z-1]);
                }
                
                if(x) mindpx[x][y][z] = min(mindpx[x-1][y][z], dp[x][y][z]);
                else mindpx[x][y][z] = dp[x][y][z];
                
                if(y) mindpy[x][y][z] = min(mindpy[x][y-1][z], dp[x][y][z]);
                else mindpy[x][y][z] = dp[x][y][z];
                
                if(z) mindpz[x][y][z] = min(mindpz[x][y][z-1], dp[x][y][z]);
                else mindpz[x][y][z] = dp[x][y][z];
                
                if((x^y^z) == 0) {
                    if(x) _mindpx[x][y][z] = min(_mindpx[x-1][y][z], dp[x][y][z]);
                    else _mindpx[x][y][z] = dp[x][y][z];
                    
                    if(y) _mindpy[x][y][z] = min(_mindpy[x][y-1][z], dp[x][y][z]);
                    else _mindpy[x][y][z] = dp[x][y][z];
                    
                    if(z) _mindpz[x][y][z] = min(_mindpz[x][y][z-1], dp[x][y][z]);
                    else _mindpz[x][y][z] = dp[x][y][z];
                }
                else {
                    if(x) _mindpx[x][y][z] = _mindpx[x-1][y][z];
                    else _mindpx[x][y][z] = 1e9;
                    
                    if(y) _mindpy[x][y][z] = _mindpy[x][y-1][z];
                    else _mindpy[x][y][z] = 1e9;
                    
                    if(z) _mindpz[x][y][z] = _mindpz[x][y][z-1];
                    else _mindpz[x][y][z] = 1e9;
                }
            }
        }
    }
    
    
    int T; cin >> T;
    while(T--) {
        int x, y, z; cin >> x >> y >> z;
        cout << dp[x][y][z] << ' ' << 10000*(x+y+z)-dp[x][y][z] << '\n';
    }
    
    return 0;
}
