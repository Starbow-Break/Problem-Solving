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

int N, M;
set<int> success[1001];
vector<int> request[1001];
vector<int> limit(1001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 1; i <= M; i++) cin >> limit[i];
    
    for(int i = 1; i <= N; i++) {
        int v;
        while(cin >> v) {
            if(v == -1) break;
            request[v].pb(i);
        }
    }
    
    for(int i = 1; i <= M; i++) {
        for(auto &v: request[i]) {
            if(request[i].size() <= limit[i]) {
                success[v].insert(i);
            }
        }
    }
    
    for(int i = 1; i <= N; i++) {
        int v;
        while(cin >> v) {
            if(v == -1) break;
            request[v].pb(i);
        }
    }
    
    for(int i = 1; i <= M; i++) {
        for(auto &v: request[i]) {
            if(request[i].size() <= limit[i]) {
                success[v].insert(i);
            }
        }
    }
    
    for(int i = 1; i <= N; i++) {
        if(success[i].size() > 0) {
            for(auto &v: success[i]) {
                cout << v << ' ';
            }
        }
        else {
            cout << "망했어요";
        }
        cout << '\n';
    }
    
    return 0;
}