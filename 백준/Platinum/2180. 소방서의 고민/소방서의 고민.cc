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

bool cmp(pii &a, pii &b) {
    return b.fi*a.se + b.se < a.fi*b.se + a.se;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<pii> fire;
    
    while(N--) {
        int a, b; cin >> a >> b;
        if(b > 0) fire.pb({a+1, b});
    }
    
    sort(all(fire), cmp);
    
    // for(auto &p: fire) {
    //     cout << p.fi << ' ' << p.se << '\n';
    // }
    
    int ans = 0;
    for(int i = 0; i < fire.size(); i++) {
        ans = (fire[i].fi * ans + fire[i].se) % 40000;
    }
    
    cout << ans;
    
    return 0;
}