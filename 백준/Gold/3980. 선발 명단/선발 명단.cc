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

int ability[11][11];
int sz[11];
vector<pii> vec[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        for(int r = 0; r < 11; r++) {
            sz[r] = 0; vec[r].clear();
            for(int c = 0; c < 11; c++) cin >> ability[r][c];
        }
        
        for(int r = 0; r < 10; r++) {
            for(int c = 0; c < 11; c++) {
                if(ability[r][c]) {
                    vec[r].pb({c, ability[r][c]});
                    sz[r]++;
                }
            }
        }
        
        int total = 1;
        for(int i = 0; i < 10; i++) total *= sz[i];
        
        int ans = 0;
        for(int s = 0; s < total; s++) {
            bool visited[11] = {false, };
            int cur = 0, status = s;
            for(int i = 0; i < 10; i++) {
                if(visited[vec[i][status%sz[i]].fi]) {
                    cur = 0;
                    break;
                }
                
                cur += vec[i][status%sz[i]].se;
                visited[vec[i][status%sz[i]].fi] = true;
                status /= sz[i];
            }
            
            if(cur != 0) {
                int idx = 0;
                for(int i = 0; i < 11; i++) {
                    if(!visited[i]) {
                        idx = i; break;
                    }
                }
                
                if(ability[10][idx]) cur += ability[10][idx];
                else cur = 0;
            }
            
            ans = max(ans, cur);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}