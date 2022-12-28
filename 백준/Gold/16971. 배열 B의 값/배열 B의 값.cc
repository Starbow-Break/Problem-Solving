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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, M;
int A[1001][1001]; int valB = 0;
int R[1001] = {0, };
int C[1001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> A[i][j];
            valB += A[i][j]*((i == 1 || i == N) ? 1 : 2)*((j == 1 || j == M) ? 1 : 2);
        }
    }
    
    for(int i = 1; i <= N; i++) {
        int cur = 0;
        for(int j = 1; j <= M; j++) {
            if(j == 1 || j == M) cur += A[i][j];
            else cur += 2*A[i][j];
        }
        R[i] = cur;
    }
    
    
    for(int j = 1; j <= M; j++) {
        int cur = 0;
        for(int i = 1; i <= N; i++) {
            if(i == 1 || i == N) cur += A[i][j];
            else cur += 2*A[i][j];
        }
        C[j] = cur;
    }
    
    int delta = 0;
    for(int r = 2; r <= N-1; r++) {
        delta = max(delta, R[1]-R[r]);
        delta = max(delta, R[N]-R[r]);
    }
    for(int c = 2; c <= M-1; c++) {
        delta = max(delta, C[1]-C[c]);
        delta = max(delta, C[M]-C[c]);
    }

    cout << valB+delta;

    return 0;
}