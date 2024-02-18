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

//--------------------------상수-------------------------
const ll a = 1'103'515'245;
const ll c = 12'345;
const ll m = 1LL << 31;
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
//--------------------------상수-------------------------

//--------------------------던전 관련-------------------------
int roomNum; // 방 개수
char roomType[9][9]; // 룸 생성 여부
char dungeon[57][57]; int dh, dw; // 던전 정보

// 방 생성에 사용되는 배열들
vector<pii> room, special; vector<int> require;
//--------------------------던전 관련-------------------------

//--------------------------난수 함수-------------------------
ll S = 0;

// rand()
ll rrand() {
    ll ret = S;
    S = (a*S+c)%m;
    return ret;
}

//randInt(l, r)
int randInt(int l, int r) {
    return l + rrand()%(r-l+1);
}

// chance(p)
bool chance(int p) {
    return randInt(1, 100) <= p;
}

//choice(arr)
template <typename T>
T choice(vector<T> arr) {
    return arr[randInt(0, arr.size()-1)];
}
//--------------------------난수 함수-------------------------

//--------------------------던전 생성-------------------------
// 던전 생성 1단계
void dgStep1() {
    roomNum = randInt(10, 20);
}

// 던전 생성 2단계
void dgStep2() {
    // roomType 초기화
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            roomType[r][c] = '.';
        }
    }
    
    room.pb({4, 4}); // 시작방 생성
    roomType[4][4] = 'R';
    queue<pii> Q;
    
    while(room.size() <= roomNum) {
        Q.push(choice(room));
        while(!Q.empty() && room.size() <= roomNum) {
            pii pos = Q.front(); Q.pop();
            for(int k = 0; k < 4; k++) {
                int nr = pos.fi+dr[k], nc = pos.se+dc[k];
                // 격자를 넘어가면 실패
                if(nr < 0 || nr >= 9 || nc < 0 || nc >= 9) continue;
                // 이미 방이 생성되어 있으면 실패
                if(roomType[nr][nc] != '.') continue;
                
                // 생성하려는 칸의 인접한 칸에 방이 2개 이상 생성되어 있으면 실패
                int cnt = 0;
                for(int l = 0; l < 4; l++) {
                    int nnr = nr+dr[l], nnc = nc+dc[l];
                    cnt += (0 <= nnr && nnr < 9 && 0 <= nnc && nnc < 9 && roomType[nnr][nnc] != '.');
                }
                if(cnt >= 2) continue;
                // chance(50)를 호출한 값이 False면 실패
                if(!chance(50)) continue;
                
                // 모든 조건에 통과하면 방 생성 성공
                roomType[nr][nc] = '*';
                Q.push({nr, nc});
                room.pb({nr, nc});
                
                if(room.size() > roomNum) break;
            }
        }
    }
    
    // room에서 시작방 제거
    room.erase(room.begin());
}

// sepcial에 방 넣기 & 일반방 지정
void assignNormalRoom() {
    // require 생성
    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j < 10-i; j++) {
            require.pb(i);
        }
    }
    
    // sepcial에 방 넣기 & 일반방 지정
    for(auto &p: room) {
        int cnt = 0; // 인접한 방의 개수
        for(int k = 0; k < 4; k++) {
            int nr = p.fi+dr[k], nc = p.se+dc[k];
            cnt += (0 <= nr && nr < 9 && 0 <= nc && nc < 9 && roomType[nr][nc] != '.');
        }
        
        // 1개면 special에 추가
        if(cnt == 1) {
            special.pb(p);
        }
        else { // 아니면 일반방으로 지정
            roomType[p.fi][p.se] = choice(require) + '0';
        }
    }
}

// 보스방 지정
void assignBossRoom() {
    vector<pii> boss;
    for(auto &s: special) {
        bool check = true;
        for(int k = 0; k < 4 && check; k++) {
            int nr = s.fi+dr[k], nc = s.se+dc[k];
            if(0 <= nr && nr < 9 && 0 <= nc && nc < 9 && roomType[nr][nc] == 'R') {
                check = false;
            }
        }
        
        if(check) boss.pb(s);
    }
    
    pii br = choice(boss);
    roomType[br.fi][br.se] = 'B';
    
    vector<pii>::iterator iter;
    for(iter = special.begin(); iter != special.end(); iter++) {
        if(roomType[iter->fi][iter->se] == 'B') break;
    }
    special.erase(iter);
}

