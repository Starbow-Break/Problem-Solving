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
    
    int l, w, a;
    while(cin >> l >> w >> a) {
        if(!l && !w && !a) break;
        
        if(l == 0) l = a/w;
        if(w == 0) w = a/l;
        if(a == 0) a = w*l;
        
        cout << l << " " << w << " " << a << '\n';
    }

    return 0;
}