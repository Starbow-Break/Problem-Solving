#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    vector<ii> info;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(T--) {
        int ans = 0;
        info.clear();
        while(!pq.empty()) { pq.pop(); }
        
        int N, M; cin >> N >> M;
        while(M--) {
            int l, r; cin >> l >> r;
            info.push_back({l, r});
        }
        
        sort(info.begin(), info.end());
        
        int idx = 0;
        for(int i = 1; i <= N; i++) {
            while(idx < info.size() && info[idx].first == i) {
                pq.push(info[idx].second); idx++;
            }
            
            while(!pq.empty() && pq.top() < i) { pq.pop(); }
            if(!pq.empty()) { pq.pop(); ans++; }
        }
        
        cout << ans << '\n';
    }

    return 0;
}