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
    
    string s = "DXAW";
    string t = "";
    for(int i = 1; i <= 50; i++) {
        for(int j = 2*(i-1); j < 2*i; j++) {
            for(int k = 0; k < i; k++) {
                t += s[j%4];
            }
        }
    }
    
    int n; cin >> n;
    vector<pii> pos;
    
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        pos.pb({x, y});
    }
    
    string cur = "";
    vector<string> ans(n);
    int cnt = 0, idx = 0;
    int x = 0, y = 0;
    while(cnt < n) {
        cur += t[idx];
        char c = t[idx];
        if(c == 'D') x--;
        if(c == 'A') x++;
        if(c == 'W') y--;
        if(c == 'X') y++;
        
        for(int i = 0; i < n; i++) {
            if(pos[i] == make_pair(x, y)) {
                ans[i] = cur;
                cnt++;
                break;
            }
        }
        
        idx++;
    }
    
    for(int i = 0; i < n; i++) cout << ans[i] << '\n';
    
    return 0;
}