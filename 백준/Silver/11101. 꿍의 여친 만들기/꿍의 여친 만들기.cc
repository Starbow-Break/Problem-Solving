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
    
    int T; cin >> T;
    while(T--) {
        string s, w; cin >> s >> w;
        map<string, int> data;
        
        string cur = ""; int t = 0;
        for(auto &c: s) {
            if('a' <= c && c <= 'z') {
                cur += c;
            }
            else if('0' <= c && c <= '9') {
                t = t * 10 + (c - '0');
            }
            else if(c == ',') {
                data.insert({cur, t});
                cur = ""; t = 0;
            }
        }
        data.insert({cur, t});
        
        cur = "";
        queue<int> q;
        int total = 0;
        for(auto &c: w) {
            if('a' <= c && c <= 'z') {
                cur += c;
            }
            else if(c == '&') {
                total = max(total, data.find(cur)->se);
                cur = "";
            }
            else {
                total = max(total, data.find(cur)->se);
                cur = "";
                q.push(total); total = 0;
            }
        }
        total = max(total, data.find(cur)->se);
        q.push(total);
        
        int ans = 1e9;
        while(!q.empty()) {
            ans = min(ans, q.front()); q.pop();
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
