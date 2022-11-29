#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M; int ans;
char board[30][31]; int remain;

void reset() {
    ans = INF; remain = 0;
}

ii move(int r, int c, int d) {
    switch(d) {
        case 0:
            while(1) {
                if(r <= 0 || board[r-1][c] != '.') break;
                r--; board[r][c] = '/'; remain--;
            }
            break;
        case 1:
            while(1) {
                if(r >= N-1 || board[r+1][c] != '.') break;
                r++; board[r][c] = '/'; remain--;
            }
            break;
        case 2:
            while(1) {
                if(c <= 0 || board[r][c-1] != '.') break;
                c--; board[r][c] = '/'; remain--;
            }
            break;
        case 3:
            while(1) {
                if(c >= M-1 || board[r][c+1] != '.') break;
                c++; board[r][c] = '/'; remain--;
            }
    }
    
    return {r, c};
}

void back(int r, int c, int br, int bc) {
    if(c == bc) {
        while(br < r) {
            board[r][c] = '.'; remain++;
            r--;
        }
        while(br > r) {
            board[r][c] = '.'; remain++;
            r++;
        }
    }
    else {
        while(bc < c) {
            board[r][c] = '.'; remain++;
            c--;
        }
        while(bc > c) {
            board[r][c] = '.'; remain++;
            c++;
        }
    }
}

void dfs(int r, int c, int cnt = 0) {
    if(remain == 0) {
        ans = min(ans, cnt);
        return;
    }
    
    if(r > 0 && board[r-1][c] == '.') {
        ii next = move(r, c, 0);
        dfs(next.first, next.second, cnt+1);
        back(next.first, next.second, r, c);
    }//상
    if(r < N-1 && board[r+1][c] == '.') {
        ii next = move(r, c, 1);
        dfs(next.first, next.second, cnt+1);
        back(next.first, next.second, r, c);
    }//하
    if(c > 0 && board[r][c-1] == '.') {
        ii next = move(r, c, 2);
        dfs(next.first, next.second, cnt+1);
        back(next.first, next.second, r, c);
    }//좌
    if(c < M-1 && board[r][c+1] == '.') {
        ii next = move(r, c, 3);
        dfs(next.first, next.second, cnt+1);
        back(next.first, next.second, r, c);
    }//우
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int num = 0;
    while(cin >> N >> M) {
        num++;
        reset();
        
        for(int i = 0; i < N; i++) { 
            cin >> board[i];
            for(int j = 0; j < M; j++) {
                if(board[i][j] == '.') remain++;
            }
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board[i][j] == '.') {
                    board[i][j] = '/'; remain--;
                    dfs(i, j);
                    board[i][j] = '.'; remain++;
                }
            }
        }
        
        cout << "Case " << num << ": ";
        cout << ((ans == INF) ? -1 : ans) << '\n';
    }

    return 0;
}