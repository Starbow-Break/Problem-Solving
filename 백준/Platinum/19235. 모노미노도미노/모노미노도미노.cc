#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int cnt = 0; int score = 0;
int arr[10][10] = {0, };

void dropBlock(int t, int x, int y) {
    if(t == 1) {
        for(int r = 4; r < 10; r++) {
            if(r+1 >= 10 || arr[r+1][y] != 0) {
                arr[r][y] = cnt; break;
            }
        }
        
        for(int c = 4; c < 10; c++) {
            if(c+1 >= 10 || arr[x][c+1] != 0) {
                arr[x][c] = cnt; break;
            }
        }
    }
    else if(t == 2) {
        for(int r = 4; r < 10; r++) {
            if(r+1 >= 10 || arr[r+1][y] != 0 || arr[r+1][y+1] != 0) {
                arr[r][y] = cnt; arr[r][y+1] = cnt; break;
            }
        }
        
        for(int c = 4; c < 10; c++) {
            if(c+2 >= 10 || arr[x][c+2] != 0) {
                arr[x][c] = cnt; arr[x][c+1] = cnt; break;
            }
        }
    }
    else {
        for(int r = 4; r < 10; r++) {
            if(r+2 >= 10 || arr[r+2][y] != 0) {
                arr[r][y] = cnt; arr[r+1][y] = cnt; break;
            }
        }
        
        for(int c = 4; c < 10; c++) {
            if(c+1 >= 10 || arr[x][c+1] != 0 || arr[x+1][c+1] != 0) {
                arr[x][c] = cnt; arr[x+1][c] = cnt; break;
            }
        }
    }
}

void deleteRow(int r) {
    for(int j = 0; j < 4; j++) { arr[r][j] = 0;}
}

void deleteCol(int c) {
    for(int j = 0; j < 4; j++) { arr[j][c] = 0; }
}

void gravityGreen() {
    for(int r = 8; r >= 4; r--) {
        int idx = 0;
        while(idx < 4) {
            if(idx < 3 && arr[r][idx] > 0 && arr[r][idx] == arr[r][idx+1]) {
                if(arr[r+1][idx] == 0 && arr[r+1][idx+1] == 0) {
                    int t = r+1;
                    while(1) {
                        if(t+1 >= 10 || arr[t+1][idx] != 0 || arr[t+1][idx+1] != 0)
                            break;
                        t++;
                    }
                    arr[t][idx] = arr[r][idx];
                    arr[t][idx+1] = arr[r][idx];
                    arr[r][idx] = 0; arr[r][idx+1] = 0;
                }
                
                idx += 2;
            }
            else {
                if(arr[r][idx] > 0 && arr[r+1][idx] == 0) {
                    int t = r+1;
                    while(1) {
                        if(t+1 >= 10 || arr[t+1][idx] != 0) break;
                        t++;
                    }
                    arr[t][idx] = arr[r][idx]; arr[r][idx] = 0;
                }
                
                idx++;
            }
        }
    }
}

void gravityBlue() {
    for(int c = 8; c >= 4; c--) {
        int idx = 0;
        while(idx < 4) {
            if(idx < 3 && arr[idx][c] > 0 && arr[idx][c] == arr[idx+1][c]) {
                if(arr[idx][c+1] == 0 && arr[idx+1][c+1] == 0) {
                    int t = c+1;
                    while(1) {
                        if(t+1 >= 10 || arr[idx][t+1] != 0 || arr[idx+1][t+1] != 0)
                            break;
                        t++;
                    }
                    arr[idx][t] = arr[idx][c];
                    arr[idx+1][t] = arr[idx+1][c];
                    arr[idx][c] = 0; arr[idx+1][c] = 0;
                }
                
                idx += 2;
            }
            else {
                if(arr[idx][c] > 0 && arr[idx][c+1] == 0) {
                    int t = c+1;
                    while(1) {
                        if(t+1 >= 10 || arr[idx][t+1] != 0)
                            break;
                        t++;
                    }
                    arr[idx][t] = arr[idx][c]; arr[idx][c] = 0;
                }
                
                idx++;
            }
        }
    }
}

void getScore() {
    while(1) {
        bool flag = false;
        for(int r = 4; r < 10; r++) {
            bool hasLine = true;
            for(int j = 0; j < 4; j++) {
                if(!arr[r][j]) hasLine = false;
            }
            
            if(hasLine) {
                score++;
                deleteRow(r);
                flag = true;
            }
        }
        
        if(!flag) break;
        
        gravityGreen();
    }
    
    while(1) {
        bool flag = false;
        for(int c = 4; c < 10; c++) {
            bool hasLine = true;
            for(int j = 0; j < 4; j++) {
                if(!arr[j][c]) hasLine = false;
            }
            
            if(hasLine) {
                score++;
                deleteCol(c);
                flag = true;
            }
        }
        
        if(!flag) break;
            
        gravityBlue();
    }
}

void adjustBoard() {
    while(1) {
        bool flag = false;
        for(int r = 4; r <= 5; r++) {
            for(int c = 0; c < 4; c++) {
                if(arr[r][c]) flag = true;
            }
        }
        
        if(!flag) break;
        
        deleteRow(9);
        gravityGreen();
    }
    
    while(1) {
        bool flag = false;
        for(int c = 4; c <= 5; c++) {
            for(int r = 0; r < 4; r++) {
                if(arr[r][c]) flag = true;
            }
        }
        
        if(!flag) break;
        
        deleteCol(9);
        gravityBlue();
    }
}

int countBlock() {
    int ret = 0;
    
    for(int r = 6; r < 10; r++) {
        for(int c = 0; c < 4; c++) {
            ret += (arr[r][c] != 0);
        }
    }
    
    for(int r = 0; r < 4; r++) {
        for(int c = 6; c < 10; c++) {
            ret += (arr[r][c] != 0);
        }
    }
    
    return ret;
}

void progress(int t, int x, int y) {
    dropBlock(t, x, y); //보드에 블록 설치
    getScore(); //완성된 행 or 열 제거하면서 점수 획득
    adjustBoard(); //연한 녹색 or 연한 파란색에 블록이 있는 경우 보드 안에 있는 블록 조정
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        cnt++;
        int t, x, y; cin >> t >> x >> y;
        progress(t, x, y);
    }
    
    cout << score << '\n';
    cout << countBlock() << '\n';
    
    /*cout << "-------------------------------" << '\n';
    for(int r = 0; r < 10; r++) {
        if(r < 4) {
            for(int c = 0; c < 10; c++) cout << arr[r][c] << " ";
        }
        else {
            for(int c = 0; c < 4; c++) cout << arr[r][c] << " ";
        }
        cout << '\n';
    }*/

    return 0;
}