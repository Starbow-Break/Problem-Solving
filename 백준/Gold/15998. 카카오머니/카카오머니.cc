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

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    return (b ? gcd(b, a%b) : a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    ll f = 0, ub = -1;
    ll remain = 0;
    bool check = true;;
    while(N--) {
        ll a, b; cin >> a >> b;
        if(a > 0) {
            remain += a;
            if(remain != b) check = false;
        }
        else {
            if(remain+a >= 0) {
                remain += a;
                if(remain != b) check = false;
            }
            else {
                remain += a;
                f = gcd(f, b-remain);
                ub = max(ub, b);
                remain = b;
            }
        }
    }
    
    //cout << f << ' ' << ub << '\n';
    
    if(check) {
        if(f == 0) cout << 1;
        else {
            if(f > ub) cout << f;
            else cout << -1;
        }
    }
    else cout << -1;
    
    return 0;
}