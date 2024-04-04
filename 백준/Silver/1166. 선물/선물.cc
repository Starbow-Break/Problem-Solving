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

const long double EPS = 1e-11;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, L, W, H; cin >> N >> L >> W >> H;
    
    long double i = 0, j = 1e9;
    while(j-i > EPS) {
        long double mid = (i+j)/2;
        if(i == mid || j == mid) break;
        ll cnt = 1LL*floor(L/mid+EPS)*floor(W/mid+EPS)*floor(H/mid+EPS);
        //cout << fixed << setprecision(12) << cnt << ' ' << i << ' ' << j << ' ' << mid << '\n';
        if(cnt < N) j = mid;
        else i = mid;
    }
    
    cout << fixed << setprecision(12) << (i+j)/2;
    
    return 0;
}
