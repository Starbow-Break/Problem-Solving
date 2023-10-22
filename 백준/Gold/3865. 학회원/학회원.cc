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

vector<string> EMPTY_VECTOR; // 빈 vector
map<string, vector<string>> mp;
set<string> visited;

int solve(string cur) {
    visited.insert(cur);
    auto iter = mp.find(cur);
    
    if(iter == mp.end()) return 1;
    
    int ret = 0;
    for(auto &next: iter->se) {
        if(visited.find(next) == visited.end()) {
            ret += solve(next);
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    while(cin >> N) {
        if(!N) break;
        
        mp.clear();
        
        string root = "";
        while(N--) {
            string s; cin >> s;
            string t = "", r;
            for(auto &c: s) {
                if(c == ':') {
                    mp.insert({t, EMPTY_VECTOR});
                    r = t;
                    if(root == "") root = r;
                    t = "";
                }
                else if(c == ',' || c == '.') {
                    auto iter = mp.find(r);
                    iter->se.pb(t);
                    t = "";
                }
                else {
                    t += c;
                }
            }
        }
        
        visited.clear();
        cout << solve(root) << '\n';
    }
    
    return 0;
}