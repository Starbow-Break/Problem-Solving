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

map<pair<string, int>, double> dp;

int N;

void bfs(pair<string, int> start) {
    queue<pair<string, int>> q;
    q.push(start); dp.insert({start, 1});
    
    while(!q.empty()) {
        string cur = q.front().fi;
        int d = q.front().se;
        q.pop();
        
        auto b = dp.find({cur, d});
        
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = i+1; j < N; j++) {
                cnt += (cur[i] > cur[j]);
            }
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = i+1; j < N; j++) {
                if(cur[i] > cur[j]) {
                    string next = cur;
                    swap(next[i], next[j]);
                    
                    auto t = dp.find({next, d+1});
                    
                    if(t == dp.end()) {
                        q.push({next, d+1});
                        dp.insert({{next, d+1}, b->se/cnt});
                    }
                    else {
                        t->se += b->se/cnt;
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    string init = "";
    
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        init += (char)('0' + v);
    }
    
    bfs({init, 0});
    
    double ans = 0;
    string sortedStatus = "";
    
    for(int i = 1; i <= N; i++) {
        sortedStatus += (char)('0' + i);
    }
    
    for(int i = 0; i <= 28; i++) {
        auto t = dp.find({sortedStatus, i});
        if(t != dp.end()) {
            ans += i*(t->se);
        }
    }
    
    cout << fixed << setprecision(12) << ans;
    
    return 0;
}