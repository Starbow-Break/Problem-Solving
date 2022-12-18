#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <list>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

vector<int> edge[300001];
int minLen[300001] = {0, };

void bfs(int start) {
    queue<pii> q; q.push({start, 0});
    
    while(!q.empty()) {
        int cur = q.front().first; int d = q.front().second; q.pop();
        
        for(auto &next: edge[cur]) {
            if(next != 1 && minLen[next] == 0) {
                q.push({next, d+1});
                minLen[next] = d+1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    
    while(M--) {
        int s, f; cin >> s >> f;
        edge[s].push_back(f);
    }
    
    bfs(X);
    
    vector<int> ans;
    for(int i = 1; i <= N; i++) {
        if(minLen[i] == K) ans.push_back(i);
    }
    
    if(ans.empty()) { cout << -1; }
    else {
        for(auto &a: ans) { cout << a << '\n'; }
    }
    
    return 0;
}