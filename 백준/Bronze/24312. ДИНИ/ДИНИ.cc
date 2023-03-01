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
    
    int arr[4]; int tot = 0;
    for(int i = 0; i < 4; i++) { cin >> arr[i]; tot += arr[i]; }
    
    int ans = tot;
    
    for(int state = 0; state < 16; state++) {
        int cur = 0;
        for(int i = 0; i < 4; i++) {
            if(state&(1<<i)) cur += arr[i];
        }
        
        ans = min(ans, abs(2*cur-tot));
    }
    
    cout << ans;

    return 0;
}