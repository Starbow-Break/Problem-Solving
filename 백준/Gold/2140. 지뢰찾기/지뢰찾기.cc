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

int N;
char arr[100][101];
bool mine[100][101] = {false, };

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int r = 0; r < N; r++) cin >> arr[r];
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(arr[r][c] == '#') {
                mine[r][c] = true;
                for(int k = 0; k < 8; k++) {
                    int nr = r+dr[k], nc = c+dc[k];
                    if(0 <= nr && nr < N && 0 <= nc && nc < N) {
                        if(arr[nr][nc] != '#') {
                            int cnt = 0;
                            for(int k = 0; k < 8; k++) {
                                if(0 <= nr+dr[k] && nr+dr[k] < N && 0 <= nc+dc[k] && nc+dc[k] < N) {
                                    cnt += mine[nr+dr[k]][nc+dc[k]];
                                }
                            }
                            if(arr[nr][nc]-'0' < cnt) {
                                mine[r][c] = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) ans += mine[r][c];
    }
    
    cout << ans;
    
    return 0;
}