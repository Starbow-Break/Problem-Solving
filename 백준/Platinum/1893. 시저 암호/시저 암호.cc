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
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

vector<int> getFail(vector<int> &p) {
    vector<int> ret;
    ret.pb(0);
    
    int j = 0;
    for(int i = 1; i < p.size(); i++) {
        while(j > 0 && p[i] != p[j]) j = ret[j-1];
        if(p[i] == p[j]) j++;
        ret.pb(j);
    }
    
    return ret;
}

int kmp(vector<int> &s, vector<int> &p, int delta, int mod) {
    int ret = 0;
    vector<int> fail = getFail(p);
    
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != (p[j]+delta) % mod) j = fail[j-1];
        if(s[i] == (p[j]+delta) % mod) j++;
        if(j == p.size()) {
            ret++;
            j = fail[j-1];
        }
    }
    return ret;
}

vector<int> solve(string a, string w, string s) {
    vector<int> sVec, wVec, ret;
    for(auto &c: s) {
        for(int i = 0; i < a.length(); i++) {
            if(a[i] == c) {
                sVec.pb(i);
                break;
            }
        }
    }
    
    for(auto &c: w) {
        for(int i = 0; i < a.length(); i++) {
            if(a[i] == c) {
                wVec.pb(i);
                break;
            }
        }
    }
    
    for(int i = 0; i < a.length(); i++) {
        int result = kmp(sVec, wVec, i, a.length());
        if(result == 1) ret.pb(i);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        string a, w, s; cin >> a >> w >> s;
        vector<int> result = solve(a, w, s);
        sort(all(result));
        if(result.size() == 0) {
            cout << "no solution";
        }
        else if(result.size() == 1) {
            cout << "unique: ";
            for(auto &v: result) cout << v << ' '; 
        }
        else {
            cout << "ambiguous: ";
            for(auto &v: result) cout << v << ' '; 
        }
        cout << '\n';
    }
    
    return 0;
}
