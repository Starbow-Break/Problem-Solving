#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(b == 1) return 1;
    if(b == 0) return a;
    return gcd(b, a%b);
}
    
ll f(int p, int q, int n) {
    if(p == 0) return 0;
    if(n == 1) return p/q;
    if(p >= q) return 1LL*(p/q)*n*(n+1)/2+f(p%q, q, n);
    return 1LL*n*p/q*n+n/q-f(q, p, 1LL*n*p/q);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int W; cin >> W;
    while(W--) {
        int p, q, n; cin >> p >> q >> n;
        if(p >= q) p %= q;
        int g = gcd(p, q);
        cout << 1LL*n*(n+1)/2*p-q*f(p/g, q/g, n) << '\n';
    }

    return 0;
}