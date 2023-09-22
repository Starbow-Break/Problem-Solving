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
    int pos; bool isStart;
    
    bool operator<(node &n) {
        return pos < n.pos;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<node> vec;
    int N; cin >> N;
    repeat(N) {
        int l, r; cin >> l >> r;
        vec.pb({l, true}); vec.pb({r, false});
    }
    
    sort(all(vec));
    
    int bef = vec[0].pos;
    int idx = 0, cnt = 0, ans = 0;
    while(idx < vec.size()) {
        int x = vec[idx].pos;
        int del = 0;
        while(idx < vec.size() && vec[idx].pos == x) {
            if(vec[idx].isStart) del++;
            else del--;
            idx++;
        }
        
        if(cnt > 0 && cnt+del == 0) {
            ans += x-bef;
        }
        if(cnt == 0 && cnt+del > 0) {
            bef = x;
        }
        
        cnt = cnt+del;
    }
    
    cout << ans;
    
    return 0;
}
