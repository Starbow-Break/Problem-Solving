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

int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int fish[4][4][8] = {0, };
int smell[4][4] = {0, };
int shark;

void moveFish() {
    int after[4][4][8] = {0, };
    for(int r = 0; r < 4; r++) {
        for(int c = 0; c < 4; c++) {
            for(int d = 0; d < 8; d++) {
                bool check = false;
                for(int k = 0; k < 8; k++) {
                    int nr = r + dr[(d+7*k)%8];
                    int nc = c + dc[(d+7*k)%8];
                    if(0 <= nr && nr < 4 && 0 <= nc && nc < 4) {
                        if(nr*4+nc != shark && !smell[nr][nc]) {
                            after[nr][nc][(d+7*k)%8] += fish[r][c][d];
                            check = true;
                            break;
                        }
                    }
                }
                if(!check) after[r][c][d] += fish[r][c][d];
            }
        }
    }
    
    for(int r = 0; r < 4; r++) {
        for(int c = 0; c < 4; c++) {
            for(int d = 0; d < 8; d++) {
                fish[r][c][d] = after[r][c][d];
            }
        }
    }
}

void moveShark() {
    int ddr[4] = {-1, 0, 1, 0}, ddc[4] = {0, -1, 0, 1};
    int select = -1, maxFish = -1;
    for(int i = 0; i < 64; i++) {
        int dir[3] = {i/16, i%16/4, i%4};
        int sr = shark/4, sc = shark%4;
        bool check = true; int cur = 0;
        bool visited[16] = {false, };
        for(int j = 0; j < 3 && check; j++) {
            sr += ddr[dir[j]];
            sc += ddc[dir[j]];
            if(sr < 0 || sr >= 4) check = false;
            else if(sc < 0 || sc >= 4) check = false;
            else {
                if(!visited[sr*4+sc]) {
                    for(int k = 0; k < 8; k++) {
                        cur += fish[sr][sc][k];
                    }
                }
                visited[sr*4+sc] = true;
            }
        }
        
        if(check && maxFish < cur) {
            select = i;
            maxFish = cur;
        }
    }
    
    int dir[3] = {select/16, select%16/4, select%4};
    int sr = shark/4, sc = shark%4;
    for(int j = 0; j < 3 ; j++) {
        sr += ddr[dir[j]];
        sc += ddc[dir[j]];
        for(int k = 0; k < 8; k++) {
            if(fish[sr][sc][k]) {
                fish[sr][sc][k] = 0;
                smell[sr][sc] = 3;
            }
        }
    }
    
    shark = sr*4+sc;
}

void smellDisappear() {
    for(int r = 0; r < 4; r++) {
        for(int c = 0; c < 4; c++) {
            if(smell[r][c]) smell[r][c]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M, S; cin >> M >> S;
    while(M--) {
        int fx, fy, d; cin >> fx >> fy >> d;
        fish[fx-1][fy-1][d-1] += 1;
    }
    
    int sr, sc; cin >> sr >> sc;
    shark = (sr-1)*4+(sc-1);
    
    while(S--) {
        // 복제
        int clipboard[4][4][8];
        for(int r = 0; r < 4; r++) {
            for(int c = 0; c < 4; c++) {
                for(int d = 0; d < 8; d++)
                    clipboard[r][c][d] = fish[r][c][d];
            }
        }
        
        moveFish();
        moveShark();
        smellDisappear();
        
        for(int r = 0; r < 4; r++) {
            for(int c = 0; c < 4; c++) {
                for(int d = 0; d < 8; d++)
                    fish[r][c][d] += clipboard[r][c][d];
            }
        }
    }
    
    int ans = 0;
    for(int r = 0; r < 4; r++) {
        for(int c = 0; c < 4; c++) {
            int cur = 0;
            for(int d = 0; d < 8; d++) {
                ans += fish[r][c][d];
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
