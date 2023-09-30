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

int N, M, K;
char arr[300][301];
int dp[300][300];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    for(int r = 0; r < N; r++) cin >> arr[r];
    
    for(int r = N-1; r >= 0; r--) {
        for(int c = M-1; c >= 0; c--) {
            int check = 2;
            if(r+1 < N && arr[r+1][c] != '#' && dp[r+1][c] == 2) check = 1;
            if(c+1 < M && arr[r][c+1] != '#' && dp[r][c+1] == 2) check = 1;
            for(int k = 1; k <= K; k++) {
                if(r+k >= N || c+k >= M) break;
                if(arr[r+k][c+k] == '#') break;
                if(dp[r+k][c+k] == 2) check = 1;
            }
            dp[r][c] = check;
        }
    }
    
    int Q; cin >> Q;
    while(Q--) {
        int x, y; cin >> x >> y;
        cout << (dp[x-1][y-1] == 1 ? "First" : "Second") << '\n';
    }
    
    return 0;
}