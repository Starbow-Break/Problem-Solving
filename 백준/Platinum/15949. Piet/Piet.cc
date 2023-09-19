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

//-------------------방향-------------------
const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
//-------------------방향-------------------

int N, M;
char arr[100][101]; //Piet 프로그램
int group[100][101] = {0, }; //그룹별로 묶은 것
char groupChar[10001]; //그룹별 문자
int DP = RIGHT, CC = LEFT; //DP, CC
pii block[10001][8]; //RR, RL, DR, DL, LR, LL, UR, UL

//블록 정보 업데이트
void updateBlockInfo(int idx, pii p) {
    for(int i = 0; i < 8; i++) {
        if(block[idx][i] == make_pair(-1, -1)) {
            block[idx][i] = p;
        }
        else {
            switch(i) {
                case 0: //RR
                if(block[idx][i].se < p.se || (block[idx][i].se == p.se && block[idx][i].fi < p.fi))
                    block[idx][i] = p;
                break;
                case 1: //RL
                if(block[idx][i].se < p.se || (block[idx][i].se == p.se && block[idx][i].fi > p.fi))
                    block[idx][i] = p;
                break;
                case 2: //DR
                if(block[idx][i].fi < p.fi || (block[idx][i].fi == p.fi && block[idx][i].se > p.se))
                    block[idx][i] = p;
                break;
                case 3: //DL
                if(block[idx][i].fi < p.fi || (block[idx][i].fi == p.fi && block[idx][i].se < p.se))
                    block[idx][i] = p;
                break;
                case 4: //LR
                if(block[idx][i].se > p.se || (block[idx][i].se == p.se && block[idx][i].fi > p.fi))
                    block[idx][i] = p;
                break;
                case 5: //LL
                if(block[idx][i].se > p.se || (block[idx][i].se == p.se && block[idx][i].fi < p.fi))
                    block[idx][i] = p;
                break;
                case 6: //UR
                if(block[idx][i].fi > p.fi || (block[idx][i].fi == p.fi && block[idx][i].se < p.se))
                    block[idx][i] = p;
                break;
                case 7: //UL
                if(block[idx][i].fi > p.fi || (block[idx][i].fi == p.fi && block[idx][i].se > p.se))
                    block[idx][i] = p;
                break;
            }
        }
    }
}

//BFS
int ord = 0;
void bfs(int r, int c) {
    ord++;
    queue<pii> q;
    q.push({r, c}); group[r][c] = ord;
    char ch = arr[r][c]; groupChar[ord] = ch;
    
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        updateBlockInfo(ord, cur);
        for(int k = 0; k < 4; k++) {
            int nr = cur.fi+dr[k];
            int nc = cur.se+dc[k];
            if(0 <= nr && nr < N && 0 <= nc && nc < M) {
                if(arr[nr][nc] == ch && !group[nr][nc]) {
                    q.push({nr, nc});
                    group[nr][nc] = ord;
                }
            }
        }
    }
}

//Piet 프로그램 동작
string runPiet() {
    string ret = "";
    
    pii pos = {0, 0};
    while(true) {
        // for(int r = 0; r < N; r++) {
        //     for(int c = 0; c < M; c++) {
        //         if(r == pos.fi && c == pos.se) cout << '@';
        //         else cout << arr[r][c];
        //     }
        //     cout << '\n';
        // }
        // cout << "DP : " << DP << " CC : " << CC << '\n';
        // cout << ret << '\n';
        // cout << "-------------------------------------" << '\n';
    
        int groupNum = group[pos.fi][pos.se];
        ret += arr[pos.fi][pos.se];
        
        bool success = false;
        for(int i = 0; i < 8; i++) {
            pii b = block[groupNum][(DP*4+CC)/2];
            int nr = b.fi+dr[DP];
            int nc = b.se+dc[DP];
            
            // 성공시 반복문을 빠져나온다.
            if(0 <= nr && nr < N && 0 <= nc && nc < M && arr[nr][nc] != 'X') {
                pos = {nr, nc};
                success = true;
                break;
            }
            
            //실패 시 DP와 CC 변경
            if(i%2) DP = (DP+1)%4;
            else CC = (CC+2)%4;
        }
        
        //최종 실패시 프로그램 종료
        if(!success) {
            break;
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int r = 0; r < N; r++) cin >> arr[r];
    
    for(int r = 0; r < 10001; r++) {
        for(int c = 0; c < 8; c++) {
            block[r][c] = {-1, -1};
        }
    }
    
    //bfs로 각 블록의 주요 코델을 찾는다.
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(!group[r][c]) bfs(r, c);
        }
    }
    
    //Piet 프로그램 동작
    cout << runPiet();
    
    return 0;
}
