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

map<pii, int> cnt;

ll modPow(int a, int e) {
    ll ret = 1, w = a;
    while(e) {
        if(e&1) {
            ret *= w; ret %= MOD;
        }
        w *= w; w %= MOD;
        e >>= 1;
    }
    return ret;
}

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    return (b ? gcd(b, a%b) : a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int A, B, C; cin >> A >> B >> C;
        if(A < 0) { A *= -1; B *= -1; }
        
        if(A == 0) B = 1;
        else if(B == 0) A = 1;
        else {
            int g = gcd(abs(A), abs(B));
            A /= g; B /= g;
        }
        
        auto t = cnt.find({A, B});
        if(t == cnt.end()) {
            cnt.insert({{A, B}, 1});
        }
        else {
            t->second++;
        }
    }
    
    vector<int> sum, sumSq;
    sum.pb(0); sumSq.pb(0);
    for(auto &[p, c]: cnt) {
        sum.pb(c);
        sumSq.pb(1LL*c*c%MOD);
    }
    
    for(int i = 1; i < sum.size(); i++) {
        sum[i] += sum[i-1];
        sum[i] %= MOD;
        sumSq[i] += sumSq[i-1];
        sumSq[i] %= MOD;
    }
    
    ll ans = 0;
    int inv2 = modPow(2, MOD-2);
    for(int i = 1; i < sum.size(); i++) {
        ll temp = 1LL*(sum.back()+MOD-sum[i])*(sum.back()+MOD-sum[i])%MOD;
        temp += MOD-(sumSq.back()-sumSq[i]); temp %= MOD;
        temp *= inv2; temp %= MOD;
        ans += 1LL*(sum[i]+MOD-sum[i-1])*temp%MOD; ans %= MOD;
    }
    
    cout << ans;
    
    return 0;
}
