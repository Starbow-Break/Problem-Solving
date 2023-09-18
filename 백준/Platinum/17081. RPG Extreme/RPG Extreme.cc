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

//----------------장신구 관련 상수----------------
const int HR = 0; // HP Regeneration
const int RE = 1; // Reincarnation
const int CO = 2; // Courage
const int EX = 3; // Experience
const int DX = 4; // Dexterity
const int HU = 5; // Hunter
const int CU = 6; // Cursed
//----------------장신구 관련 상수----------------

//몬스터
struct monster {
    string name;
    int atk, def, hp, xp;
};

// 아이템
struct item {
    char type; int value;
};

int N, M;
char field[100][101]; //게임 필드
monster monsterInfo[100][100]; //몬스터 정보
item itemInfo[100][100]; //몬스터 정보

//------------------주인공 정보------------------
pii initPos; // 초기 위치
pii playerPos; // 현재 위치
int level = 1; // 레벨
int hp = 20; // 체력
int maxHp = 20; // 최대 체력
int atk = 2; // 공격력
int def = 2; // 방어력
int xp = 0; // 경험치
int weaponAtk = 0; // 무기 공격력
int armorDef = 0; // 방어구 방어력
int accessories = 0; // 장신구, 비트마스킹으로 관리
//------------------주인공 정보------------------

//------------------게임 진행 상황 정보------------------
int turn = 0; // 턴 수
bool death = false; // 사망 여부
string deathSign = ""; // 사망 원인
bool clear = false; // 클리어 여부
//------------------게임 진행 상황 정보------------------

//이동
void move(char cm) {
    int nr = playerPos.fi, nc = playerPos.se;
    if(cm == 'U') nr--;
    if(cm == 'D') nr++;
    if(cm == 'L') nc--;
    if(cm == 'R') nc++;
        
    // 이동이 불가능하면 이동하지 않고 다음 명령 수행
    if(nr < 0 || nr >= N || nc < 0 || nc >= M) return;
    if(field[nr][nc] == '#') return;
    
    playerPos = {nr, nc};
}

// 가시 함정에 들어갈 때 액션
void actionSpikeTrap() {
    hp -= ((accessories & 1 << DX) ? 1 : 5);
    
    // 가시로 인해 사망하면
    if(hp <= 0) {
        hp = 0;
        death = true;
        deathSign = "SPIKE TRAP";
    }
}

//무기 획득 및 교체
void getWeapon(int atk) {
    weaponAtk = atk;
}

// 방어구 획득 및 교체
void getArmor(int def) {
    armorDef = def;
}

//레벨 업
void levelUp() {
    xp = 0;
    level++;
    maxHp += 5;
    atk += 2;
    def += 2;
    hp = maxHp;
}

//몬스터와 배틀
bool battle(monster enemy, bool isBoss) {
    // 총 공격력, 방어력, 보호막(공격 무효화)
    int totalAtk = atk+weaponAtk;
    int totalDef = def+armorDef;
    bool shield = false;
    
    if((accessories & 1 << HU) && isBoss) {
        hp = maxHp;
        shield = true;
    }
    
    //적 체력
    int enemyHp = enemy.hp;
    
    //턴 수
    int battleTurn = 0;
    
    //배틀 시작
    while(true) {
        battleTurn++;
        
        //플레이어 공격
        // CO 장신구를 소지하고 있고 첫번째 턴이면 공격력 2배 적용
        // CO, DX 둘다 소지시 배로 적용
        // 그 외는 그대로
        if((accessories & 1 << CO) && battleTurn == 1) {
            if(accessories & 1 << DX)
                enemyHp -= max(1, 3*totalAtk-enemy.def);
            else
                enemyHp -= max(1, 2*totalAtk-enemy.def);
        }
        else {
            enemyHp -= max(1, totalAtk-enemy.def);
        }
        if(enemyHp <= 0) return true;
        
        // 몬스터 공격
        if(shield) shield = false;
        else {
            hp -= max(1, enemy.atk-totalDef);
            if(hp <= 0) {
                hp = 0;
                return false;
            }
        }
    }
}

// 장신구 획득 및 착용
void getAccessories(int value) {
    int cnt = 0;
    for(int i = 0; i <= 6; i++) {
        if(accessories & 1<<i) {
            cnt++;
            if(i == value) return; // 이미 착용한 종류의 장신구면 패스
        }
    }
    
    if(cnt == 4) return; //이미 4개를 착용했으면 패스
    accessories |= 1 << value;
}

