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

struct room {
    int t, a, h;
};

vector<room> rooms;

bool play(ll maxhp, ll atk) {
    int idx = 0; ll hp = maxhp;
    while(idx < rooms.size()) {
        if(rooms[idx].t == 1) {
            int cnt = rooms[idx].h/atk+(rooms[idx].h%atk > 0);
            hp -= 1LL*rooms[idx].a*(cnt-1);
            if(hp <= 0) return false;
        }
        else {
            atk += rooms[idx].a; hp = min(maxhp, hp+rooms[idx].h);
        }
        idx++;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, atk; cin >> N >> atk;
    repeat(N) {
        int t, a, h; cin >> t >> a >> h;
        rooms.pb({t, a, h});
    }
    
    ll i = 1, j = 1e18;
    while(i <= j) {
        ll mid = i+j >> 1;
        if(play(mid, atk)) j = mid-1;
        else i = mid+1;
    }
    cout << i;
    
    return 0;
}
