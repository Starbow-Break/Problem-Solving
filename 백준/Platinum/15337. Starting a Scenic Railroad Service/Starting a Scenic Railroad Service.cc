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

struct node {
    int pos, isAdd, num;
    
    bool operator<(node &n) {
        if(pos != n.pos) return pos < n.pos;
        return isAdd < n.isAdd;
    }
};

vector<node> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        vec.pb({a, 1, i}); vec.pb({b, 0, i});
    }
    
    sort(all(vec));
    
    int idx = 0;
    int in = 0, out = 0;
    int ans1[200001] = {0, }, minus[200001] = {0, };
    int ans[2] = {0, }, cnt = 0;
    while(idx < vec.size()) {
        int p = vec[idx].pos;
        vector<int> added;
        while(idx < vec.size() && vec[idx].pos == p) {
            if(vec[idx].isAdd) {
                in++;
                added.pb(vec[idx].num);
                cnt++;
            }
            else {
                out++;
                ans1[vec[idx].num] = in;
                cnt--;
            }
            
            idx++;
        }
        
        for(auto &num: added) {
            minus[num] = out;
        }
        
        ans[1] = max(ans[1], cnt);
    }
    
    for(int i = 1; i <= n; i++) ans[0] = max(ans[0], ans1[i]-minus[i]);
    cout << ans[0] << ' ' << ans[1];
    
    return 0;
}
