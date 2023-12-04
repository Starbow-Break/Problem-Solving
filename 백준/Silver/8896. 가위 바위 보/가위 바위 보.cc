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
    
    int T; cin >> T;
    while(T--) {
        vector<string> robots;
        int N; cin >> N;
        for(int i = 1; i <= N; i++) {
            string s; cin >> s;
            robots.pb(s);
        }
        
        bool failed[10] = {false, }; int cnt = N;
        
        for(int i = 0; i < robots[0].length() && cnt > 1; i++) {
            vector<int> vec[3];
            
            for(int j = 0; j < N; j++) {
                if(failed[j]) continue;
                if(robots[j][i] == 'R') vec[0].pb(j);
                if(robots[j][i] == 'S') vec[1].pb(j);
                if(robots[j][i] == 'P') vec[2].pb(j);
            }
            
            if(vec[0].size() && vec[1].size() && !vec[2].size()) {
                for(auto &v: vec[1]) {
                    failed[v] = true;
                    cnt--;
                }
            }
            else if(!vec[0].size() && vec[1].size() && vec[2].size()) {
                for(auto &v: vec[2]) {
                    failed[v] = true;
                    cnt--;
                }
            }
            else if(vec[0].size() && !vec[1].size() && vec[2].size()) {
                for(auto &v: vec[0]) {
                    failed[v] = true;
                    cnt--;
                }
            }
        }
        
        if(cnt > 1) cout << 0;
        else {
            for(int i = 1; i <= N; i++) {
                if(!failed[i-1]) {
                    cout << i;
                    break;
                }
            }
        }
        
        cout << '\n';
    }
    
    return 0;
}