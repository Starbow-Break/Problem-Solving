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

int R, C, K;
char arr[5][6];

int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1};

int ans = 0;
bool visited[5][5] = {false, };

void travel(int r = R-1, int c = 0, int k = 1) {
    if(r == 0 && c == C-1) {
        ans += (k == K);
        return;
    }
    
    if(k == K) return;
    
    visited[r][c] = true;
    for(int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if(0 <= nr && nr < R && 0 <= nc && nc < C) {
            if(!visited[nr][nc] && arr[nr][nc] != 'T') travel(nr, nc, k+1);
        }
    }
    
    visited[r][c] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C >> K;
    for(int r = 0; r < R; r++) cin >> arr[r];
    
    travel();
    
    cout << ans;
    
    return 0;
}
