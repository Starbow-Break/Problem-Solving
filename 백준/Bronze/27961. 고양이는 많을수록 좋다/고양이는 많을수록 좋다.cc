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
    
    ll N; cin >> N;
    int ans = 0;
    
    if(N > 0) {
        ll M = 1; ans++;
        while(M < N) {
            M *= 2; ans++;
        }
    }
    
    cout << ans;

    return 0;
}