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

int dp[50] = {0, };
vector<int> edge[50];

void dfs(int start = 0) {
    vector<int> vec;
    
    for(auto &child: edge[start]) {
        dfs(child);
        vec.push_back(dp[child]);
    }
    
    if(vec.empty()) { dp[start] = 0; }
    else {
        sort(vec.rbegin(), vec.rend());
        
        int w = 1;
        for(auto &v: vec) {
            dp[start] = max(dp[start], v+w);
            w++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        if(v != -1) {
            edge[v].push_back(i);
        }
    }
    
    dfs();
    
    cout << dp[0];

    return 0;
}