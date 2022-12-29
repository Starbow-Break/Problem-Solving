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

int N, R[500], C[500];
bool ans[500][500] = {false, };

struct cmp {
    bool operator()(pii &A, pii &B) {
        return A.second < B.second;
    }
};

bool solve() {
    priority_queue<pii, vector<pii>, cmp> pq;
    stack<pii> s;
    
    for(int i = 0; i < N; i++) { if(C[i]) pq.push({i, C[i]}); }
    
    for(int r = 0; r < N; r++) {
        if(R[r] > pq.size()) return false;
        
        while(R[r]--) {
            ans[r][pq.top().first] = true;
            s.push(pq.top()); pq.pop();
        }
        
        while(!s.empty()) {
            pii cur = s.top(); s.pop();
            cur.second--;
            if(cur.second > 0) pq.push(cur);
        }
    }
    
    return pq.empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) { cin >> R[i]; }
    for(int i = 0; i < N; i++) { cin >> C[i]; }
    
    if(solve()) {
        cout << 1 << '\n';
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
    else cout << -1;

    return 0;
}