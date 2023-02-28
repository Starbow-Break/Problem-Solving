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
    
    int N; cin >> N;
    ll ans = 0; int cur; cin >> cur; N--;
    
    while(N--) {
        int v; cin >> v;
        ans += 1LL*(v-cur)*(v-cur);
        cur = v;
    }
    
    cout << ans;
    
    return 0;
}