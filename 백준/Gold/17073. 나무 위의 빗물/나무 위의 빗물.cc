#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, W;
vector<int> edge[500001];

bool visited[500001] = {false, };
int getLeafNum(int root = 1) {
    queue<int> q; q.push(root);
    visited[root] = true;
    
    int ret = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        bool isLeaf = true;
        
        for(auto &next: edge[cur]) {
            if(!visited[next]) {
                q.push(next); visited[next] = true;
                isLeaf = false;
            }
        }
        
        if(isLeaf) ret++;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> W;
    for(int i = 1; i < N; i++) {
        int s, f; cin >> s >> f;
        edge[s].push_back(f);
        edge[f].push_back(s);
    }
    
    cout << fixed; cout.precision(12);
    cout << (double)W/(double)getLeafNum();

    return 0;
}
