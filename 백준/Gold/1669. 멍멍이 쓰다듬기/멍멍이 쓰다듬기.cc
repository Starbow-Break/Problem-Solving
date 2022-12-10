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

ll ub[(1<<17)|1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll X, Y; cin >> X >> Y;
    ll D = Y-X;
    
    ub[0] = 0;
    for(ll k = 1; k <= (1<<16); k++) {
        ub[2*k-1] = k*k; ub[2*k] = k*(k+1);
    }
    
    int ans;
    for(ans = 0; ans <= (1<<17); ans++) {
        if(D <= ub[ans]) break;
    }
    
    cout << ans;

    return 0;
}