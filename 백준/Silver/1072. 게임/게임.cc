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
    
    ll X, Y, Z; cin >> X >> Y;
    Z = (Y*100)/X;
    
    ll A = X*(Z+1)-100*Y;
    ll B = 99-Z;
    
    cout << ((B > 0) ? A/B+(A%B != 0) : -1);

    return 0;
}