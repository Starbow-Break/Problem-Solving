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
char game[50][51]; //게임판
int hp[50][50] = {0, }; //몬스터 hp
int def[50][50] = {0, }; //몬스터 방어력
int _exp[50][50] = {0, }; //몬스터 처치시 획득 가능한 경험치

pii player; //플레이어 위치
pii goal; // 목적지 위치
int level = 1; // 레벨
int atk = 5; // 공격력
int range = 1; // 공격 사거리
int speed = 1; // 이동 속도
int experience = 0; // 경험치
int need_exp = 10; // 요구 경험치
int drug = 0; // 약 섭취 횟수
bool overdose = false; // 오버도즈 상태
int overdose_remain = 0; //오버도즈 해제까지 남은 행동력
int ap = 0; // 행동력
bool is_clear = false; // 클리어 여부

// 이동할 수 있는 위치인지 확인
bool check_move(int nr, int nc) {
    return 0 <= nr && nr < N && 0 <= nc && nc < M && 
        game[nr][nc] != '*' && game[nr][nc] != 'm';
}

//플레이어를 해당 위치로 이동 (이동이 가능하면)
void move(int nr, int nc) {
    // 격자판 안이며 장애물과 몬스터가 없으면
    if(check_move(nr, nc)) {
        ap++;
        // 오버도즈 상태면 오버도즈 상태도 관리
        if(overdose) {
            overdose_remain--;
            if(overdose_remain <= 0) {
                overdose = false;
            }
        }
        
        if(player == goal) game[player.fi][player.se] = 'g';
        else game[player.fi][player.se] = '.';
        game[nr][nc] = 'p';
        player = {nr, nc};
    }
}

// 대기
void wait() {
    ap++;
    // 오버도즈 상태면 오버도즈 상태도 관리
    if(overdose) {
        overdose_remain--;
        if(overdose_remain <= 0) {
            overdose = false;
        }
    }
}

void level_up() {
    while(experience >= need_exp) { // 획득 경험치가 요구 경험치보다 크거나 같을동안
        experience -= need_exp; // 요구 경험치 만큼 경험치 감소
        atk += level; // 공격력 증가
        level++; // 레벨 1 증가
        range++; // 사거리 1 증가
        need_exp += 10; // 요구 경험치 10 증가
    }
}

// 공격
void attack(int sr, int sc, int er, int ec) {
    ap += 3;
    int r = sr, c = sc;
    while(r != er || c != ec) {
        if(r < er) r++;
        if(r > er) r--;
        if(c < ec) c++;
        if(c > ec) c--;
        
        if(game[r][c] == '*') { // 장애물에 부딫히면 공격 종료
            break;
        }
        if(game[r][c] == 'm') {
            hp[r][c] -= max(0, atk-def[r][c]); //몬스터 체력 감소
            if(hp[r][c] <= 0) { // 몬스터 체력이 0 이하가 되면
                game[r][c] = '.'; // 빈칸으로 교체
                experience += _exp[r][c]; // 경험치 증가
            }
        }
    }

}

// 약 복용
void eat_drug(int d_speed) {
    ap += 2;
    speed += d_speed;
    if(speed < 0) speed = 0;
    drug++;
    if(drug >= 5) {
        overdose = true;
        overdose_remain = 10;
        drug = 0;
    }
}

// 클리어
void clear() {
    if(player == goal) {
        is_clear = true;
    }
}

// 마지막 게임 상태 출력
void print_game_status() {
    cout << level << ' ' << experience << '\n';
    cout << ap << '\n';
    FOR(i, 0, N) cout << game[i] << '\n';
    FOR(i, 0, N) {
        FOR(j, 0, M) {
            if(hp[i][j] > 0) cout << hp[i][j] << ' ';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> game[i];
    
    // 몬스터, 플레이어, 목적지 위치 얻기
    vector<pii> monsters;
    FOR(i, 0, N) {
        FOR(j, 0, M) {
            if(game[i][j] == 'm') {
                monsters.pb({i, j});
            }
            if(game[i][j] == 'p') {
                player = {i, j};
            }
            if(game[i][j] == 'g') {
                goal = {i, j};
            }
        }
    }
    
    //몬스터 정보 얻기
    int k; cin >> k;
    for(auto &monster: monsters) cin >> hp[monster.fi][monster.se];
    for(auto &monster: monsters) cin >> def[monster.fi][monster.se];
    for(auto &monster: monsters) cin >> _exp[monster.fi][monster.se];
    
    int Q; cin >> Q;
    while(Q--) {
        string s; cin >> s;
        
        if(s == "u") { //위로 이동
            int nr = player.fi-speed;
            int nc = player.se;
            move(nr, nc);
        }
        if(s == "d") { // 아래로 이동
            int nr = player.fi+speed;
            int nc = player.se;
            move(nr, nc);
        }
        if(s == "l") { // 왼쪽으로 이동
            int nr = player.fi;
            int nc = player.se-speed;
            move(nr, nc);
        }
        if(s == "r") { // 오른쪽으로 이동
            int nr = player.fi;
            int nc = player.se+speed;
            move(nr, nc);
        }
        if(s == "w") { // 대기
            wait();
        }
        if(!overdose) { //아래 동작들은 오버도즈 상태가 아니여야만 할 수 있음
            if(s == "au") { // 위로 공격
                int nr = player.fi-range;
                int nc = player.se;
                attack(player.fi, player.se, nr, nc);
            }
            if(s == "ad") { // 아래로 공격
                int nr = player.fi+range;
                int nc = player.se;
                attack(player.fi, player.se, nr, nc);
            }
            if(s == "al") { // 왼쪽으로 공격
                int nr = player.fi;
                int nc = player.se-range;
                attack(player.fi, player.se, nr, nc);
            }
            if(s == "ar") { // 오른쪽으로 공격
                int nr = player.fi;
                int nc = player.se+range;
                attack(player.fi, player.se, nr, nc);
            }
            if(s == "du") { // 약 먹기 (이동속도 +1)
                eat_drug(1);
            }
            if(s == "dd") { // 약 먹기 (이동속도 -1)
                eat_drug(-1);
            }
            if(s == "c") { // 클리어
                clear();
                if(is_clear) break; // 클리어 상태면 더 이상 행동 불가
            }
        }
        
        if(experience >= need_exp) {
            level_up();
        }
    }
    
    print_game_status(); // 마지막 게임 상태 출력
    
    return 0;
}