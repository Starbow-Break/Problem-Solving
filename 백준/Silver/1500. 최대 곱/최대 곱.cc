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
    
    int S, K; cin >> S >> K;
    int q = S/K; int r = S%K;
    
    ll ans = 1;
    for(int i = 0; i < K; i++) {
        ans *= q+(i < r);
    }
    
    cout << ans;

    return 0;
}