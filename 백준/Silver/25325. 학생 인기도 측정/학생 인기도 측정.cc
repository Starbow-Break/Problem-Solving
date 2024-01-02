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

bool cmp(pair<int, string> &a, pair<int, string> &b) {
    if(a.fi != b.fi) return a.fi > b.fi;
    return a.se < b.se;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    map<string, int> favorite;
    
    for(int i = 0; i < N; i++) {
        string name; cin >> name;
        favorite.insert({name, 0});
    }
    
    cin.ignore();
    for(int i = 0; i < N; i++) {
        string s; getline(cin, s);
        s += ' ';
        
        string name = "";
        for(auto &c: s) {
            if(c == ' ') {
                auto t = favorite.find(name);
                t->second++;
                name = "";
            }
            else name += c;
        }
    }
    
    vector<pair<int, string>> result;
    for(auto &[name, count]: favorite) {
        result.pb({count, name});
    }
    
    sort(all(result), cmp);
    
    for(auto &[count, name]: result) {
        cout << name << ' ' << count << '\n';
    }
    
    return 0;
}
