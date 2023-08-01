#include <bits/stdc++.h>
#define repeat(i, s, e) for(int i = s; i < e; i++)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int shark[20][20]; //상어의 위치
int temp[20][20];
int smell_owner[20][20] = {0, }; //냄새 주인
int smell_remain[20][20] = {0, }; //사라지기가지 남은 시간
int d[401]; //상어의 방향
int priority[401][5][4];

int N, M, k; 
int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, -1, 1};

bool can_move(int r, int c, int dir) {
    return 0 <= r+dr[dir] && r+dr[dir] < N && 
        0 <= c+dc[dir] && c+dc[dir] < N && 
        smell_remain[r+dr[dir]][c+dc[dir]] == 0;
}

bool can_move1(int r, int c, int dir) {
    return 0 <= r+dr[dir] && r+dr[dir] < N && 
        0 <= c+dc[dir] && c+dc[dir] < N && 
        smell_owner[r+dr[dir]][c+dc[dir]] == shark[r][c];
}

//상어 이동
void move_shark() {
    bool moved[401] = {false, };
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            temp[r][c] = 0;
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(shark[r][c] && !moved[shark[r][c]]) {
                bool flag = false;
                //냄새가 없는곳이 있는지 확인
                for(auto &dir: priority[shark[r][c]][d[shark[r][c]]]) { 
                    if(can_move(r, c, dir)) {
                        d[shark[r][c]] = dir;
                        flag = true;
                        break;
                    }
                }
                    
                //전부 냄새로 가득하면
                if(!flag) {
                    for(auto &dir: priority[shark[r][c]][d[shark[r][c]]]) { 
                        if(can_move1(r, c, dir)) {
                            d[shark[r][c]] = dir;
                            break;
                        }
                    }
                }
                
                //새 위치로 이동
                if(temp[r+dr[d[shark[r][c]]]][c+dc[d[shark[r][c]]]]  == 0) {
                    temp[r+dr[d[shark[r][c]]]][c+dc[d[shark[r][c]]]] 
                        = shark[r][c];
                }
                else {
                    temp[r+dr[d[shark[r][c]]]][c+dc[d[shark[r][c]]]] 
                        = min(temp[r+dr[d[shark[r][c]]]][c+dc[d[shark[r][c]]]], shark[r][c]);
                }
                
                //이동 했음을 표시
                moved[shark[r][c]] = true;
            }
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            shark[r][c] = temp[r][c];
            if(shark[r][c] > 0) {
                smell_remain[r][c] = k;
                smell_owner[r][c] = shark[r][c];
            }
            else {
                if(smell_remain[r][c] > 0) {
                    smell_remain[r][c] -= 1;
                    if(smell_remain[r][c] == 0) {
                        smell_owner[r][c] = 0;
                    }
                }
            }
        }
    }
}

//종료 조건을 만족하는지 확인
bool isEnd() {
    int cnt = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            cnt += (shark[r][c] != 0);
        }
    }
    return cnt == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> k;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> shark[i][j];
            if(shark[i][j]) {
                smell_owner[i][j] = shark[i][j];
                smell_remain[i][j] = k;
            }
        }
    }
    
    for(int i = 1; i <= M; i++) cin >> d[i];
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= 4; j++) {
            for(int k = 0; k < 4; k++) {
                cin >> priority[i][j][k];
            }
        }
    }
    
    // cout << "-----------------------\n";
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         cout << shark[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "-----------------------\n";
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         cout << smell_owner[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "-----------------------\n";
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         cout << smell_remain[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "-----------------------\n";
    // for(int i = 1; i <= M; i++) cout << d[i] << ' ';
    // cout << '\n';
    // cout << "-----------------------\n";
    
    
    int ans = 0;
    while(ans <= 1000) {
        // 종료 조건을 만족하면 답 출력 후 종료
        if(isEnd()) {
            cout << ans;
            return 0;
        }
        
        ans++;
        move_shark();
        
        // cout << "time = " << ans << '\n';
        // cout << "-----------------------\n";
        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < N; j++) {
        //         cout << shark[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "-----------------------\n";
        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < N; j++) {
        //         cout << smell_owner[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "-----------------------\n";
        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < N; j++) {
        //         cout << smell_remain[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "-----------------------\n";
        // for(int i = 1; i <= M; i++) cout << d[i] << ' ';
        // cout << '\n';
        // cout << "-----------------------\n";
    }
    
    cout << -1;
        
    return 0;
}