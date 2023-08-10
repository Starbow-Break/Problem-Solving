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
    
    int ans = 0;
    int N, K; cin >> N >> K;
    vector<int> vec(N);
    FOR(i, 0, N) {
        cin >> vec[i];
    }
    
    FOR(s, 0, 1<<N) {
        int cur = 0;
        int eat = 0;
        FOR(i, 0, N) {
            if(s & 1<<i) {
                eat += vec[i];
                if(eat >= K) {
                    cur += eat-K;
                    eat = 0;
                }
            }
            else {
                if(0 < eat) {
                    cur = -1;
                    break;
                }
            }
        }
        
        if(cur != -1 && eat > 0) cur = -1;
        
        ans = max(ans, cur);
    }
    
    cout << ans;
    
    return 0;
}
