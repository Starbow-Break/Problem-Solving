#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M, R;
int A[300][300];

void rotateOnce(int r1, int r2, int c1, int c2) {
    int temp = A[r1][c1];
    for(int c = c1+1; c <= c2; c++) A[r1][c-1] = A[r1][c];
    for(int r = r1+1; r <= r2; r++) A[r-1][c2] = A[r][c2];
    for(int c = c2-1; c >= c1; c--) A[r2][c+1] = A[r2][c];
    for(int r = r2-1; r > r1; r--) A[r+1][c1] = A[r][c1];
    A[r1+1][c1] = temp;
}

void rotate(int r1, int r2, int c1, int c2, int R) {
    if(r1 > r2 || c1 > c2) return;
    
    int r = R%(((r2-r1)+(c2-c1))*2);
    while(r--) {
        rotateOnce(r1, r2, c1, c2);
    }
    
    rotate(r1+1, r2-1, c1+1, c2-1, R);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> R;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) { cin >> A[i][j]; }
    }
    
    rotate(0, N-1, 0, M-1, R);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) { cout << A[i][j] << " "; }
        cout << '\n';
    }

    return 0;
}