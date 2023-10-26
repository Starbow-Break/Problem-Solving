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

int arr[1000][1000]; //초기 상태
int num[1000][1000] = {0, }; //사람 수
bool target[1000][1000] = {false }; //추적하는 경로를 기록

pii solve(int N, int M, int K) {
    num[0][0] = K; target[0][0] = true;
    for(int s = 0; s < N+M-1; s++) {
        for(int r = max(0, s-M+1); r <= min(s, N-1); r++) {
            int c = s-r;
            if(arr[r][c]) { //초기에 오른쪽이면
                if(target[r][c]) { //만약 타겟이 여기에 있으면
                    int nr, nc;
                    if(num[r][c]%2) {
                        nr = r, nc = c+1;
                    }
                    else {
                        nr = r+1, nc = c;
                    }
                    
                    if(nr >= N || nc >= M) {
                        return {nr+1, nc+1};
                    }
                    
                    target[nr][nc] = true;
                }
                
                int d = num[r][c]/2;
                if(r+1 < N) num[r+1][c] += d;
                if(c+1 < M) num[r][c+1] += num[r][c]-d;
            }
            else { //초기에 아래쪽이면
                if(target[r][c]) { //만약 타겟이 여기에 있으면
                    int nr, nc;
                    if(num[r][c]%2) {
                        nr = r+1, nc = c;
                    }
                    else {
                        nr = r, nc = c+1;
                    }
                    
                    if(nr >= N || nc >= M) {
                        return {nr+1, nc+1};
                    }
                    
                    target[nr][nc] = true;
                }
                
                int d = num[r][c]/2;
                if(r+1 < N) num[r+1][c] += num[r][c]-d;
                if(c+1 < M) num[r][c+1] += d;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K; cin >> N >> M >> K;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) cin >> arr[r][c];
    }
    
    pii result = solve(N, M, K);
    cout << result.fi << ' ' << result.se;
    
    return 0;
}
