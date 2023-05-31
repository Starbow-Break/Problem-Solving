#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int INF = 1'000'000'000;

int dp[3][101][101][101];

int N;
vector<int> A, B, C;

//a->b
int move(int a, int b) {
    return min((N+a-b)%N, (N+b-a)%N);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    A.push_back(1); B.push_back(N/3+1); C.push_back(N/3*2+1);
    
    int a, b, c;
    cin >> a;
    for(int i = 1; i <= a; i++) {
        int v; cin >> v;
        A.push_back(v);
    }
    cin >> b;
    for(int i = 1; i <= b; i++) {
        int v; cin >> v;
        B.push_back(v);
    }
    cin >> c;
    for(int i = 1; i <= c; i++) {
        int v; cin >> v;
        C.push_back(v);
    }
    
    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            for(int k = 0; k <= c; k++) {
                dp[0][i][j][k] = INF;
                dp[1][i][j][k] = INF;
                dp[2][i][j][k] = INF;
            }
        }
    }
    dp[0][0][0][0] = 0; dp[1][0][0][0] = 0; dp[2][0][0][0] = 0;
    
    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            for(int k = 0; k <= c; k++) {
                if(i > 0) {
                    dp[0][i][j][k] = min(dp[0][i][j][k], dp[0][i-1][j][k]+move(A[i-1], A[i]));
                    dp[0][i][j][k] = min(dp[0][i][j][k], dp[1][i-1][j][k]+move((B[j]-1+N/3*2)%N+1, A[i]));
                    dp[0][i][j][k] = min(dp[0][i][j][k], dp[2][i-1][j][k]+move((C[k]-1+N/3)%N+1, A[i]));
                }
                if(j > 0) {
                    dp[1][i][j][k] = min(dp[1][i][j][k], dp[0][i][j-1][k]+move((A[i]-1+N/3)%N+1, B[j]));
                    dp[1][i][j][k] = min(dp[1][i][j][k], dp[1][i][j-1][k]+move(B[j-1], B[j]));
                    dp[1][i][j][k] = min(dp[1][i][j][k], dp[2][i][j-1][k]+move((C[k]-1+N/3*2)%N+1, B[j]));
                }
                if(k > 0) {
                    dp[2][i][j][k] = min(dp[2][i][j][k], dp[0][i][j][k-1]+move((A[i]-1+N/3*2)%N+1, C[k]));
                    dp[2][i][j][k] = min(dp[2][i][j][k], dp[1][i][j][k-1]+move((B[j]-1+N/3)%N+1, C[k]));
                    dp[2][i][j][k] = min(dp[2][i][j][k], dp[2][i][j][k-1]+move(C[k-1], C[k]));
                }
            }
        }
    }
    
    cout << min({dp[0][a][b][c], dp[1][a][b][c], dp[2][a][b][c]});

    return 0;
}