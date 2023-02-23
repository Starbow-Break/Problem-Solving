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

const double golden = (sqrt(5)+1)/2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        double a, b; cin >> a >> b;
        double d = abs(a/b-golden);
        
        if(d <= golden*0.01) cout << "golden";
        else cout << "not";
        
        cout << '\n';
    }
    
    return 0;
}