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
    
    ll k, a, x, b, y; cin >> k >> a >> x >> b >> y;
    cout << max(0LL, min((k-a)*x+(k-(a+b))*y, (k-b)*y+(k-(a+b))*x));

    return 0;
}
