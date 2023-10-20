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
    
    int N; cin >> N;
    vector<pii> pos; //용사들의 위치
    for(int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        pos.pb({x, y});
    }
    
    pii delta = {0, 0}; //위치 보정
    vector<string> route(N); //경로
    bool finished[500] = {false, }; //도착 여부
    
    int cnt = 0;
    string t = "";
    while(cnt < N) {
        int target = -1;
        for(int i = 0; i < N; i++) {
            if(!finished[i]) {
                if(target == -1) target = i;
                else {
                    if(abs(pos[target].fi+delta.fi)+abs(pos[target].se+delta.se)
                    > abs(pos[i].fi+delta.fi)+abs(pos[i].se+delta.se)) {
                        target = i;
                    }
                }
            }
        }
        
        int dx = -(pos[target].fi+delta.fi);
        int dy = -(pos[target].se+delta.se);
        delta.fi += dx; delta.se += dy;
        while(dx > 0) {
            t += 'D'; dx--;
        }
        while(dx < 0) {
            t += 'A'; dx++;
        }
        while(dy > 0) {
            t += 'W'; dy--;
        }
        while(dy < 0) {
            t += 'X'; dy++;
        }
        
        route[target] = t;
        finished[target] = true;
        cnt++;
    }
    
    for(int i = 0; i < N; i++) cout << route[i] << '\n';
    
    return 0;
}