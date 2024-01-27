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
    
    int r, c; cin >> r >> c;
    r--; c--;
    bool row[10] = {false, }, col[10] = {false, };
    
    for(int rr = 0; rr < 10; rr++) {
        string s; cin >> s;
        for(int cc = 0; cc < 10; cc++) {
            if(s[cc] == 'o') {
                row[rr] = true; col[cc] = true;
            }
        }
    }
    
    int ans = 100000000;
    for(int rr = 0; rr < 10; rr++) {
        if(row[rr]) continue;
        for(int cc = 0; cc < 10; cc++) {
            if(col[cc]) continue;
            ans = min(ans, abs(rr-r)+abs(cc-c));
        }
    }
    
    cout << ans;
    
    return 0;
}