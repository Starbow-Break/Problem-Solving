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
    
    string ans = "", ss;
    while(cin >> ss) {
        if(ss == "E-N-D") break;
        string s = "";
        for(auto &c: ss) {
            if('A' <= c && c <= 'Z') s += c-'A'+'a';
            if('a' <= c && c <= 'z') s += c;
            if(c== '-') s += c;
        }
        if(ans.length() < s.length()) ans = s;
    }
    
    cout << ans;
    
    return 0;
}