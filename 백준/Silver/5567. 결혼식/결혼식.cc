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

vector<int> edge[501];
int step[501] = {0, };

int solve(int start) {
    queue<pii> q; q.push({start, 0});
    int ret = -1;
    
    while(!q.empty()) {
        int cur = q.front().first; int d = q.front().second; q.pop();
        ret++;
        
        if(d < 2) {
            for(auto &next: edge[cur]) {
                if(next != 1 && step[next] == 0) {
                    q.push({next, d+1});
                    step[next] = d+1;
                }
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    while(M--) {
        int s, f; cin >> s >> f;
        edge[s].push_back(f);
        edge[f].push_back(s);
    }
    
    cout << solve(1);
    
    return 0;
}