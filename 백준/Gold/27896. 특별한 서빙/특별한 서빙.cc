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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    priority_queue<int, vector<int>, less<int>> pq;
    
    int dissatis = 0, ans = 0;
    while(N--) {
        int v; cin >> v; pq.push(v); dissatis += v;
        while(dissatis >= M) {
            ans++; dissatis -= 2*pq.top(); pq.pop();
        }
    }
    
    cout << ans;

    return 0;
}