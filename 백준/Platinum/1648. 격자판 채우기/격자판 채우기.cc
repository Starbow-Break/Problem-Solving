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
#define MOD 9901;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

vector<int> states;
int dp[15][1<<14] = {0, };

bool check(int s) {
    int cnt = 0;
    for(int j = 13; j >= 0; j--) {
        if(s & (1<<j)) cnt++;
        else {
            if(cnt%2) return false;
            cnt = 0;
        }
    }
    
    return !(cnt%2);
}

void initStates(int N) {
    for(int s = 0; s < (1<<N); s++) {
        if(check(s)) states.push_back(s);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    initStates(N);
    
    for(auto &s: states) dp[1][s] = 1;
    
    for(int i = 2; i <= M; i++) {
        for(int s = 0; s < (1<<N); s++) {
            for(auto &st: states) {
                if(!(st & s)) {
                    dp[i][st+s] += dp[i-1][(1<<N)-s-1];
                    dp[i][st+s] %= MOD;
                }
            }
        }
    }
    
    cout << dp[M][(1<<N)-1];

    return 0;
}