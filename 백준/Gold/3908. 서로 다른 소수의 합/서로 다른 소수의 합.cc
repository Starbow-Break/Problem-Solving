#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int dp[1121][188][15] = {0, };
vector<int> prime;

bool isPrime[1121];
void getPrime() {
    fill(isPrime+2, isPrime+1121, true);
    for(int i = 4; i <= 1120; i += 2) { isPrime[i] = false; }
    for(int i = 3; i <= 1120; i += 2) {
        for(int j = i*2; j <= 1120; j += i) {
            isPrime[j] = false;
        }
    }
    
    for(int i = 2; i <= 1120; i++) { if(isPrime[i]) prime.push_back(i); }
}

void init() {
    getPrime();
    
    for(int i = 0; i <= 187; i++) { dp[0][i][0] = 1; }
    
    for(int l = 1; l <= 187; l++) {
        for(int k = 1; k <= min(l, 14); k++) {
            for(int n = 2; n <= 1120; n++) {
                dp[n][l][k] += dp[n][l-1][k];
                if(n >= prime[l-1]) dp[n][l][k] += dp[n-prime[l-1]][l-1][k-1];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    init();
    
    int T; cin >> T;
    while(T--) {
        ll ans = 0;
        int n, k; cin >> n >> k;
        cout << dp[n][187][k] << '\n';
    }

    return 0;
}