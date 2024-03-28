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
        int N; cin >> N;
        vector<int> vec(N);
        
        for(int i = 0; i < N; i++) cin >> vec[i];
        
        int x = 0, ans = 0, mex = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i <= 29; i++) {
            x |= 1<<i;
            
            for(int j = 0; j < N; j++) {
                pq.push(x & vec[j]);
            }
            
            int cur = 0;
            while(!pq.empty()) {
                if(cur != pq.top()) break;
                
                while(!pq.empty() && cur == pq.top()) pq.pop();
                cur++;
            }
            
            while(!pq.empty()) { pq.pop(); };
            
            if(cur > mex) {
                ans = x; mex = cur;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
