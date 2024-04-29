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
    
    int N, Q; cin >> N >> Q;
    ll cnt[100'002] = {0, };
    ll maxV = 0;
    
    while(Q--) {
        int q, x, y; cin >> q >> x >> y;
        if(q == 1) {
            cnt[y] += x;
            if(y != N+1) maxV = max(maxV, cnt[y]);
        }
        else {
            cout << (cnt[N+1] + x > maxV + y ? "YES" : "NO") << '\n';
        }
    }
    
    return 0;
}
