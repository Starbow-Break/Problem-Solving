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
#define MOD 1'000'003

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll A[50][50]={0, }; //변형된 그래프의 인접 행렬
ll ans[50][50] = {0, };

void solve(int T) {
    ll w[50][50];
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) w[i][j] = A[i][j];
    }
    
    while(T > 0) {
        if(T%2) {
            ll temp[50][50] = {0, };
            
            for(int i = 0; i < 50; i++) {
                for(int j = 0; j < 50; j++) {
                    for(int k = 0; k < 50; k++) {
                        temp[i][j] += ans[i][k]*w[k][j];
                        temp[i][j] %= MOD;
                    }
                }
            }
            
            for(int i = 0; i < 50; i++) {
                for(int j = 0; j < 50; j++) {
                    ans[i][j] = temp[i][j];
                }
            }
        }
        
        T /= 2;
        
        ll temp[50][50] = {0, };
        
        for(int i = 0; i < 50; i++) {
            for(int j = 0; j < 50; j++) {
                for(int k = 0; k < 50; k++) {
                    temp[i][j] += w[i][k]*w[k][j];
                    temp[i][j] %= MOD;
                }
            }
        }
            
        for(int i = 0; i < 50; i++) {
            for(int j = 0; j < 50; j++) {
                w[i][j] = temp[i][j];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, S, E, T; cin >> N >> S >> E >> T;
    
    char arr[10][11];
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    //---------주어진 그래프를 변형---------
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 4; j++) A[5*i+j][5*i+j+1] = 1;
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            int w = arr[r][c]-'0';
            
            if(w > 0) A[5*r+w-1][5*c] = 1;
        }
    }
    //--------------------------------------
    
    for(int i = 0; i < 5*N; i++) ans[i][i] = 1;
    
    solve(T);
    
    cout << ans[5*(S-1)][5*(E-1)];
    
    return 0;
}