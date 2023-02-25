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

ll solve(int n, int m) {
    return 1LL*(n+m)*(m-n+1)/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cout << "Scenario #" << tc << ":" << '\n';
        
        int n, m; cin >> n >> m;
        cout << solve(n, m) << '\n' << '\n';
    }

    return 0;
}