#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MOD 998244353

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int gomSkill, gomRank;
vector<int> a, r;
int participant;
ll f[1 << 18];

void getFact() {
    f[0] = 1;
    for(int i = 1; i < participant; i++) {
        f[i] = f[i-1]*i;
        f[i] %= MOD;
    }
}

ll solve() {
    ll ret = 0; int idx = 0;
    int w = 2, rr = 1; ll p = 1;
    while(w-1 <= gomRank) {
        while(rr < w) {
            p *= gomRank-rr+1; p %= MOD;
            rr++;
        }
        
        ret += p*f[participant-w]%MOD*r[idx]; ret %= MOD;
        idx++; w *= 2;
    }
    
    return ret;
}

ll inverse(ll x) {
    ll ret = 1;
    ll w = x; int e = MOD-2;
    while(e != 0) {
        if(e%2) {
            ret *= w; ret %= MOD;
        }
        
        w *= w; w %= MOD;
        e /= 2;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int K; cin >> K;
    participant = pow(2, K);
    
    for(int i = 1; i <= participant; i++) {
        int value; cin >> value;
        a.push_back(value);
    }
    
    for(int i = 1; i <= K; i++) {
        int value; cin >> value;
        r.push_back(value);
    }
    
    gomSkill = a[0];
    sort(a.begin(), a.end());
    
    for(int i = 0; i < participant; i++) {
        if(a[i] == gomSkill) { gomRank = i; break; }
    }
    
    getFact();
    ll x = f[participant-1];
    ll y = solve();
    
    cout << (inverse(x)*y)%MOD;

    return 0;
}