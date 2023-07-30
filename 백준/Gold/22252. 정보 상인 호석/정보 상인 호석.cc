#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define push_back pb
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int birth[1'000'001] = {0, };
int birthSum[1'000'001] = {0, };
int deathSum[1'000'001] = {0, };

priority_queue<int, vector<int>, less<int>> EMPTY_PQ;
map<string, priority_queue<int, vector<int>, less<int>>> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int Q; cin >> Q;
    ll ans = 0;
    while(Q--) {
        int q; cin >> q;
        if(q == 1) {
            string name; cin >> name;
            int k; cin >> k;
            auto t = mp.find(name);
            if(t == mp.end()) {
                mp.insert({name, EMPTY_PQ});
                t = mp.find(name);
            }
            
            while(k--) {
                int w; cin >> w;
                t->se.push(w);
            }
        }
        else {
            string name; int num; cin >> name >> num;
            auto t = mp.find(name);
            if(t != mp.end()) {
                while(num > 0 && !t->se.empty()) {
                    ans += t->se.top(); t->se.pop();
                    num--;
                }
            }
        }
    }
    
    cout << ans;
    
    return 0;
}