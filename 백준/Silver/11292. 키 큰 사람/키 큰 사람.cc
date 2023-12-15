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
    
    int N;
    while(cin >> N) {
        if(!N) break;
        vector<pair<int, string>> data;
        
        while(N--) {
            string name, h;
            cin >> name >> h;
            data.pb({(h[0]-'0')*100+(h[2]-'0')*10+(h[3]-'0'), name});
        }
        
        vector<string> ans;
        int maxH = 0;
        for(auto &[h, name]: data) {
            if(maxH < h) {
                ans.clear();
                ans.pb(name);
                maxH = h;
            }
            else if(maxH == h) {
                ans.pb(name);
            }
        }
            
        for(auto &name: ans) {
            cout << name << ' ';
        }
        cout << '\n';
    }
    
    
    return 0;
}
