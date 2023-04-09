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

class Cube {
    private:
    char cube[6][3][3];
    
    //큐브의 지정된 면을 돌리기 (옆면은 제외)
    void rotateSurface(int surface, char d) {
        char temp[3][3];
        if(d == '+') {
            for(int r = 0; r < 3; r++) {
                for(int c = 0; c < 3; c++) {
                    temp[c][2-r] = cube[surface][r][c];
                }
            }
        }
        else {
            for(int r = 0; r < 3; r++) {
                for(int c = 0; c < 3; c++) {
                    temp[2-c][r] = cube[surface][r][c];
                }
            }
        }
        
        for(int r = 0; r < 3; r++) {
            for(int c = 0; c < 3; c++) {
                cube[surface][r][c] = temp[r][c];
            }
        }
    }
    
    //큐브의 지정된 면을 돌리기 (옆면만 돌아감)
    void rotateSide(int surface, char d) {
        int temp[4][3]; int w = (d == '+' ? 3 : 1);
        
        switch(surface) {
            case 0:
                for(int i = 0; i < 3; i++) temp[0][i] = cube[3][0][i];
                for(int i = 0; i < 3; i++) temp[1][i] = cube[2][0][i];
                for(int i = 0; i < 3; i++) temp[2][i] = cube[1][0][i];
                for(int i = 0; i < 3; i++) temp[3][i] = cube[4][0][i];
                
                for(int i = 0; i < 3; i++) cube[3][0][i] = temp[(0+d)%4][i];
                for(int i = 0; i < 3; i++) cube[2][0][i] = temp[(1+d)%4][i];
                for(int i = 0; i < 3; i++) cube[1][0][i] = temp[(2+d)%4][i];
                for(int i = 0; i < 3; i++) cube[4][0][i] = temp[(3+d)%4][i];
                break;
            case 1:
                for(int i = 0; i < 3; i++) temp[0][i] = cube[0][2][2-i];
                for(int i = 0; i < 3; i++) temp[1][i] = cube[2][2-i][0];
                for(int i = 0; i < 3; i++) temp[2][i] = cube[5][0][i];
                for(int i = 0; i < 3; i++) temp[3][i] = cube[4][i][2];
                
                for(int i = 0; i < 3; i++) cube[0][2][2-i] = temp[(0+d)%4][i];
                for(int i = 0; i < 3; i++) cube[2][2-i][0] = temp[(1+d)%4][i];
                for(int i = 0; i < 3; i++) cube[5][0][i] = temp[(2+d)%4][i];
                for(int i = 0; i < 3; i++) cube[4][i][2] = temp[(3+d)%4][i];
                break;
            case 2:
                for(int i = 0; i < 3; i++) temp[0][i] = cube[0][i][2];
                for(int i = 0; i < 3; i++) temp[1][i] = cube[3][2-i][0];
                for(int i = 0; i < 3; i++) temp[2][i] = cube[5][i][2];
                for(int i = 0; i < 3; i++) temp[3][i] = cube[1][i][2];
                
                for(int i = 0; i < 3; i++) cube[0][i][2] = temp[(0+d)%4][i];
                for(int i = 0; i < 3; i++) cube[3][2-i][0] = temp[(1+d)%4][i];
                for(int i = 0; i < 3; i++) cube[5][i][2] = temp[(2+d)%4][i];
                for(int i = 0; i < 3; i++) cube[1][i][2] = temp[(3+d)%4][i];
                break;
            case 3:
                for(int i = 0; i < 3; i++) temp[0][i] = cube[0][0][i];
                for(int i = 0; i < 3; i++) temp[1][i] = cube[4][2-i][0];
                for(int i = 0; i < 3; i++) temp[2][i] = cube[5][2][2-i];
                for(int i = 0; i < 3; i++) temp[3][i] = cube[2][i][2];
                
                for(int i = 0; i < 3; i++) cube[0][0][i] = temp[(0+d)%4][i];
                for(int i = 0; i < 3; i++) cube[4][2-i][0] = temp[(1+d)%4][i];
                for(int i = 0; i < 3; i++) cube[5][2][2-i] = temp[(2+d)%4][i];
                for(int i = 0; i < 3; i++) cube[2][i][2] = temp[(3+d)%4][i];
                break;
            case 4:
                for(int i = 0; i < 3; i++) temp[0][i] = cube[0][2-i][0];
                for(int i = 0; i < 3; i++) temp[1][i] = cube[1][2-i][0];
                for(int i = 0; i < 3; i++) temp[2][i] = cube[5][2-i][0];
                for(int i = 0; i < 3; i++) temp[3][i] = cube[3][i][2];
                
                for(int i = 0; i < 3; i++) cube[0][2-i][0] = temp[(0+d)%4][i];
                for(int i = 0; i < 3; i++) cube[1][2-i][0] = temp[(1+d)%4][i];
                for(int i = 0; i < 3; i++) cube[5][2-i][0] = temp[(2+d)%4][i];
                for(int i = 0; i < 3; i++) cube[3][i][2] = temp[(3+d)%4][i];
                break;
            case 5:
                for(int i = 0; i < 3; i++) temp[0][i] = cube[1][2][2-i];
                for(int i = 0; i < 3; i++) temp[1][i] = cube[2][2][2-i];
                for(int i = 0; i < 3; i++) temp[2][i] = cube[3][2][2-i];
                for(int i = 0; i < 3; i++) temp[3][i] = cube[4][2][2-i];
                
                for(int i = 0; i < 3; i++) cube[1][2][2-i] = temp[(0+d)%4][i];
                for(int i = 0; i < 3; i++) cube[2][2][2-i] = temp[(1+d)%4][i];
                for(int i = 0; i < 3; i++) cube[3][2][2-i] = temp[(2+d)%4][i];
                for(int i = 0; i < 3; i++) cube[4][2][2-i] = temp[(3+d)%4][i];
        }
    }
    
    public:
    Cube() {
        for(int i = 0; i < 6; i++) {
            char color;
            switch(i) {
                case 0: color = 'w'; break;
                case 1: color = 'r'; break;
                case 2: color = 'b'; break;
                case 3: color = 'o'; break;
                case 4: color = 'g'; break;
                case 5: color = 'y'; break;
            }
            
            for(int r = 0; r < 3; r++) {
                for(int c = 0; c < 3; c++) {
                    cube[i][r][c] = color;
                }
            }
        }
    }
    
    //큐브 돌리기
    void rotateCube(string command) {
        char sur, d; cin >> sur >> d;
        int surNum;
        
        switch(sur) {
            case 'U': surNum = 0; break;
            case 'F': surNum = 1; break;
            case 'R': surNum = 2; break;
            case 'B': surNum = 3; break;
            case 'L': surNum = 4; break;
            case 'D': surNum = 5; break;
        }
        
        rotateSurface(surNum, d);
        rotateSide(surNum, d);
    }
    
    //큐브의 윗면 출력
    void printTopSurface() {
        for(int r = 0; r < 3; r++) {
            for(int c = 0; c < 3; c++) {
                cout << cube[0][r][c];
            }
            cout << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        Cube cube = Cube();
        
        int n; cin >> n;
        while(n--) {
            string s;
            cube.rotateCube(s);
        }
        
        cube.printTopSurface();
    }

    return 0;
}