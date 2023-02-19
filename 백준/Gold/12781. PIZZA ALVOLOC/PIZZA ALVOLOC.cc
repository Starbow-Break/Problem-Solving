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

pii arr[4];

int ccw(pii a, pii b) {
    return a.first*b.second-a.second*b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i < 4; i++) {
        int x, y; cin >> x >> y;
        arr[i] = {x, y};
    }
    
    int c0 = ccw({arr[2].first-arr[0].first, arr[2].second-arr[0].second}, 
        {arr[3].first-arr[0].first, arr[3].second-arr[0].second});
    int c1 = ccw({arr[2].first-arr[1].first, arr[2].second-arr[1].second}, 
        {arr[3].first-arr[1].first, arr[3].second-arr[1].second});
    int c2 = ccw({arr[0].first-arr[2].first, arr[0].second-arr[2].second}, 
        {arr[1].first-arr[2].first, arr[1].second-arr[2].second});
    int c3 = ccw({arr[0].first-arr[3].first, arr[0].second-arr[3].second}, 
        {arr[1].first-arr[3].first, arr[1].second-arr[3].second});
        
    c0 /= abs(c0); c1 /= abs(c1); c2 /= abs(c2); c3 /= abs(c3);
    
    cout << (c0*c1 < 0 && c2*c3 < 0);

    return 0;
}