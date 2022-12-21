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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    if(N == 1) { cout << 0; }
    else {
        priority_queue<int, vector<int>, less<int>> pq;
        
        int dasom; cin >> dasom;
        for(int i = 2; i <= N; i++) {
            int v; cin >> v;
            pq.push(v);
        }
        
        int ans = 0;
        while(dasom <= pq.top()) {
            int t = pq.top(); pq.pop();
            dasom++; ans++; t--; pq.push(t);
        }
        
        cout << ans;
    }

    return 0;
}