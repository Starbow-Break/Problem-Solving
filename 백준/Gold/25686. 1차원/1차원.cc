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

void solve(int sz, vector<int> &result) {
    if(sz == 2) {
        result.pb(1); result.pb(2);
        return;
    }
    
    if(sz == 3) {
        result.pb(2); result.pb(3); result.pb(1);
        return;
    }
    
    vector<int> left, right;
    solve((sz+1)/2, left); solve(sz/2, right);
    
    for(auto &l: left) { result.pb(2*l-1); }
    for(auto &r: right) { result.pb(2*r); }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    vector<int> ans;
    solve(N, ans);
    
    for(auto &v: ans) {
        cout << v << ' ';
    }
    
    return 0;
}