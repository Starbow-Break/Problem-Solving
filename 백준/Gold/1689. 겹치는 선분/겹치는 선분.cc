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

struct sweepNode {
    int pos; bool isAdd;
    
    bool operator<(sweepNode &sn) {
        return pos < sn.pos;
    }
};

vector<sweepNode> nodeVec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int s, e; cin >> s >> e;
        nodeVec.push_back({s, 1});
        nodeVec.push_back({e, 0});
    }
    
    sort(nodeVec.begin(), nodeVec.end());
    
    int idx = 0;
    int ans = 0; int cur = 0;
    while(idx < nodeVec.size()) {
        int t = nodeVec[idx].pos;
        while(idx < nodeVec.size() && nodeVec[idx].pos == t) {
            if(nodeVec[idx].isAdd) cur++;
            else cur--;
            
            idx++;
        }
        
        ans = max(ans, cur);
    }
    
    cout << ans;

    return 0;
}