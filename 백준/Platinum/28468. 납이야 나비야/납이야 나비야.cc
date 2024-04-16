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

bool conn[501][501] = {false, };
int order[501] = {0, };

vector<int> edges[501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        conn[a][b] = true; conn[b][a] = true;
        edges[a].pb(b); edges[b].pb(a);
    }
    
    ll ans = 0; 
    for(int i = 1; i <= N; i++) {
        int ord = edges[i].size();
        if(ord >= 6) {
            int cnt[501] = {0, };
            int total = 0;
            for(int a = 0; a < ord; a++) {
                for(int b = a+1; b < ord; b++) {
                    if(conn[edges[i][a]][edges[i][b]]) {
                        cnt[a]++; cnt[b]++; total++;
                    }
                }
            }
            
            if(total >= 2) {
                ll x = 1LL*total*(total-1)/2, y = 1LL*(ord-4)*(ord-5)/2;
                for(int i = 0; i < ord; i++) {
                    if(cnt[i] >= 2) {
                        x -= 1LL*cnt[i]*(cnt[i]-1)/2;
                    }
                }
                
                if(total >= 2) {
                    ans += x*y;
                }
            }
        }
    }
    
    cout << ans;
    
    return 0;
}