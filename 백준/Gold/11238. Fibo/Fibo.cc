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

const int MOD = 1'000'000'007;

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(b == 1) return 1;
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll fibo(int n) {
    ll a[2][2] = {{1, 0}, {0, 1}};
    ll w[2][2] = {{1, 1}, {1, 0}};
    ll temp[2][2];
    while(n > 0) {
        if(n&1) {
            for(int r = 0; r < 2; r++) {
                for(int c = 0; c < 2; c++) {
                    temp[r][c] = (a[r][0]*w[0][c]+a[r][1]*w[1][c])%MOD;
                }
            }
            for(int r = 0; r < 2; r++) {
                for(int c = 0; c < 2; c++) {
                    a[r][c] = temp[r][c];
                }
            }
        }
        
        for(int r = 0; r < 2; r++) {
            for(int c = 0; c < 2; c++) {
                temp[r][c] = (w[r][0]*w[0][c]+w[r][1]*w[1][c])%MOD;
            }
        }
        for(int r = 0; r < 2; r++) {
            for(int c = 0; c < 2; c++) {
                w[r][c] = temp[r][c];
            }
        }
        n >>= 1;
    }
    
    return a[1][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        cout << fibo(gcd(N, M)) << '\n';
    }
    
    return 0;
}