// 부활
void reincarnation() {
    death = false;
    deathSign = "";
    // 최대 체력으로 회복
    hp = maxHp;
    // 처음 위치로 돌려보냄
    playerPos = initPos;
    //장신구 소멸
    accessories ^= 1 << RE;
}

//게임 상태 출력
void printGameStatus() {
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(!death && playerPos == make_pair(r, c)) {
                cout << '@';
            }
            else cout << field[r][c];
        }
        cout << '\n';
    }
    
    cout << "Passed Turns : " << turn << '\n';
    cout << "LV : " << level << '\n';
    cout << "HP : " << hp << '/' << maxHp << '\n';
    cout << "ATT : " << atk << "+" << weaponAtk << '\n';
    cout << "DEF : " << def << "+" << armorDef << '\n';
    cout << "EXP : " << xp << "/" << 5*level << '\n';
    if(clear) {
        cout << "YOU WIN!";
    }
    else if(death) {
        cout << "YOU HAVE BEEN KILLED BY " << deathSign << "..";
    }
    else {
        cout << "Press any key to continue.";
    }
}

// 게임 플레이
void play(string command) {
    for(auto &cm: command) {
        turn++;
        
        // 이동
        move(cm);
        
        int r = playerPos.fi, c = playerPos.se;
        // 가시에 걸릴 때
        if(field[r][c] == '^') {
            actionSpikeTrap();
        }
        // 아이템 상자를 얻을 때
        else if(field[r][c] == 'B') {
            item curItem = itemInfo[r][c];
            if(curItem.type == 'W') { //무기
                getWeapon(curItem.value);
            }
            else if(curItem.type == 'A') { // 갑옷
                getArmor(curItem.value);
            }
            else { // 장신구
                getAccessories(curItem.value);
            }
            field[r][c] = '.';
        }
        //몬스터랑 조우할 때
        else if(field[r][c] == '&' || field[r][c] == 'M') {
            monster curMonster = monsterInfo[r][c];
            if(battle(curMonster, field[r][c] == 'M')) { //승리하면
                // 경험치 획득 및 레벨 업
                if(accessories & 1 << EX) xp += curMonster.xp*6/5;
                else xp += curMonster.xp;
                
                if(xp >= 5*level) levelUp();
                
                //HR 소지시 체력 3 회복
                if(accessories & 1 << HR) {
                    hp = min(maxHp, hp+3);
                }
                
                // 잡은 몬스터가 보스 몬스터면 클리어
                if(field[r][c] == 'M') clear = true;
                
                //잡았으니 빈칸으로 교체
                field[r][c] = '.';
            }
            else { //패배하면
                death = true;
                deathSign = curMonster.name;
            }
        }
        
        // 게임을 클리어했으면 종료
        if(clear) return;
        // 사망한 상태면
        if(death) {
            //RE 장신구가 있으면
            if(accessories & 1 << RE) {
                reincarnation();
            }
            else return; //RE가 없으면 부활 불가, 게임 종료
        }
        
        // cout << "direction : " << cm << '\n';
        // printGameStatus();
        // cout << "------------------------------------" << '\n';
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int r = 0; r < N; r++) cin >> field[r];
    
    string s; cin >> s;
    
    int monsterNum = 0, itemNum = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(field[r][c] == '&' || field[r][c] == 'M') monsterNum++;
            if(field[r][c] == 'B') itemNum++;
            if(field[r][c] == '@') {
                initPos = playerPos = {r, c};
                field[r][c] = '.';
            }
        }
    }
    
    while(monsterNum--) {
        int R, C, W, A, H, E;
        string S;
        cin >> R >> C >> S >> W >> A >> H >> E;
        monsterInfo[R-1][C-1] = {S, W, A, H, E};
    }
    
    while(itemNum--) {
        int R, C; char T; cin >> R >> C >> T;
        int S;
        if(T == 'W' || T == 'A') {
            cin >> S;
        }
        else {
            string s; cin >> s;
            if(s == "HR") S = HR;
            if(s == "RE") S = RE;
            if(s == "CO") S = CO;
            if(s == "EX") S = EX;
            if(s == "DX") S = DX;
            if(s == "HU") S = HU;
            if(s == "CU") S = CU;
        }
        itemInfo[R-1][C-1] = {T, S};
    }
    
    play(s);
    printGameStatus();
    
    return 0;
}