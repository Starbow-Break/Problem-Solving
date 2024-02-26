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
    if(a.se != b.se) return a.se > b.se;
    return a.fi < b.fi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<pii> ranges(N);
    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        ranges[i] = {x, y};
    }
    
    sort(all(ranges), cmp);
    
    vector<int> d, v(N);
    
    for(int i = 0; i < N; i++) {
        if(d.empty()) {
            d.pb(ranges[i].fi);
            v[i] = 1;
        }
        else {
            int l = 0, r = d.size()-1;
            while(l <= r) {
                int mid = (l+r) >> 1;
                if(d[mid] > ranges[i].fi) r = mid-1;
                else l = mid+1;
            }
            
            if(l == d.size()) {
                d.pb(ranges[i].fi);
                v[i] = d.size();
            }
            else {
                d[l] = ranges[i].fi;
                v[i] = l+1;
            }
        }
    }
    
    vector<pii> ans;
    int t = d.size(), idx = N-1;
    while(t > 0) {
        if(v[idx] == t) {
            ans.pb(ranges[idx]);
            t--;
        }
        idx--;
    }
    
    reverse(all(ans));
    
    cout << d.size() << '\n';
    for(auto &r: ans) {
        cout << r.fi << ' ' << r.se << '\n';
    }
    
    return 0;
}