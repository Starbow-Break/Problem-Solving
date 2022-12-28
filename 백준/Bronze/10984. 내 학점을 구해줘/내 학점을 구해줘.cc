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
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        double a, b; a = b = 0;
        while(N--) {
            double aa, bb; cin >> aa >> bb;
            a += aa; b += bb*aa;
        }
        
        cout << a << " " << b/a << '\n';
    }

    return 0;
}