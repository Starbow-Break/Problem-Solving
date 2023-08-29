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
        int cnt[2][5] = {0, };
        int N; cin >> N;
        while(N--) {
            int v; cin >> v;
            cnt[0][v]++;
        }
        cin >> N;
        while(N--) {
            int v; cin >> v;
            cnt[1][v]++;
        }
        
        char ans = 'D';
        for(int i = 4; i >= 1; i--) {
            if(cnt[0][i] > cnt[1][i]) {
                ans = 'A';
                break;
            }
            if(cnt[0][i] < cnt[1][i]) {
                ans = 'B';
                break;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
