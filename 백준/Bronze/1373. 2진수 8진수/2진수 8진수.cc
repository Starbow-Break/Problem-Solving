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
    
    string s; cin >> s;
    while(s.length()%3) {
        s = '0'+s;
    }
    
    string ans = "";
    for(int i = 0; i < s.length(); i += 3) {
        string t; t += s[i]; t += s[i+1]; t += s[i+2];
        if(t == "000") ans += '0';
        else if(t == "001") ans += '1';
        else if(t == "010") ans += '2';
        else if(t == "011") ans += '3';
        else if(t == "100") ans += '4';
        else if(t == "101") ans += '5';
        else if(t == "110") ans += '6';
        else ans += '7';
    }
    
    cout << ans;
    
    return 0;
}