#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX 1000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M;
int ans[MAX+1];
vector<int> edge[MAX+1];
int inDegree[MAX+1] = {0, };

void solve() {
    queue<ii> q;
    
    for(int i = 1; i <= N; i++) {
        if(!inDegree[i]) q.push({i, 1});
    }
    
    while(!q.empty()) {
        int cur = q.front().first;
        ans[cur] = q.front().second; q.pop();
        
        for(auto &next: edge[cur]) {
            inDegree[next]--;
            if(!inDegree[next]) q.push({next, ans[cur]+1});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        edge[a].push_back(b);
        inDegree[b]++;
    }
    
    solve();
    
    for(int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}