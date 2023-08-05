#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end();
#define rall(vec) vec.rbegin(), vec.rend();
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using int128 = __int128_t;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int domino[36][2] = {
    {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {1, 8}, {1, 9},
    {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {2, 8}, {2, 9}, {3, 4}, 
    {3, 5}, {3, 6}, {3, 7}, {3, 8}, {3, 9}, {4, 5}, {4, 6}, {4, 7}, 
    {4, 8}, {4, 9}, {5, 6}, {5, 7}, {5, 8}, {5, 9}, {6, 7}, {6, 8}, 
    {6, 9}, {7, 8}, {7, 9}, {8, 9}
};
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int sudoku[9][9] = {0, };
bool used[10][10] = {false, };

bool checkRow[9][10] = {false, };
bool checkCol[9][10] = {false, };
bool checkBox[9][10] = {false, };

void init() {
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            sudoku[r][c] = 0;
            used[r+1][c+1] = false;
            checkRow[r][c+1] = false;
            checkCol[r][c+1] = false;
            checkBox[r][c+1] = false;
        }
    }
}

void printSudoku(int num){
    cout << "Puzzle " << num << '\n';
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            cout << sudoku[r][c];
        }
        cout << '\n';
    }
}

bool solve(int idx = 0) {
    //cout << idx << '\n';
    if(idx == 36) return true;
    if(used[domino[idx][0]][domino[idx][1]]) return solve(idx+1);
    
    int a = domino[idx][0];
    int b = domino[idx][1];
    for(int r = 0; r < 9; r++) {
        if(checkRow[r][a]) continue; //행에 a가 있으면 스킵
        for(int c = 0; c < 9; c++) {
            if(checkCol[c][a]) continue; //열에 a가 있으면 스킵
            if(checkBox[r/3*3+c/3][a]) continue; //박스에 a가 있으면 스킵
            if(sudoku[r][c]) continue; //이미 채워진 수가 있으면 스킵
            for(int k = 0; k < 4; k++) {
                int rr = r+dr[k];
                int cc = c+dc[k];
                if(0 > rr || rr >= 9 || 0 > cc || cc >= 9) //격자를 넘어가면 스킵
                    continue;
                if(checkRow[rr][b] || checkCol[cc][b] || checkBox[rr/3*3+cc/3][b])
                    continue;
                if(sudoku[rr][cc]) continue;
                
                sudoku[r][c] = a;
                sudoku[rr][cc] = b;
                checkRow[r][a] = true;
                checkCol[c][a] = true;
                checkBox[r/3*3+c/3][a] = true;
                checkRow[rr][b] = true;
                checkCol[cc][b] = true;
                checkBox[rr/3*3+cc/3][b] = true;
                if(solve(idx+1)) return true;
                sudoku[r][c] = 0;
                sudoku[rr][cc] = 0;
                checkRow[r][a] = false;
                checkCol[c][a] = false;
                checkBox[r/3*3+c/3][a] = false;
                checkRow[rr][b] = false;
                checkCol[cc][b] = false;
                checkBox[rr/3*3+cc/3][b] = false;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int num = 0;
    while(1) {
        num++;
        int N; cin >> N;
        if(!N) break;
        
        init();
        
        while(N--) {
            int a, b;
            string s, t;
            cin >> a >> s >> b >> t;
            sudoku[s[0]-'A'][s[1]-'1'] = a;
            sudoku[t[0]-'A'][t[1]-'1'] = b;
            used[a][b] = true;
            used[b][a] = true;
        }
        for(int i = 1; i <= 9; i++) {
            string s; cin >> s;
            sudoku[s[0]-'A'][s[1]-'1'] = i;
        }
        
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(sudoku[r][c]) {
                    checkRow[r][sudoku[r][c]] = true;
                    checkCol[c][sudoku[r][c]] = true;
                    checkBox[r/3*3+c/3][sudoku[r][c]] = true;
                }
            }
        }
        
        solve();
        
        printSudoku(num);
    }

    return 0;
}