#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

vector<int> cow;
vector<ii> chicken;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int C, N; cin >> C >> N;
    while(C--) {
        int t; cin >> t;
        cow.push_back(t);
    }
    while(N--) {
        int a, b; cin >> a >> b;
        chicken.push_back({a, b});
    }
    
    sort(cow.begin(), cow.end());
    sort(chicken.begin(), chicken.end());
    
    int idx = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for(auto &t: cow) {
        while(idx < chicken.size() && chicken[idx].first <= t) {
            pq.push(chicken[idx].second); idx++;
        }
        
        while(!pq.empty() && pq.top() < t) pq.pop();
        
        if(!pq.empty()) { ans++; pq.pop(); }
    }
    
    cout << ans;
    
    return 0;
}