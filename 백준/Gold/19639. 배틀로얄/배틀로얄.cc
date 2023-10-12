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

queue<int> enemy[50001];
queue<int> potion[50001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int X, Y, M; cin >> X >> Y >> M;
    FOR(i, 1, X+1) {
        int v; cin >> v;
        enemy[v].push(-i);
    }
    FOR(i, 1, Y+1) {
        int v; cin >> v;
        potion[v].push(i);
    }
    
    vector<int> ans;
    bool clear = true;
    int hp = M;
    
    int idx = M/2;
    for(int i = M/2; i >= 0 && clear; i--) {
        while(!enemy[i].empty()) {
            if(hp <= i) {
                while(idx >= 0 && potion[idx].empty()) idx--;
                if(idx == -1) {
                    clear = false;
                    break;
                }
                ans.pb(potion[idx].front());
                potion[idx].pop();
                hp = min(M, hp+idx);
            }
            else {
                ans.pb(enemy[i].front());
                enemy[i].pop();
                hp -= i;
            }
        }
    }
    
    if(clear) {
        while(idx >= 0) {
            while(!potion[idx].empty()) {
                ans.pb(potion[idx].front());
                potion[idx].pop();
            }
            idx--;
        }
        for(auto &a: ans) cout << a << '\n';
    }
    else cout << 0;
    
    return 0;
}
