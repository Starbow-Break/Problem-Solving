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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int color[1001][1001];
        bitset<1001> red[1001];
        bitset<1001> blue[1001];
        
        int N; cin >> N;
        for(int i = 1; i <= N; i++) {
            for(int j = i+1; j <= N; j++) {
                cin >> color[i][j];
                if(color[i][j] == 1) {
                    red[i][j] = 1;
                    red[j][i] = 1;
                }
                else {
                    blue[i][j] = 1;
                    blue[j][i] = 1;
                }
            }
        }
        
        ll ans = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = i+1; j <= N; j++) {
                if(color[i][j] == 1) {
                    bitset<1001> bs = red[i] & red[j];
                    ans += bs.count();
                }
                else {
                    bitset<1001> bs = blue[i] & blue[j];
                    ans += bs.count();
                }
            }
        }
        
        ans /= 3;
        cout << ans << '\n';
    }
    
    return 0;
}