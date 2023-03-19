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
#define MAX_N 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll dp[MAX_N+1];
ll sum[MAX_N+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    
    dp[0] = 0; sum[0] = 0;
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        sum[i] = sum[i-1]+v;
    }
    
    deque<pll> dq;
    
    for(int i = 1; i <= K; i++) {
        ll value = dp[i-1]-sum[i];
        while(!dq.empty() && dq.back().first <= value)
            dq.pop_back();
        dq.push_back({value, i});
        
        dp[i] = sum[i];
    }
    
    for(int i = K+1; i <= N; i++) {
        while(!dq.empty() && dq.front().second < i-K)
            dq.pop_front();
        
        ll value = dp[i-1]-sum[i];
        while(!dq.empty() && dq.back().first <= value)
            dq.pop_back();
        dq.push_back({value, i});
        
        dp[i] = sum[i]+dq.front().first;
    }
    
    cout << dp[N];

    return 0;
}