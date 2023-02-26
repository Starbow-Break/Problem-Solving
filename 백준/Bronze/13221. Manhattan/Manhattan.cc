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
    
    int x, y; cin >> x >> y;
    int xx, yy; int l = 1000000000;
    int T; cin >> T;
    while(T--) {
        int _x, _y; cin >> _x >> _y;
        if(l > abs(_x-x)+abs(_y-y)) {
            l = abs(_x-x)+abs(_y-y);
            xx = _x; yy = _y;
        }
    }
    
    cout << xx << " " << yy;
    
    return 0;
}