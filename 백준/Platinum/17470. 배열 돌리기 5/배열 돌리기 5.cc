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

struct linear {
    int a1, a0;
    
    int getValue(int x){
        return a1*x+a0;
    }
    
    linear operator*(linear &l) {
        return {a1*l.a1, a1*l.a0+a0};
    }
};

int A[100][100], temp[100][100], B[2][2] = {{0, 1}, {2, 3}};
int R, C; linear arr[2] = {{1, 0}, {1, 0}};

void op1() {
    linear f = {-1, R/2-1};
    arr[0] = f*arr[0];
    
    swap(B[0][0], B[1][0]);
    swap(B[0][1], B[1][1]);
}

void op2() {
    linear f = {-1, C/2-1};
    arr[1] = f*arr[1];
    
    swap(B[0][0], B[0][1]);
    swap(B[1][0], B[1][1]);
}

void op3() {
    swap(arr[0], arr[1]);
    
    linear f = {-1, R/2-1};
    arr[1] = f*arr[1];
    
    swap(R, C);
    
    int temp = B[0][0];
    B[0][0] = B[1][0];
    B[1][0] = B[1][1];
    B[1][1] = B[0][1];
    B[0][1] = temp;
}

void op4() {
    swap(arr[0], arr[1]);
    
    linear f = {-1, C/2-1};
    arr[0] = f*arr[0];
    
    swap(R, C);
    
    int temp = B[0][0];
    B[0][0] = B[0][1];
    B[0][1] = B[1][1];
    B[1][1] = B[1][0];
    B[1][0] = temp;
}

void op5() {
    int temp = B[0][0];
    B[0][0] = B[1][0];
    B[1][0] = B[1][1];
    B[1][1] = B[0][1];
    B[0][1] = temp;
}

void op6() {
    int temp = B[0][0];
    B[0][0] = B[0][1];
    B[0][1] = B[1][1];
    B[1][1] = B[1][0];
    B[1][0] = temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, Q; cin >> N >> M >> Q;
    R = N; C = M;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) cin >> A[i][j];
    }
    
    int t = 0, s = 0;
    while(Q--) {
        int q; cin >> q;
        
        switch(q) {
            case 1: op1(); break; 
            case 2: op2(); break; 
            case 3: op3(); s++; break; 
            case 4: op4(); s++; break; 
            case 5: op5(); break; 
            case 6: op6();
        }
    }

    
    int ans[100][100]; s %= 2;
    
    for(int i = 0; i < 4; i++) {
        int j = B[i/2][i%2];
        for(int r = 0; r < N/2; r++) {
            for(int c = 0; c < M/2; c++) {
                if(s) ans[arr[0].getValue(c)+(R/2)*(i/2)][arr[1].getValue(r)+(C/2)*(i%2)]
                    = A[r+(N/2)*(j/2)][c+(M/2)*(j%2)];
                else ans[arr[0].getValue(r)+(R/2)*(i/2)][arr[1].getValue(c)+(C/2)*(i%2)]
                    = A[r+(N/2)*(j/2)][c+(M/2)*(j%2)];
            }
        }
    }
    
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            cout << ans[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}