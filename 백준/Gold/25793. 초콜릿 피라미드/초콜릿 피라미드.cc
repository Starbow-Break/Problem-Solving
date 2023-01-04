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
        int R, C; cin >> R >> C;
        int k = min(R, C);
        
        ll white = 0; ll dark = 0;
        white += 2LL*R*C*k;
        white -= 1LL*k*(k-1)*(R+C);
        white += 1LL*(k-1)*k*(2*k-1)/3;
        white -= 1LL*R*C;
        
        dark = white; dark += 1LL*R*C;
        dark -= 1LL*k*(R+C);
        dark += (k-1)*k;
        
        cout << white << " " << dark << '\n';
    }

    return 0;
}