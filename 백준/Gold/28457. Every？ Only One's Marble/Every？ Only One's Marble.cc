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

struct GoldKey {
    int query, x;
};

//--------------보트의 칸 종류--------------
const int SOLD_CITY = -1;
const int CITY = 0;
const int GOLDKEY = 1;
const int START = 2;
const int ISLAND = 3;
const int WELFARE = 4;
const int SPACE = 5;
//--------------보트의 칸 종류--------------

int N; // 보드의 크기
int board[36] = {0, }; // 보드
int price[36] = {0, }; // 땅 가격
ll money; // 소지하고 있는 돈
ll welfareFund = 0; // 복지 기금
int salary; // 월급
queue<GoldKey> goldKeys; // 황금 열쇠 카드
queue<pii> dices; // 주사위 결과

int cur = 0; // 현재 위치
int stop = 0; // 남은 정지 횟수
bool defeat = false; // 패배 여부, 도시를 전부 구매했어도 해당 값이 true면 패배로 간주

//게임 정보 받기
void input() {
    int G;
    cin >> N >> money >> salary >> G;
    // 황금 열쇠 카드
    while(G--) {
        int q, x; cin >> q >> x;
        goldKeys.push({q, x});
    }
    // 특수칸 표시
    board[0] = START;
    board[N-1] = ISLAND;
    board[2*(N-1)] = WELFARE;
    board[3*(N-1)] = SPACE;
    // 일반칸 정보 받기
    int idx = 0;
    while(idx < 4*(N-1)) {
        if(board[idx] != 0) {
            idx++;
            continue;
        }
        
        char c; cin >> c;
        if(c == 'G') {
            board[idx] = GOLDKEY;
        }
        else {
            cin >> price[idx];
            board[idx] = CITY;
        }
        idx++;
    }
    
    // 주사위 정보
    int I; cin >> I;
    while(I--) {
        int a, b; cin >> a >> b;
        dices.push({a, b});
    }
}

// 한 칸 이동
void move() {
    cur = (cur+1)%(4*N-4); // 한칸 이동
    if(board[cur] == START) { // 시작 칸을 지나가면
        money += salary; // 월급을 받는다.
    }
}

// 특정 행동을 취함(도시, 무인도, 사회복지기금)
void action() {
    switch(board[cur]) {
        case CITY:
            if(money >= price[cur]) {
                money -= price[cur];
                board[cur] = SOLD_CITY;
            }
            break;
        case ISLAND:
            stop = 3;
            break;
        case WELFARE:
            money += welfareFund;
            welfareFund = 0;
    }
}

// 황금 열쇠 카드에 대한 행동
bool goldKeyAction(GoldKey goldKey) {
    switch(goldKey.query) {
        case 1:
            money += goldKey.x;
            break;
        case 2:
            money -= goldKey.x;
            if(money < 0) return false;
            break;
        case 3:
            money -= goldKey.x;
            welfareFund += goldKey.x;
            if(money < 0) return false;
            break;
        case 4:
            int cnt = goldKey.x;
            while(cnt--) {
                move();
            }
            action();
    }
    return true;
}

// 게임 플레이
void play() {
    while(!dices.empty() && !defeat) {
        pii dice = dices.front(); dices.pop();
        if(stop) { // 무인도에서 멈추는 횟수가 남아있을 때
            if(dice.fi != dice.se) { // 주사위 눈이 다르면 정지 횟수만 감소
                stop--;
            }
            else stop = 0; // 같으면 바로 탈출 가능, stop을 0으로 초기화
            continue;
        }
        
        if(board[cur] == SPACE) { // 우주 여행 칸에 있으면
            while(board[cur] != START) { // 시작 지점으로 이동
                move();
            }
        }
        
        int moveCnt = dice.fi+dice.se; // 이동 횟수
        while(moveCnt--) {
            move();
        }
        // 황금 열쇠 칸이면 카드를 뽑고 행동을 취한다.
        if(board[cur] == GOLDKEY) {
            GoldKey goldKey = goldKeys.front();
            goldKeys.pop();
            goldKeys.push(goldKey);
            bool success = goldKeyAction(goldKey);
            if(!success) {
                defeat = true;
            }
        }
        else { // 그 이외의 칸은 해당 액션을 취한다.
            action();
        }
    }
}

bool isWin() {
    if(defeat) return false; // 패배 판정을 받으면 패배로 간주
    FOR(i, 0, 4*N-4) {
        if(board[i] == CITY) return false; // 구매하지 않은 도시가 있으면 패배로 간주
    }
    return true; // 패배 판정을 받지 않고 모든 도시를 구매 했으면 승리
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    play();
    cout << (isWin() ? "WIN" : "LOSE");
    
    return 0;
}