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
#define MAX 3000

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        if(N%4 == 2) { cout << "IMPOSSIBLE" << '\n'; continue; }
        
        int ans = 1'000'000'000;
        for(int a = 1; a*a <= N; a++) {
            if(N%a == 0 && (N/a+a)%2 == 0 && (N/a-a)%2 == 0) {
                ans = min(ans, (N/a-a)/2);
            }
        }
        
        cout << ans << ' ' << (int)round(sqrt(N+1LL*ans*ans)) << '\n';
    }

    return 0;
}