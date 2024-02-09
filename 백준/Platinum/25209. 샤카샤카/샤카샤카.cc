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

int N, M;
char arr[30][31];
int tile[10][10], num[10][10];

char tiles[6][3][4] = {
    {"...", "...", "..."},
    {"#..", "##.", "###"},
    {"###", ".##", "..#"},
    {"###", "##.", "#.."},
    {"..#", ".##", "###"},
    {"###", "#*#", "###"}
};

bool checkSquareBlackTile() {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(tile[r][c] == 5 && num[r][c] != -1) {
                int cnt = 0;
                for(int k = 0; k < 4; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    cnt += (0 <= nr && nr < N && 0 <= nc && 
                        nc < M && 1 <= tile[nr][nc] && tile[nr][nc] <= 4);
                }
                if(num[r][c] != cnt) return false;
            }
        }
    }
    
    return true;
}

void deleteWhiteRect1() {
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            for(int l = 2; l <= min(N, M); l++) {
                for(int a = 1; a < l; a++) {
                    bool check = true;
                    int b = l-a;
                    int u = r+a-1, ut = 3, d = r+a, dt = 1;
                    for(int i = 0; i < l && check; i++) {
                        if(tile[u][c+i] != ut) check = false;
                        if(tile[d][c+i] != dt) check = false;
                        for(int j = u+1; j <= d-1 && check; j++) {
                            if(tile[j][c+i] != 0) check = false;
                        }
                        
                        if(ut == 3) {
                            if(u == r) ut = 2;
                            else u--;
                        }
                        else u++;
                        
                        if(dt == 1) {
                            if(d == r+l-1) dt = 4;
                            else d++;
                        }
                        else d--;
                    }
                    
                    u = r+a-1, ut = 3, d = r+a, dt = 1;
                    if(check) {
                        for(int i = 0; i < l; i++) {
                            for(int j = u; j <= d; j++) tile[j][c+i] = 5;
                            
                            if(ut == 3) {
                                if(u == r) ut = 2;
                                else u--;
                            }
                            else u++;
                            
                            if(dt == 1) {
                                if(d == r+l-1) dt = 4;
                                else d++;
                            }
                            else d--;
                        }
                    }
                }
            }
        }
    }
}

void deleteWhiteRect2() {
    for(int sr = 0; sr < N; sr++) {
        for(int er = sr; er < N; er++) {
            for(int sc = 0; sc < M; sc++) {
                for(int ec = sc; ec < M; ec++) {
                    bool check = true;
                    for(int r = sr-1; r <= er+1 && check; r++) {
                        for(int c = sc-1; c <= ec+1 && check; c++) {
                            if((sr <= r && r <= er && sc <= c && c <= ec) && tile[r][c] != 0) {
                                check = false;
                            }
                            if(!(sr <= r && r <= er && sc <= c && c <= ec)
                                && !(!(sr <= r && r <= er) && !(sc <= c && c <= ec))) {
                                if(0 <= r && r < N && 0 <= c && c < M && tile[r][c] != 5)
                                    check = false;
                            }
                        }
                    }
                    
                    if(check) {
                        for(int r = sr; r <= er; r++) {
                            for(int c = sc; c <= ec; c++) {
                                tile[r][c] = 5;
                            }
                        }
                    }
                }
            }
        }
    }
}


bool isValid() {
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            num[r][c] = -1;
            for(int k = 0; k <= 5; k++) {
                bool check = true;
                for(int rr = 0; rr < 3 && check; rr++) {
                    for(int cc = 0; cc < 3 && check; cc++) {
                        if(tiles[k][rr][cc] != '*') {
                            if(arr[3*r+rr][3*c+cc] != tiles[k][rr][cc]) {
                                check = false;
                            }
                        }
                    }
                }
                
                if(check) { tile[r][c] = k; break; }
            }
            
            if(tile[r][c] == 5 && arr[3*r+1][3*c+1] != '#') {
                num[r][c] = arr[3*r+1][3*c+1] - '0';
            }
        }
    }
    
    if(!checkSquareBlackTile()) return false;
    deleteWhiteRect1(); deleteWhiteRect2();
    
    // for(int r = 0; r < N; r++) {
    //     for(int c = 0; c < M; c++) {
    //         cout << tile[r][c];
    //     }
    //     cout << '\n';
    // }
    
    bool check = true;
    for(int r = 0; r < N && check; r++) {
        for(int c = 0; c < M && check; c++) {
            if(tile[r][c] != 5) check = false;
        }
    }
    
    return check;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < 3*N; i++) cin >> arr[i];
    
    cout << (isValid() ? "YES" : "NO");
    
    return 0;
}
