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

char arr[1000][1001];
vector<pii> teachers[2000];

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// finish에 도착한 시간 반환
// deadline을 넘어가면 INF 반환
int progress(int row, int col, int L, int start, int finish, int startTime, int deadline) {
    vector<bool> check(row*col); // 위치에 있을 수 있으면 True, 아니면 false
    
    check[start] = true;
    
    int t = startTime;
    while(t % 10 != 5) t++;
    
    while(t <= deadline) {
        //cout << start << ' ' << finish << ' ' << t << '\n';
        if(t % 10 == 5) { // 파댕이 이동
            vector<bool> temp(row*col);
            for(int i = 0; i < row*col; i++) {
                if(check[i]) {
                    temp[i] = true;
                    for(int k = 0; k < 8; k++) {
                        // 새 위치 계산
                        int nr = i/col+dr[k];
                        int nc = i%col+dc[k];
                        
                        // 이동할 수 있으면 일단 이동 (시선 고려 x)
                        if(0 <= nr && nr < row && 0 <= nc && nc < col && arr[nr][nc] == '.' && !temp[nr*col+nc]) {
                            temp[nr*col+nc] = true;
                            
                            // 도착 지점에 도착하면 t 값 바로 return
                            if(nr*col+nc == finish) return t;
                        }
                    }
                }
            }
            
            // 선생님의 시선이 닿는 위치인지 확인 닿으면 false로 교체
            for(int j = 0; j < L; j++) {
                int p = (t / 10) % teachers[j].size();
                for(int jk = 0; jk < 8; jk++) {
                    int jnr = teachers[j][p].fi+dr[jk];
                    int jnc = teachers[j][p].se+dc[jk];
                    if(0 <= jnr && jnr < row && 0 <= jnc && jnc < col) {
                        if(jnr*col+jnc != start) temp[jnr*col+jnc] = false;
                    }
                }
            }
            
            check = temp;
        }
        else { // 선생님 이동
            // 선생님의 시선이 닿는 위치인지 확인 닿으면 false로 교체
            for(int j = 0; j < L; j++) {
                int p = (t / 10) % teachers[j].size();
                for(int jk = 0; jk < 8; jk++) {
                    int jnr = teachers[j][p].fi+dr[jk];
                    int jnc = teachers[j][p].se+dc[jk];
                    if(0 <= jnr && jnr < row && 0 <= jnc && jnc < col) {
                        if(jnr*col+jnc != start) check[jnr*col+jnc] = false;
                    }
                }
            }
        }
        
        t += 5;
    }
    
    return 1e9;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, L, T, K;
    cin >> N >> M >> L >> T >> K;
    
    for(int r = 0; r < N; r++) cin >> arr[r];
    
    for(int i = 0; i < L; i++) {
        int p; cin >> p;
        while(p--) {
            int x, y; cin >> x >> y;
            teachers[i].pb({x-1, y-1});
        }
    }
    
    if(10*2*max(N-1, M-1)-5 > T) {
        cout << "SAD";
        return 0;
    }
    else {
        // 교실 -> 분식집
        int goTime = progress(N, M, L, 0, N*M-1, 1, T);
        
        if(goTime > T) {
            cout << "SAD";
            return 0;
        }
        
        // 분식집 -> 교실
        int backTime = progress(N, M, L, N*M-1, 0, goTime+K, T);
        
        //cout << goTime << ' ' << backTime << '\n';
        cout << (backTime > T ? "SAD" : "YUMMY");
    }

    return 0;
}
