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

int N, M; ll K;
bool arr[200] = {0, };
ll dp[201][201] = {0, };

ll combination(int n, int m) {
    if(dp[n][m] != 0) return dp[n][m];
    
    if(m == 0 || n == m) { dp[n][m] = 1; return 1; }
    
    dp[n][m] = combination(n-1, m)+combination(n-1, m-1);
    return dp[n][m];
}

bool solve(int N, int M) {
    int remain = M; K--;
    while(remain) {
        ll cur = 0; int idx = remain-1;
        while(1) {
            if(idx >= N+M) return false;
            
            ll d = combination(idx, remain-1);
            
            if(K <= cur+d-1) {
                arr[idx] = 1; K -= cur;
                break;
            }
            
            cur += d; idx++;
        }
        remain--;
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    if(solve(N, M)) {
        for(int i = M+N-1; i >= 0; i--) { cout << (arr[i] ? 'z' : 'a'); }
    }
    else cout << -1;

    return 0;
}