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

int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0] = 0; dp[1] = 0; dp[2] = 1; dp[3] = 1;
    
    int N; cin >> N;
    
    bool check[2000];
    for(int i = 4; i <= N; i++) {
        fill(check, check+2000, false);
        
        for(int j = 0; j <= (i-2)/2; j++) {
            check[dp[j] ^ dp[i-2-j]] = true;
        }
        
        for(int j = 0; j < 2000; j++) {
            if(!check[j]) {dp[i] = j; break;}
        }
    }
    
    cout << (dp[N] ? 1 : 2);

    return 0;
}