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
    
    int N, K; cin >> N >> K;
    int height[300000];
    
    for(int i = 0; i < N; i++) {
        cin >> height[i];
    }
    
    sort(height, height+N);
    
    int ans = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    for(int i = 1; i < N; i++) { ans += height[i]-height[i-1]; pq.push(height[i]-height[i-1]); }
    
    K--;
    while(K--) {
        ans -= pq.top(); pq.pop();
    }
    
    cout << ans;

    return 0;
}