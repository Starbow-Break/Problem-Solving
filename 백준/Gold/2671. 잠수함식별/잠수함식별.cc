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

bool check(string &s, int i, int numP) {
    if(numP) {
        i += 2;
        if(i == s.length()) return true;
        
        bool ret = false;
        if(i+3 < s.length() && s[i] == '1' && s[i+1] == '0' && s[i+2] == '0') {
            ret |= check(s, i, 0);
        }
        if(i+1 < s.length() && s[i] == '0' && s[i+1] == '1') {
            ret |= check(s, i, 1);
        }
        return ret;
    }
    else {
        i += 2;
        int cnt = 0;
        while(i < s.length()) {
            if(cnt == 0 && s[i] == '1') cnt++;
            if(cnt == 1 && s[i] == '0') break;
            i++;
        }
        
        if(!cnt) return false;
        if(i == s.length()) return true;
        
        bool ret = false;
        if(i+2 < s.length() && s[i-2] == '1' && s[i-1] == '1' && s[i] == '0' && s[i+1] == '0') {
            ret |= check(s, i-1, 0);
        }
        if(i+1 < s.length() && s[i] == '0' && s[i+1] == '1') {
            ret |= check(s, i, 1);
        }
        return ret;
    }
}

//(100~1~|01)~
bool solve(string &s) {
    if(s.length() < 2) return false;
    
    bool ret = false;
    if(3 < s.length() && s[0] == '1' && s[1] == '0' && s[2] == '0') {
        ret |= check(s, 0, 0);
    }
    if(1 < s.length() && s[0] == '0' && s[1] == '1') {
        ret |= check(s, 0, 1);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    
    cout << (solve(s) ? "SUBMARINE" : "NOISE");
    
    return 0;
}