// 비밀방 지정
void assignSecretRoom() {
    if(special.size()) {
        pii sr = choice(special);
        roomType[sr.fi][sr.se] = 'X';
        
        vector<pii>::iterator iter;
        for(iter = special.begin(); iter != special.end(); iter++) {
            if(roomType[iter->fi][iter->se] == 'X') break;
        }
        special.erase(iter);
    }
}

// 보물방 지정
void assignTreasureRoom() {
    if(special.size()) {
        pii tr = choice(special);
        roomType[tr.fi][tr.se] = 'T';
        
        vector<pii>::iterator iter;
        for(iter = special.begin(); iter != special.end(); iter++) {
            if(roomType[iter->fi][iter->se] == 'T') break;
        }
        special.erase(iter);
        
        if(roomNum >= 15 && special.size() && chance(25)) {
            pii tr = choice(special);
            roomType[tr.fi][tr.se] = 'T';
            
            vector<pii>::iterator iter;
            for(iter = special.begin(); iter != special.end(); iter++) {
                if(roomType[iter->fi][iter->se] == 'T') break;
            }
            special.erase(iter);
        }
    }
}

// 상정방 지정
void assignStoreRoom() {
    if(special.size() && (roomNum <= 15 || chance(66))) {
        pii sr = choice(special);
        roomType[sr.fi][sr.se] = 'M';
        
        vector<pii>::iterator iter;
        for(iter = special.begin(); iter != special.end(); iter++) {
            if(roomType[iter->fi][iter->se] == 'M') break;
        }
        special.erase(iter);
    }
}

// 악마방 또는 천사방 지정
void assignDevilOrAngelRoom() {
    if(chance(20)) {
        vector<pii> reward;
        pii br; int xm = 4, xM = 4, ym = 4, yM = 4;
        for(auto &r: room) {
            if(roomType[r.fi][r.se] == 'B') br = r;
            xm = min(xm, r.fi); xM = max(xM, r.fi);
            ym = min(ym, r.se); yM = max(yM, r.se);
        }
        
        int dir[4] = {0, 2, 1, 3};
        for(int k = 0; k < 4; k++) {
            int nr = br.fi+dr[dir[k]], nc = br.se+dc[dir[k]];
            if(xm <= nr && nr <= xM && ym <= nc && nc <= yM && roomType[nr][nc] == '.') {
                reward.pb({nr, nc});
            }
        }
        
        pii dar = choice(reward);
        roomType[dar.fi][dar.se] = (chance(50) ? 'D' : 'A');
    }
}

// 희생방 지정
void assignSacrificeRoom() {
    if(special.size()) {
        bool hasAngelRoom = false;
        for(int r = 0; r < 9 && !hasAngelRoom; r++) {
            for(int c = 0; c < 9 && !hasAngelRoom;c++) {
                if(roomType[r][c] == 'A') {
                    hasAngelRoom = true;
                    break;
                }
            }
        }
        
        if(hasAngelRoom || chance(14)) {
            pii sr = choice(special);
            roomType[sr.fi][sr.se] = 'S';
            
            vector<pii>::iterator iter;
            for(iter = special.begin(); iter != special.end(); iter++) {
                if(roomType[iter->fi][iter->se] == 'S') break;
            }
            special.erase(iter);
        }
    }
}

// 저주방 지정
void assignCurseRoom() {
    if(special.size()) {
        bool hasDevilRoom = false;
        for(int r = 0; r < 9 && !hasDevilRoom; r++) {
            for(int c = 0; c < 9 && !hasDevilRoom;c++) {
                if(roomType[r][c] == 'D') {
                    hasDevilRoom = true;
                    break;
                }
            }
        }
        
        if(hasDevilRoom && chance(50)) {
            pii cr = choice(special);
            roomType[cr.fi][cr.se] = 'C';
            
            vector<pii>::iterator iter;
            for(iter = special.begin(); iter != special.end(); iter++) {
                if(roomType[iter->fi][iter->se] == 'C') break;
            }
            special.erase(iter);
        }
    }
}

// 일반방 추가 지정
void assignAdditionalNormalRoom() {
    for(auto &s: special) {
        roomType[s.fi][s.se] = choice(require) + '0';
    }
}

