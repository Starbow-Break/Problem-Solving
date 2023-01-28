#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX 1000000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> dd;

ll arr[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    
    ll maxV = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        maxV = max(maxV, arr[i]);
    }
    
    for(int i = 1; i <= n; i++) { arr[i] = maxV-arr[i]; }
    
    int cur = 0; ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(cur < arr[i]) ans += (arr[i]-cur);
        
        cur = arr[i];
    }
    
    cout << ans;

    return 0;
}