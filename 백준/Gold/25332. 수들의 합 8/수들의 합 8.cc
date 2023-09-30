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
    
    int N; cin >> N;
    vector<int> vec(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> vec[i];
    }
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        vec[i] -= v;
    }
    for(int i = 1; i <= N; i++) {
        vec[i] += vec[i-1];
    }
    
    map<int, int> cnt;
    
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        auto t = cnt.find(vec[i-1]);
        if(t == cnt.end()) cnt.insert({vec[i-1], 1});
        else t->second++;
        
        auto p = cnt.find(vec[i]);
        if(p != cnt.end()) ans += p->second;
    }
    
    cout << ans;
    
    return 0;
}