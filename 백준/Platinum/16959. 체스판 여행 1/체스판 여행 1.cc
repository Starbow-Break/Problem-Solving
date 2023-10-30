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

const int INF = 1'000'000'000;

const int KNIGHT = 0;
const int BISHOP = 1;
const int ROOK = 2;

int A[300][300];
int pos[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            int v; cin >> v;
            pos[v] = r*N+c;
        }
    }
    
    for(int r = 0; r < 3*N*N; r++) {
        for(int c = 0; c < 3*N*N; c++) A[r][c] = (r == c ? 0 : INF);
    }
    
    for(int i = 0; i < 3*N*N; i++) {
        int p = i/3, k = i%3;
        if(k == KNIGHT) {
            // 말 교체 
            A[i][3*p+BISHOP] = 1;
            A[3*p+BISHOP][i] = 1;
            A[i][3*p+ROOK] = 1;
            A[3*p+ROOK][i] = 1;
            
            // 이동
            int dr[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
            int dc[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
            
            for(int j = 0; j < 8; j++) {
                int nr = p/N+dr[j];
                int nc = p%N+dc[j];
                
                if(0 <= nr && nr < N && 0 <= nc && nc < N) {
                    int np = nr*N+nc;
                    A[i][3*np+KNIGHT] = 1;
                    A[3*np+KNIGHT][i] = 1;
                }
            }
        }
        if(k == BISHOP) {
            // 말 교체 
            A[i][3*p+KNIGHT] = 1;
            A[3*p+KNIGHT][i] = 1;
            A[i][3*p+ROOK] = 1;
            A[3*p+ROOK][i] = 1;
            
            // 이동
            for(int j = -N; j <= N; j++) {
                if(j == 0) continue;
                int nr = p/N+j;
                int nc = p%N+j;
                if(0 <= nr && nr < N && 0 <= nc && nc < N) {
                    int np = nr*N+nc;
                    A[i][3*np+BISHOP] = 1;
                    A[3*np+BISHOP][i] = 1;
                }
            }
            
            for(int j = -N; j <= N; j++) {
                if(j == 0) continue;
                int nr = p/N+j;
                int nc = p%N-j;
                if(0 <= nr && nr < N && 0 <= nc && nc < N) {
                    int np = nr*N+nc;
                    A[i][3*np+BISHOP] = 1;
                    A[3*np+BISHOP][i] = 1;
                }
            }
        }
        if(k == ROOK) {
            // 말 교체 
            A[i][3*p+BISHOP] = 1;
            A[3*p+BISHOP][i] = 1;
            A[i][3*p+KNIGHT] = 1;
            A[3*p+KNIGHT][i] = 1;
            
            // 이동
            for(int r = 0; r < N; r++) {
                int np = r*N+p%N;
                if(np == p) continue;
                A[i][3*np+ROOK] = 1;
                A[3*np+ROOK][i] = 1;
            }
            
            for(int c = 0; c < N; c++) {
                int np = p/N*N+c;
                if(np == p) continue;
                A[i][3*np+ROOK] = 1;
                A[3*np+ROOK][i] = 1;
            }
        }
    }
    
    //Floid-Warshall
    for(int k = 0; k < 3*N*N; k++) {
        for(int r = 0; r < 3*N*N; r++) {
            for(int c = 0; c < 3*N*N; c++) {
                A[r][c] = min(A[r][c], A[r][k]+A[k][c]);
            }
        }
    }
    
    // for(int r = 0; r < 3*N*N; r++) {
    //     for(int c = 0; c < 3*N*N; c++) {
    //         cout << A[r][c] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    int dp[3*N*N];
    fill(dp, dp+3*N*N, INF);
    dp[0] = dp[1] = dp[2] = 0;
    
    for(int i = 2; i <= N*N; i++) {
        for(int k = 0; k < 3; k++) {
            int bef = pos[i-1]; //이전 위치
            int aft = pos[i]; // 디음 위치
            dp[3*(i-1)+k] = min({
                dp[3*(i-1)+k], 
                dp[3*(i-2)]+A[3*bef][3*aft+k],
                dp[3*(i-2)+1]+A[3*bef+1][3*aft+k], 
                dp[3*(i-2)+2]+A[3*bef+2][3*aft+k]
            });
        }
    }
    
    cout << min({dp[3*N*N-3], dp[3*N*N-2], dp[3*N*N-1]});
    
    return 0;
}