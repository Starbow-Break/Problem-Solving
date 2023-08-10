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

// 윷놀이 게임판
// 숫자가 같으면 같은 위치, 점수는 10으로 나눈 몫
int board[4][30] = {
    {-10, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, -11},
    {0, 0, 0, 0, 0, 0, 130, 160, 190, 250, 301, 350, 400, -11},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 221, 241, 250, 301, 350, 400, -11},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 281, 270, 261, 250, 301, 350, 400, -11}
};

vector<int> dices(10);

pii move(pii cur, int cnt) {
    if(cur == make_pair(0, 5)) cur = {1, 5};
    if(cur == make_pair(0, 10)) cur = {2, 10};
    if(cur == make_pair(0, 15)) cur = {3, 15};
    while(cnt--) {
        if(board[cur.fi][cur.se] == -11) return cur;
        cur.se++;
    }
    return cur;
}

int simulate(int status) {
    int score = 0; // 점수
    pii pos[4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}}; // 말의 위치
    
    FOR(i, 0, 10) {
        int t = status%4; // 이동해야 하는 말
        status /= 4;
        // 지금 이동 할 수 없는 말이면 -1 반환
        if(t == 1 && pos[0] == make_pair(0, 0)) return -1;
        if(t == 2 && pos[0] == make_pair(0, 0) && pos[1] == make_pair(0, 0)) return -1;
        if(t == 3 && pos[0] == make_pair(0, 0) && pos[1] == make_pair(0, 0) && pos[2] == make_pair(0, 0)) return -1;
        if(board[pos[t].fi][pos[t].se] == -11) return -1;
        
        pii next = move(pos[t], dices[i]);
        // 이동해야 할 위치에 다른 말이 있으면 -1 반환
        FOR(j, 0, 4) {
            if(board[next.fi][next.se] > 0 
            && board[next.fi][next.se] == board[pos[j].fi][pos[j].se] && j != t) return -1;
        }
        
        pos[t] = next;
        if(board[pos[t].fi][pos[t].se] > 0) score += board[pos[t].fi][pos[t].se]/10;
    }
    
    return score;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    FOR(i, 0, 10) cin >> dices[i];
    
    int ans = 0;
    for(int s = 0; s < 1<<20; s++) {
        ans = max(ans, simulate(s));
    }
    
    cout << ans;
    
    return 0;
}