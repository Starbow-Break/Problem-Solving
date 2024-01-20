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
    int ans = 0;
    
    map<string, int> cnt;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        auto t = cnt.find(s);
        if(t == cnt.end()) {
            cnt.insert({s, 1});
        }
        else {
            t->second++;
        }
    }
    
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        auto t = cnt.find(s);
        if(t != cnt.end() && t->second) {
            ans++;
            t->second--;
        }
    }
    
    cout << ans;
    
    return 0;
}
