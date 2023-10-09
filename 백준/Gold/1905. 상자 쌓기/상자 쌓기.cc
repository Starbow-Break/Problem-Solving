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

struct box {
    int px, py, lx, ly, h;
};

vector<box> boxes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int Lx, Ly, N; cin >> Lx >> Ly >> N;
    while(N--) {
        int lx, ly, lz, px, py; cin >> lx >> ly >> lz >> px >> py;
        int h = 0;
        for(auto &b: boxes) {
            int l = b.px, r = b.px+b.lx, d = b.py, u = b.py+b.ly;
            if(r <= px || px+lx <= l) continue;
            if(u <= py || py+ly <= d) continue;
            h = max(h, b.h);
        }
        
        boxes.pb({px, py, lx, ly, h+lz});
    }
    
    int ans = 0;
    for(auto &b: boxes) {
        ans = max(ans, b.h);
    }
    
    cout << ans;
    
    return 0;
}