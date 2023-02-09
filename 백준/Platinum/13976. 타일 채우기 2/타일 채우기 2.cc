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
#define MOD 1'000'000'007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;


ll solve(ll N) {
    if(N%2) return 0;
    
    N /= 2; ll w[2][2] = {{4, MOD-1}, {1, 0}};
    ll A[2][2] = {{1, 0}, {0, 1}};
    while(N > 0) {
        if(N%2) {
            ll temp[2][2] = {0, };
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    for(int k = 0; k < 2; k++) {
                        temp[i][j] += A[i][k]*w[k][j];
                        temp[i][j] %= MOD;
                    }
                }
            }
            
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    A[i][j] = temp[i][j];
                }
            }
        }
        
        N /= 2;
        
        ll temp2[2][2] = {0, };
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    temp2[i][j] += w[i][k]*w[k][j];
                    temp2[i][j] %= MOD;
                }
            }
        }
        
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                w[i][j] = temp2[i][j];
            }
        }
    }
    
    return (A[1][0]*3+A[1][1])%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N; cin >> N;
    cout << solve(N);

    return 0;
}