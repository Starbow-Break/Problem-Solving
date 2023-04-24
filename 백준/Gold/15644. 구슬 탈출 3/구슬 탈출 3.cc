#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M;
char arr[10][11];

pair<bool, char> left() {
    bool change = false; char goal = 'X';
    for(int i = 1; i < N-1; i++) {
        int idx = 1; int goalIdx = -1;
        for(int j = 1; j < M-1; j++) {
            if(arr[i][j] == '#') {
                idx = j+1;
            }
            if(arr[i][j] == 'O') {
                idx = j; goalIdx = j;
            }
            if(arr[i][j] == 'R') {
                if(idx == goalIdx && goal != 'B') {
                    goal = 'R';
                }
                else {
                    if(idx != j) {
                        change = true;
                        arr[i][idx] = 'R';
                        arr[i][j] = '.';
                    }
                    idx++;
                }
            }
            if(arr[i][j] == 'B') {
                if(idx == goalIdx) {
                    goal = 'B';
                }
                else {
                    if(idx != j) {
                        change = true;
                        arr[i][idx] = 'B';
                        arr[i][j] = '.';
                    }
                    idx++;
                }
            }
        }
    }
    
    return {change, goal};
}
pair<bool, char> right() {
    bool change = false; char goal = 'X';
    for(int i = 1; i < N-1; i++) {
        int idx = M-2; int goalIdx = -1;
        for(int j = M-2; j >= 1; j--) {
            if(arr[i][j] == '#') {
                idx = j-1;
            }
            if(arr[i][j] == 'O') {
                idx = j; goalIdx = j;
            }
            if(arr[i][j] == 'R') {
                if(idx == goalIdx && goal != 'B') {
                    goal = 'R';
                }
                else {
                    if(idx != j) {
                        change = true;
                        arr[i][idx] = 'R';
                        arr[i][j] = '.';
                    }
                    idx--;
                }
            }
            if(arr[i][j] == 'B') {
                if(idx == goalIdx) {
                    goal = 'B';
                }
                else {
                    if(idx != j) {
                        change = true;
                        arr[i][idx] = 'B';
                        arr[i][j] = '.';
                    }
                    idx--;
                }
            }
        }
    }
    
    return {change, goal};
}
pair<bool, char> up() {
    bool change = false; char goal = 'X';
    for(int j = 1; j < M-1; j++) {
        int idx = 1; int goalIdx = -1;
        for(int i = 1; i < N-1; i++) {
            if(arr[i][j] == '#') {
                idx = i+1;
            }
            if(arr[i][j] == 'O') {
                idx = i; goalIdx = i;
            }
            if(arr[i][j] == 'R') {
                if(idx == goalIdx && goal != 'B') {
                    goal = 'R';
                }
                else {
                    if(idx != i) {
                        change = true;
                        arr[idx][j] = 'R';
                        arr[i][j] = '.';
                    }
                    idx++;
                }
            }
            if(arr[i][j] == 'B') {
                if(idx == goalIdx) {
                    goal = 'B';
                }
                else {
                    if(idx != i) {
                        change = true;
                        arr[idx][j] = 'B';
                        arr[i][j] = '.';
                    }
                    idx++;
                }
            }
        }
    }
    
    return {change, goal};
}
pair<bool, char> down() {
    bool change = false; char goal = 'X';
    for(int j = 1; j < M-1; j++) {
        int idx = N-2; int goalIdx = -1;
        for(int i = N-2; i >= 1; i--) {
            if(arr[i][j] == '#') {
                idx = i-1;
            }
            if(arr[i][j] == 'O') {
                idx = i; goalIdx = i;
            }
            if(arr[i][j] == 'R') {
                if(idx == goalIdx && goal != 'B') {
                    goal = 'R';
                }
                else {
                    if(idx != i) {
                        change = true;
                        arr[idx][j] = 'R';
                        arr[i][j] = '.';
                    }
                    idx--;
                }
            }
            if(arr[i][j] == 'B') {
                if(idx == goalIdx) {
                    goal = 'B';
                }
                else {
                    if(idx != i) {
                        change = true;
                        arr[idx][j] = 'B';
                        arr[i][j] = '.';
                    }
                    idx--;
                }
            }
        }
    }
    
    return {change, goal};
}

int minStep = 11; string ans;
void solve(int step, string s = "") {
    if(step >= minStep)
        return;
    
    char temp[10][10];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            temp[i][j] = arr[i][j];
        }
    }
    
    for(int i = 0; i < 4; i++) {
        pair<bool, char> check; char c;
        switch(i) {
            case 0:
                check = left(); c = 'L'; break;
            case 1:
                check = right(); c = 'R'; break;
            case 2:
                check = up(); c = 'U'; break;
            case 3:
                check = down(); c = 'D';
        }
        
        if(check.second != 'X') {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < M; j++) {
                    arr[i][j] = temp[i][j];
                }
            }
            
            if(check.second == 'R') {
                if(minStep > step) {
                    ans = s+c; minStep = step;
                }
                
                break;
            }
        }
        else if(check.first) {
            solve(step+1, s+c);
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < M; j++) {
                    arr[i][j] = temp[i][j];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    solve(1);
    
    if(minStep <= 10) cout << minStep << '\n' << ans;
    else cout << -1;

    return 0;
}