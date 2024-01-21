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

int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int check[19][19]; int offset = 9;
        for(int i = -9; i <= 9; i++) {
            for(int j = -9; j <= 9; j++) {
                check[i+offset][j+offset] = -1;
            }
        }
        
        int K, M; cin >> K >> M;
        
        vector<pii> delta; int cycle_start;
        int cur = 1, d = 0;
        while(true) {
            if(check[offset+nx[d]*cur][offset+ny[d]*cur] != -1) {
                cycle_start = check[offset+nx[d]*cur][offset+ny[d]*cur];
                break;
            }
            
            check[offset+nx[d]*cur][offset+ny[d]*cur] = delta.size();
            delta.pb({nx[d]*cur, ny[d]*cur});
            cur = cur*M%9; cur = (cur ? cur : 9);
            d = (d+1)%4;
        }
        
        ll X = 0, Y = 0;
        int idx = 0;
        while(idx != cycle_start && K > 0) {
            K--;
            X += delta[idx].fi; Y += delta[idx].se;
            idx++;
        }
        
        if(K == 0) {
            cout << X << ' ' << Y << '\n';
            continue;
        }
        
        ll cX = 0, cY = 0;
        for(int i = cycle_start; i < delta.size(); i++) {
            cX += delta[i].fi; cY += delta[i].se;
        }
        
        int cycle_size = delta.size()-cycle_start;
        X += 1LL*cX*(K/cycle_size); Y += 1LL*cY*(K/cycle_size);
        K %= cycle_size;
        
        while(K--) {
            X += delta[idx].fi; Y += delta[idx].se;
            idx++;
        }
        
        cout << X << ' ' << Y << '\n';
    }
    
    return 0;
}