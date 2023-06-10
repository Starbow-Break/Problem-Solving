#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

ll value[40];
int sz[40];

ll hackenbush(string &s) {
    ll w = 1LL<<40; ll ret = 0;
    
    bool flag = false;
    for(int i = 0; i < s.length(); i++) {
        if(i != 0 && s[i-1] != s[i]) flag = true;
        if(flag) w /= 2;
        
        if(s[i] == 'W') ret += w;
        else ret -= w;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        value[i] = hackenbush(s);
        sz[i] = s.length();
    }
    
    map<ll, int> mp;
    int a = N/2, b = N-a;
    for(int i = 0; i < 1<<a; i++) {
        ll v = 0; int s = 0;
        for(int j = 0; j < a; j++) {
            if(i & (1<<j)) {
                v += value[j]; s += sz[j];
            }
        }
        
        auto t = mp.find(v);
        if(t == mp.end()) mp.insert({v, s});
        else t->second = max(t->second, s);
    }
    
    int ans = 0;
    for(int i = 0; i < 1<<b; i++) {
        ll v = 0; int s = 0;
        for(int j = 0; j < b; j++) {
            if(i & (1<<j)) {
                v += value[a+j]; s += sz[a+j];
            }
        }
        
        auto t = mp.find(-v);
        if(t != mp.end()) {
            ans = max(ans, t->second+s);
        }
    }
    
    cout << ans;

    return 0;
}