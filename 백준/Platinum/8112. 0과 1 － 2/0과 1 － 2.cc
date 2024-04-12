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

bool visited[1'000'000];
int bef[1'000'000];
int value[1'000'000];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        fill(visited, visited+N, false);
        fill(bef, bef+N, -1);
        fill(value, value+N, -1);
        
        while(!q.empty()) { q.pop(); }
        
        if(N == 1) {
            cout << 1 << '\n';
            continue;
        }
        
        q.push(1); visited[1] = true; value[1] = 1;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            
            int next = cur*10%N;
            if(!visited[next]) {
                visited[next] = true;
                bef[next] = cur;
                value[next] = 0;
                q.push(next);
            }
            
            next = (cur*10+1)%N;
            if(!visited[next]) {
                visited[next] = true;
                bef[next] = cur;
                value[next] = 1;
                q.push(next);
            }
        }
        
        if(!visited[0]) {
            cout << "BRAK";
        }
        else {
            string ans = "";
            int cur = 0;
            while(cur != -1) {
                ans = (char)('0' + value[cur]) + ans;
                cur = bef[cur];
            }
            
            cout << ans;
        }
        
        cout << '\n';
    }
    
    return 0;
}