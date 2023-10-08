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
    
    string s, t; cin >> s >> t;
    int lenS = s.length(), lenT = t.length();
    int ans = lenS+lenT;
    for(int i = 1-lenT; i < lenS; i++) {
        bool check = true;
        int l = lenS+lenT;
        for(int j = 0; j < lenT; j++) {
            if(i+j >= 0 && i+j < lenS) {
                l--;
                if(s[i+j] == '2' &&  t[j] == '2') check = false;
            }
        }
        
        if(check) ans = min(ans, l);
    }
    
    cout << ans;
    
    return 0;
}