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

int H[1001] = {0, }; int maxH = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int l, h; cin >> l >> h;
        H[l] = h; maxH = max(maxH, h);
    }
    
    int ans = 0; int i, j; int cur = 0;
    for(i = 1; i <= 1000; i++) {
        cur = max(cur, H[i]);
        if(cur == maxH) break;
        
        ans += cur;
    }
    
    cur = 0;
    for(j = 1001; j > 2; j--) {
        cur = max(cur, H[j-1]);
        if(cur == maxH) break;
        
        ans += cur;
    }
    
    ans += maxH*(j-i);
    
    cout << ans;

    return 0;
}