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

char arr[32][33] = {
    "..----..----..----..----..----..",
    "..    ..    ..    ..    ..    ..",
    "| \\                          / |",
    "|  \\                        /  |",
    "|   \\                      /   |",
    "|    ..                  ..    |",
    "..   ..                  ..   ..",
    "..     \\                /     ..",
    "|       \\              /       |",
    "|        \\            /        |",
    "|         ..        ..         |",
    "|         ..        ..         |",
    "..          \\      /          ..",
    "..           \\    /           ..",
    "|             \\  /             |",
    "|              ..              |",
    "|              ..              |",
    "|             /  \\             |",
    "..           /    \\           ..",
    "..          /      \\          ..",
    "|         ..        ..         |",
    "|         ..        ..         |",
    "|        /            \\        |",
    "|       /              \\       |",
    "..     /                \\     ..",
    "..   ..                  ..   ..",
    "|    ..                  ..    |",
    "|   /                      \\   |",
    "|  /                        \\  |",
    "| /                          \\ |",
    "..    ..    ..    ..    ..    ..",
    "..----..----..----..----..----.."
};

int status[31][2] = {0, }; // 각 칸별로 말의 상태
int curPos[2][4] = {0, }; // 말의 위치 (0 : 안 올라감, -1 : 도착)
pii pos[31] = {
    {-1, -1},
    {24, 30}, {18, 30}, {12, 30}, {6, 30}, {0, 30},
    {0, 24}, {0, 18}, {0, 12}, {0, 6}, {0, 0},
    {6, 0}, {12, 0}, {18, 0}, {24, 0}, {30, 0},
    {30, 6}, {30, 12}, {30, 18}, {30, 24}, {30, 30},
    {5, 25}, {10, 20}, {15, 15}, {20, 10}, {25, 5}, 
    {5, 5}, {10, 10}, {-1, -1}, {20, 20}, {25, 25}, 
};

void update() {
    for(int i = 1; i <= 30; i++) {
        if(i == 28) continue;
        int r = pos[i].fi;
        int c = pos[i].se;
        for(int j = 0; j < 4; j++) {
            if(status[i][0] & 1<<j) {
                arr[r+j/2][c+j%2] = 'A'+j;
            }
            else if(status[i][1] & 1<<j) {
                arr[r+j/2][c+j%2] = 'a'+j;
            }
            else {
                arr[r+j/2][c+j%2] = '.';
            }
        }
    }
}

void printAnswer() {
    update();
    for(int r = 0; r < 32; r++) {
        for(int c = 0; c < 32; c++) cout << arr[r][c];
        cout << '\n';
    }
}

void move(int i, int j, int cnt) {
    int cur = curPos[i][j];
    int next = cur;
    int is = status[cur][i];
    
    if(is == 0) { 
        is |= 1<<j;
    }
    
    // 시작 위치가 어딘지에 따라 다른 방향으로 가는 케이스 고려
    if(next == 5) {
        next = 21;
        cnt--;
    }
    if(next == 10) {
        next = 26;
        cnt--;
    }
    if(next == 23) {
        next = 29;
        cnt--;
    }
    
    //남은 횟수만큼 이동
    while(cnt--) {
        if(next == 25)
            next = 15;
        else if(next == 30)
            next = 20;
        else if(next == 20) {
            next = -1;
            break;
        }
        else next++;
    }
    if(next == 28) next = 23;
    
    //해당 위치로 이동
    status[cur][i] = 0;
    if(next != -1) status[next][i] |= is;
    for(int k = 0; k < 4; k++) {
        if(is & 1<<k) {
            curPos[i][k] = next;
        }
    }
    
    //다른 팀 말이 있으면 제거
    if(next != -1 && status[next][1-i]) {
        for(int k = 0; k < 4; k++) {
            if(status[next][1-i] & 1<<k) {
                curPos[1-i][k] = 0;
            }
        }
        status[next][1-i] = 0;
    }
}

void move(char c, string s) {
    //cout << c << ' ' << s << '\n';
    int i, j, k = 0;
    for(int i = 0; i < 4; i++) {
        k += (s[i] == 'F');
    }
    if(k == 0) k = 5;
    
    if('a' <= c) {i = 1, j = c-'a';}
    else {i = 0, j = c-'A';}
    
    move(i, j, k);
    
    //printAnswer();
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        char c; string s; cin >> c >> s;
        move(c, s);
    }
    
    printAnswer();
    
    return 0;
}