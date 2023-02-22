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
    
    int T; cin >> T;
    while(T--) {
        int A, B, C, D, E; cin >> A >> B >> C >> D >> E;
        
        cout << fixed << setprecision(2) << "$" 
            << 350.34*A+230.90*B+190.55*C+125.30*D+180.90*E << '\n';
    }
    
    return 0;
}