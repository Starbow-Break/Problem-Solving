#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int m[100001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T[100001], V[100001];
    int N, D; cin >> N >> D;
    for(int i = 1; i <= N; i++) cin >> T[i];
    for(int i = 1; i <= N; i++) cin >> V[i];
    
    m[N] = N; m[1] = 1;
    for(int i = 1; i <= min(N, D+1); i++) {
        if(1LL*(m[1]-1)*T[m[1]] < 1LL*(i-1)*T[i]) m[1] = i;
    }
    
    queue<pii> q; q.push({1, N});
    while(!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        
        int mid = (i+j)/2; 
        if(m[mid]) continue;
        
        m[mid] = mid;
        
        for(int k = max(m[i], mid); k <= min(m[j], mid+D); k++) {
            if(1LL*(m[mid]-mid)*T[m[mid]] < 1LL*(k-mid)*T[k]) m[mid] = k;
        }
        
        q.push({i, mid}); q.push({mid, j});
    }
    
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        ans = max(ans, V[i]+1LL*T[m[i]]*(m[i]-i));
    }
    
    cout << ans;

    return 0;
}