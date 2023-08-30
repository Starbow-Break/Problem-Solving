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

string op = "*+-/";

string bfs(ll s, ll t) {
    queue<pair<ll, string>> q;
    set<ll> st;
    q.push({s, ""}); st.insert(s);
    
    while(!q.empty()) {
        ll cur = q.front().fi;
        string str = q.front().se;
        q.pop();
        
        if(cur == t) return str;
        
        for(auto &c: op) {
            if(c == '*') {
                if(cur*cur <= 1e9 && st.find(cur*cur) == st.end()) {
                    q.push({cur*cur, str+'*'}); st.insert(cur*cur);
                }            
            }
            if(c == '+') {
                if(cur+cur <= 1e9 && st.find(cur+cur) == st.end()) {
                    q.push({cur+cur, str+'+'}); st.insert(cur+cur);
                } 
            }
            if(c == '-') {
                if(st.find(0) == st.end()) {
                    q.push({0, str+'-'}); st.insert(0);
                } 
            }
            if(c == '/') {
                if(cur != 0 && st.find(1) == st.end()) {
                    q.push({1, str+'/'}); st.insert(1);
                } 
            }
        }
    }
    
    return "-1";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int s, t; cin >> s >> t;
    if(s == t) {
        cout << 0;
        return 0;
    }
    
    cout << bfs(s, t);
    
    return 0;
}