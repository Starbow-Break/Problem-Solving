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

// 테트로미노
struct tetromino {
    char type; //테트로미노 타입
    int row, col; //확인해야하는 행/열 수
    int block[4]; // 블록 (비트로 관리)
};

vector<tetromino> tetrominos; // 모든 테트로미노를 모아놓은 vector

// 테트로미노 생성
void generateTetromino() {
    // I
    tetrominos.pb({'I', 4, 1, {1, 1, 1, 1}});
    tetrominos.pb({'I', 1, 4, {15, 0, 0, 0}});
    
    // J
    tetrominos.pb({'J', 3, 2, {2, 2, 3, 0}});
    tetrominos.pb({'J', 2, 3, {1, 7, 0, 0}});
    tetrominos.pb({'J', 3, 2, {3, 1, 1, 0}});
    tetrominos.pb({'J', 2, 3, {7, 4, 0, 0}});
    
    // L
    tetrominos.pb({'L', 3, 2, {1, 1, 3, 0}});
    tetrominos.pb({'L', 2, 3, {7, 1, 0, 0}});
    tetrominos.pb({'L', 3, 2, {3, 2, 2, 0}});
    tetrominos.pb({'L', 2, 3, {4, 7, 0, 0}});
    
    // O
    tetrominos.pb({'O', 2, 2, {3, 3, 0, 0}});
    
    // S
    tetrominos.pb({'S', 2, 3, {6, 3, 0, 0}}); 
    tetrominos.pb({'S', 3, 2, {1, 3, 2, 0}});
    
    // T
    tetrominos.pb({'T', 2, 3, {7, 2, 0, 0}});
    tetrominos.pb({'T', 3, 2, {2, 3, 2, 0}});
    tetrominos.pb({'T', 2, 3, {2, 7, 0, 0}});
    tetrominos.pb({'T', 3, 2, {1, 3, 1, 0}});
    
    // Z
    tetrominos.pb({'Z', 2, 3, {3, 6, 0, 0}});
    tetrominos.pb({'Z', 3, 2, {2, 3, 1, 0}});
}

int H, W;
int init[100000], target[100000]; // 초기 상태, 목표 상태 (비트로 관리)
// check[line][d] == t => init[(t-d)~line] == target[t~(line+d)]
//                     => 처음부터 일치하지 않으면 line+d+1
int check[100000][5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    generateTetromino(); // 테트로미노 생성
    
    // input
    cin >> H >> W;
    for(int r = 0; r < H; r++) {
        string s; cin >> s;
        for(int c = 0; c < W; c++) {
            init[r] += (s[c] == '#')*(1 << c);
        }
    }
    for(int r = 0; r < H; r++) {
        string s; cin >> s;
        for(int c = 0; c < W; c++) {
            target[r] += (s[c] == '#')*(1 << c);
        }
    }
    
    // 실행 시간 단축을 위해 필요한 정보 얻기
    for(int r = 0; r < H; r++) {
        for(int d = 0; d <= min((H-1)-r, 4); d++) {
            if(init[r] == target[r+d]) {
                if(r == 0) check[r][d] = d;
                else check[r][d] = check[r-1][d];
            }
            else check[r][d] = r+d+1;
        }
    }
    
    // 브루트포스 ON
    bool checkBlock[26] = {false, };
    for(auto &t: tetrominos) {
        if(checkBlock[t.type-'A']) continue;
        
        // 브루트포오오오오오오오오오오오오오오오오오스
        int br = t.row, bc = t.col; int *block = t.block;
        bool checkSuccess = false;
        for(int r = 0; r <= H-br; r++) {
            for(int c = 0; c <= W-bc; c++) {
                // 해당 위치에 블록을 놓을 수 있는지 확인
                bool checkPut = true;
                for(int i = 0; i < br && checkPut; i++) {
                    if(init[r+i] & (block[i] << c)) {
                        checkPut = false;
                    }
                }
                if(!checkPut) continue;
                
                int checkRow[4] = {-1, -1, -1, -1};
                for(int i = br-1; i >= 0; i--) {
                    for(int j = 0; j < bc; j++) {
                        if(block[i] & (1 << j)) {
                            if(checkRow[j] == -1) checkRow[j] = r+i+1;
                        }
                    }
                }

                checkPut = false;
                for(int i = 0; i < bc && !checkPut; i++) {
                    if(checkRow[i] >= H || (init[checkRow[i]] & (1 << (c+i))))
                        checkPut = true;
                }
                if(!checkPut) continue;
                
                //target이 만들어지는지 확인
                bool checkSuccess = true;
                int d = 0;
                if(check[H-1][d] > r+br) checkSuccess = false;
                for(int i = br-1; i >= 0; i--) {
                    int lineStatus = init[r+i] | (block[i] << c);
                    if(lineStatus == ((1 << W)-1)) d++;
                    else {
                        if(lineStatus != target[r+i+d]) {
                            checkSuccess = false;
                        }
                    }
                }
                if(check[r-1][d] > d) checkSuccess = false;
                for(int i = 0; i < d; i++) {
                    if(target[i]) checkSuccess = false;
                }
                
                if(checkSuccess) {
                    checkBlock[t.type-'A'] = true;
                    // cout << r << ' ' << c << '\n';
                    // for(auto b: t.block) cout << b << ' ';
                    // cout << '\n';
                }
            }
        }
    }
    
    // for(int r = 0; r < H; r++) {
    //     for(int d = 0; d <= 4; d++) {
    //         cout << check[r][d] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // 답 출력
    string blockTypes = "IJLOSTZ";
    string ans = "";
    
    for(auto &c: blockTypes) {
        if(checkBlock[c-'A']) ans += c;
    }
    
    cout << (ans == "" ? "X" : ans);    
    
    return 0;
}