void dgStep3() {
    assignNormalRoom(); // special 생성 및 일반방 지정
    assignBossRoom(); // 보스방 지정
    assignSecretRoom(); // 비밀방 지정
    assignTreasureRoom(); // 보물방 지정
    assignStoreRoom(); // 상점방 지정
    assignDevilOrAngelRoom(); // 악마방 또는 천사방 지정
    assignSacrificeRoom(); // 희생방 지정
    assignCurseRoom(); // 저주방 지정
    assignAdditionalNormalRoom(); // 일반방 추가 지정
}

void dungeonGenerate() {
    dgStep1(); // 던전 생성 1단계
    dgStep2(); // 던전 생성 2단계
    dgStep3(); // 던전 생성 3단계
    
    // 생성된 방들의 정보를 사용해서 실제 던전 모습을 dungeon에 그린다.
    // 왼쪽, 오른쪽, 위, 아래 경계 위치 구하기
    int xm = 4, ym = 4, xM = 4, yM = 4;
    for(auto &r: room) {
        xm = min(xm, r.fi); xM = max(xM, r.fi);
        ym = min(ym, r.se); yM = max(yM, r.se);
    }
    
    // 던전의 벽 그리기
    dh = 6*(xM-xm+1)+3, dw = 6*(yM-ym+1)+3;
    for(int r = 0; r < dh; r++) {
        for(int c = 0; c < dw; c++) {
            if(r == 0 || r == dh-1 || c == 0 || c == dw-1) {
                dungeon[r][c] = '#';
            } else {
                dungeon[r][c] = ' ';
            }
        }
    }
    
    // 각 방 그리기
    for(int r = 0; r <= xM-xm; r++) {
        for(int c = 0; c <= yM-ym; c++) {
            if(roomType[xm+r][ym+c] != '.') {
                // 각 방의 외벽 그리기
                if(roomType[xm+r][ym+c] == 'R' || roomType[xm+r][ym+c] == 'B') {
                    for(int i = 1; i < 4; i++) {
                        dungeon[6*r+2+i][6*c+2] = '@';
                        dungeon[6*r+2+i][6*c+6] = '@';
                    }
                    for(int j = 1; j < 4; j++) {
                        dungeon[6*r+2][6*c+2+j] = '@';
                        dungeon[6*r+6][6*c+2+j] = '@';
                    }
                    dungeon[6*r+2][6*c+2] = '@'; dungeon[6*r+2][6*c+6] = '@';
                    dungeon[6*r+6][6*c+2] = '@'; dungeon[6*r+6][6*c+6] = '@';
                }
                else if(roomType[xm+r][ym+c] == 'D' || roomType[xm+r][ym+c] == 'A') {
                    for(int i = 1; i < 4; i++) {
                        dungeon[6*r+2+i][6*c+2] = '<';
                        dungeon[6*r+2+i][6*c+6] = '>';
                    }
                    for(int j = 1; j < 4; j++) {
                        dungeon[6*r+2][6*c+2+j] = '^';
                        dungeon[6*r+6][6*c+2+j] = 'v';
                    }
                    dungeon[6*r+2][6*c+2] = '/'; dungeon[6*r+2][6*c+6] = '\\';
                    dungeon[6*r+6][6*c+2] = '\\'; dungeon[6*r+6][6*c+6] = '/';
                }
                else {
                    for(int i = 1; i < 4; i++) {
                        dungeon[6*r+2+i][6*c+2] = '|';
                        dungeon[6*r+2+i][6*c+6] = '|';
                    }
                    for(int j = 1; j < 4; j++) {
                        dungeon[6*r+2][6*c+2+j] = '-';
                        dungeon[6*r+6][6*c+2+j] = '-';
                    }
                    dungeon[6*r+2][6*c+2] = '+'; dungeon[6*r+2][6*c+6] = '+';
                    dungeon[6*r+6][6*c+2] = '+'; dungeon[6*r+6][6*c+6] = '+';
                }
                
                // 방 가운데에 적절한 문자 지정
                dungeon[6*r+4][6*c+4] = roomType[xm+r][ym+c];
            }
        }
    }
    
    // 통로 그리기
    for(int r = 0; r <= xM-xm; r++) {
        for(int c = 0; c <= yM-ym; c++) {
            if(roomType[xm+r][ym+c] != 'D' && roomType[xm+r][ym+c] != 'A' && roomType[xm+r][ym+c] != 'X' && roomType[xm+r][ym+c] != '.') {
                for(int k = 0; k < 2; k++) {
                    int nr = xm+r+dr[k], nc = ym+c+dc[k];
                    if(0 <= nr && nr < 9 && 0 <= nc && nc < 9) {
                        if(roomType[nr][nc] != 'D' && roomType[nr][nc] != 'A' && roomType[nr][nc] != 'X' && roomType[nr][nc] != '.') {
                            switch(k) {
                                case 0:
                                    for(int i = 3; i <= 5; i++) {
                                        for(int j = 6; j <= 8; j++) {
                                            if(i == 4)
                                                dungeon[6*r+i][6*c+j] = ' ';
                                            else if(j == 7)
                                                dungeon[6*r+i][6*c+j] = '-';
                                            else {
                                                dungeon[6*r+i][6*c+j] = (dungeon[6*r+i][6*c+j] == '@' ? '@' : '+');
                                            }
                                        }
                                    }
                                    break;
                                case 1:
                                    for(int i = 6; i <= 8; i++) {
                                        for(int j = 3; j <= 5; j++) {
                                            if(j == 4)
                                                dungeon[6*r+i][6*c+j] = ' ';
                                            else if(i == 7)
                                                dungeon[6*r+i][6*c+j] = '|';
                                            else
                                                dungeon[6*r+i][6*c+j] = (dungeon[6*r+i][6*c+j] == '@' ? '@' : '+');
                                        }
                                    }
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }
}
//--------------------------던전 생성-------------------------

//--------------------클리어 가능 여부 판별-------------------
vector<int> status;
int statusIndex[1 << 20];
int parent[20];
int roomId[9][9]; pii roomPos[20]; // 방 아이디, 각 아이디 별 위치
int startId, storeId = -1; // 시작 방 id, 상점 방 id
int (*maxAtk)[10][23][5]; // 방 방문 상태, 체력, 코인, 폭탄

//DFS
void dfs(int cur, int bef = -1) {
    parent[cur] = bef;
    for(int k = 0; k < 4; k++) {
        int nr = roomPos[cur].fi+dr[k], nc = roomPos[cur].se+dc[k];
        if(0 <= nr && nr < 9 && 0 <= nc && nc < 9 && roomId[nr][nc] != -1 && roomId[nr][nc] != bef) {
            dfs(roomId[nr][nc], cur);
        }
    }
}

//클리어 가능 여부 판별
bool isCleared() {
    // 방에 아이디 부여
    int ord = 0;
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            if(roomType[r][c] != '.' && roomType[r][c] != 'D' && roomType[r][c] != 'A' && roomType[r][c] != 'B') {
                roomId[r][c] = ord;
                roomPos[ord] = {r, c};
                if(roomType[r][c] == 'R') startId = ord;
                if(roomType[r][c] == 'M') storeId = ord;
                ord++;
            }
            else {
                roomId[r][c] = -1;
            }
        }
    }
    
    // dfs, 나올 수 있는 상태만 건져내기 위함
    dfs(startId);
    
    // 나올 수 있는 방문 상태만 모으기
    for(int s = 0; s < (1 << ord); s++) {
        bool check = true;
        for(int k = 0; k < ord && check; k++) {
            if(s & (1 << k)) {
                if(parent[k] != -1 && !(s & (1 << parent[k]))) {
                    check = false;
                }
            }
        }
        if(check) {
            status.pb(s);
            statusIndex[s] = status.size()-1;
        }
    }
    
    // maxAtk 초기화
    maxAtk = new int[status.size()][10][23][5];
    for(int i = 0; i < status.size(); i++) {
        for(int j = 0; j < 10; j ++) {
            for(int k = 0; k < 23; k++) {
                for(int l = 0; l < 5; l++) {
                    maxAtk[i][j][k][l] = -1e9;
                }
            }
        }
    }
    
    // ㄱㄱ
    maxAtk[statusIndex[1 << startId]][6][0][3] = 1;
    for(int s = 0; s < status.size(); s++) {
        int stat = status[s];
        vector<int> next;
        for(int k = 0; k < ord; k++) {
            if(!(stat & (1 << k)) && (stat & (1 << parent[k]))) {
                next.pb(k);
            }
        }
        
        for(int hp = 1; hp <= 9; hp++) {
            for(int coin = 22; coin >= 0; coin--) {
                for(int bomb = 0; bomb <= 4; bomb++) {
                    if(maxAtk[s][hp][coin][bomb] == -1e9) continue;
                    
                    bool useStore = storeId != -1 && (stat & (1 << storeId));
                    if(maxAtk[s][hp][coin][bomb]+(useStore ? coin/2 : 0) >= 10) return true;
                    
                    if(useStore) {
                        maxAtk[s][hp][coin-2][bomb] = max(maxAtk[s][hp][coin-2][bomb], maxAtk[s][hp][coin][bomb]+1);
                    }
                    
                    for(auto &nid: next) {
                        pii n = roomPos[nid];
                        // 비밀 방
                        if(roomType[n.fi][n.se] == 'X') {
                            if(bomb) {
                                maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp+2][coin+2][bomb-1] = max(maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp+2][coin+2][bomb-1], maxAtk[s][hp][coin][bomb]+2);
                            }
                        }
                        // 보물 방
                        else if(roomType[n.fi][n.se] == 'T') {
                            maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin][bomb] = max(maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin][bomb], maxAtk[s][hp][coin][bomb]+1);
                        }
                        //상점 방
                        else if(roomType[n.fi][n.se] == 'M') {
                            maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin][bomb] = max(maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin][bomb], maxAtk[s][hp][coin][bomb]);
                        }
                        // 희생 방
                        else if(roomType[n.fi][n.se] == 'S') {
                            if(hp > 2)
                                maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp-2][coin][bomb] = max(maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp-2][coin][bomb], maxAtk[s][hp][coin][bomb]+3);
                            if(useStore) {
                                if(coin >= 2 && hp > 1)
                                    maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp-1][coin-2][bomb] = max(maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp-1][coin-2][bomb], maxAtk[s][hp][coin][bomb]+3);
                                if(coin >= 4)
                                    maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin-4][bomb] = max(maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin-4][bomb], maxAtk[s][hp][coin][bomb]+3);
                            }
                        }
                        // 저주 방
                        else if(roomType[n.fi][n.se] == 'C') {
                            maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin+3][bomb+1] = max(maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin+3][bomb+1], maxAtk[s][hp][coin][bomb]-2);
                        }
                        // 일반 방
                        else {
                            int monsterAtk = roomType[n.fi][n.se] - '0';
                            if(monsterAtk <= maxAtk[s][hp][coin][bomb]) {
                                maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin+1][bomb] = max(maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin+1][bomb], maxAtk[s][hp][coin][bomb]);
                            }
                            else {
                                if(hp > 1) {
                                    maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp-1][coin+1][bomb] = max(maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp-1][coin+1][bomb], maxAtk[s][hp][coin][bomb]);
                                }
                                if(bomb >= 1) {
                                    maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin+1][bomb-1] = max(maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin+1][bomb-1], maxAtk[s][hp][coin][bomb]);
                                }
                                if(useStore && coin >= 2) {
                                    maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin-1][bomb] = max(maxAtk[statusIndex[stat|(1 << roomId[n.fi][n.se])]][hp][coin-1][bomb], maxAtk[s][hp][coin][bomb]);
                                }
                            } 
                        }
                    }
                }
            }
        }
    }
    
    return false;
}
//--------------------클리어 가능 여부 판별-------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 시드 입력 및 S_1 계산
    string seed; cin >> seed;
    for(int i = 0; i < 9; i++) {
        if(seed[i] == '-') continue;
        S = 36*S+('0' <= seed[i] && seed[i] <= '9' ? seed[i]-'0' : seed[i]-'A'+10);
        S %= m;
    }
    
    dungeonGenerate(); // 던전 생성
    
    // 클리어 가능 여부 출력
    cout << (isCleared() ? "CLEAR" : "GAME OVER") << '\n';
    // 던전 출력
    for(int r = 0; r < dh; r++) {
        for(int c = 0; c < dw; c++) {
            cout << dungeon[r][c];
        }
        cout << '\n';
    }
    
    return 0;
}