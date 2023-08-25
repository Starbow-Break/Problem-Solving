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
    if(a.fi != b.fi) return a.fi < b.fi;
    return a.se > b.se;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<pii> result;
    
    repeat(N) {
        int solve, panelty;
        cin >> solve >> panelty;
        result.pb({solve, panelty});
    }
    
    sort(result.rbegin(), result.rend(), cmp);
    
    int ans = 0;
    for(int i = 5; i < result.size(); i++) {
        if(result[4].fi != result[i].fi) break;
        ans++;
    }
    
    cout << ans;
    
    return 0;
}