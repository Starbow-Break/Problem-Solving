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
    
    int N; cin >> N;
    int bitCnt[30] = {0, };
    
    for(int n = 0; n < N; n++) {
        int v; cin >> v;
        for(int i = 0; i < 30; i++) {
            if(v & 1<<i) bitCnt[i]++;
        }
    }
    
    ll ans = 1;
    for(int n = 0; n < N; n++) {
        int v = 0;
        for(int i = 0; i < 30; i++) {
            if(bitCnt[i]) {
                v += (1<<i);
                bitCnt[i]--;
            }
        }
        ans *= v;
        ans %= 1'000'000'007;
    }
    
    cout << ans;
    
    return 0;
}