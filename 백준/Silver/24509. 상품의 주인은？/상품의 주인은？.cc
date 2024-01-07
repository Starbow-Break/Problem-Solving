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

vector<pii> kor, eng, math, sci;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int n, k, e, m, s; cin >> n >> k >> e >> m >> s;
        kor.pb({k, -n}); eng.pb({e, -n});
        math.pb({m, -n}); sci.pb({s, -n});
    }
    
    sort(rall(kor)); sort(rall(eng)); sort(rall(math)); sort(rall(sci));
    
    set<int> st;
    for(auto &k: kor) {
        if(st.find(k.se) == st.end()) {
            cout << -k.se << ' ';
            st.insert(k.se);
            break;
        }
    }
    for(auto &e: eng) {
        if(st.find(e.se) == st.end()) {
            cout << -e.se << ' ';
            st.insert(e.se);
            break;
        }
    }
    for(auto &m: math) {
        if(st.find(m.se) == st.end()) {
            cout << -m.se << ' ';
            st.insert(m.se);
            break;
        }
    }
    for(auto &s: sci) {
        if(st.find(s.se) == st.end()) {
            cout << -s.se << ' ';
            st.insert(s.se);
            break;
        }
    }
    
    return 0;
}