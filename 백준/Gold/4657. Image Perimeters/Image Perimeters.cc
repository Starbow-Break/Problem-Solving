#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v: vec)
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

int dr[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dc[8] = {0, -1, 1, 0, -1, 1, -1, 1};

int R, C, r, c;
char arr[20][21];

void bfs(int cur) {
    queue<int> q;
    q.push(cur); arr[cur/C][cur%C] = '*';
    
    while(!q.empty()) {
        int v = q.front(); q.pop();
        FOR(k, 0, 8) {
            int nr = v/C+dr[k], nc = v%C+dc[k];
            if(0 <= nr && nr < R && 0 <= nc && nc < C && arr[nr][nc] == 'X') {
                q.push(nr*C+nc);
                arr[nr][nc] = '*';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(cin >> R >> C >> r >> c) {
        if(!R && !C && !r && !c) break;
        
        FOR(i, 0, R) cin >> arr[i];
        
        bfs((r-1)*C+(c-1));
        
        int ans = 0;
        FOR(i, 0, R) {
            FOR(j, 0, C) {
                if(arr[i][j] == '*') {
                    ans += 4;
                    FOR(k, 0, 4) {
                        int nr = i+dr[k], nc = j+dc[k];
                        ans -= (0 <= nr && nr < R && 0 <= nc && nc < C && arr[nr][nc] == '*');
                    }
                }
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
