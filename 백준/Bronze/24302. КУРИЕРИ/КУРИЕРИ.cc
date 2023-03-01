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

int solve(int n) {
    int a = 0, b = 0;
    
    n /= 1000;
    if(n <= 5) a = 400;
    else if(n <= 10) a = 700;
    else if(n <= 20) a = 1200;
    else if(n <= 30) a = 1700;
    else a = n*57;
    
    if(n <= 2) b = 90+n*90;
    else if(n <= 5) b = 100+n*85;
    else if(n <= 20) b = 125+n*80;
    else if(n <= 40) b = 325+n*70;
    else b = 925+n*55;
    
    return min(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;

    int ans = solve(n)+solve(m);
    
    cout << ans/100 << '.';
    cout.width(2); cout.fill('0');
    cout << ans%100;

    return 0;
}