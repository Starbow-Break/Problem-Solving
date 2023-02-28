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

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(b == 1) return 1;
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int r = 0, g = 0, b = 0;
        
        for(int i = 0; i < 10; i++) {
            int rr, gg, bb; cin >> rr >> gg >> bb;
            r += rr; g += gg; b += bb;
        }
        
        cout << r/10+(r%10>=5) << ' ' << g/10+(g%10>=5) << ' ' << b/10+(b%10>=5) << '\n';
    }
    
    return 0;
}