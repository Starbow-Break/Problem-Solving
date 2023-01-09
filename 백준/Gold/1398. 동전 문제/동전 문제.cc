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
        ll N; cin >> N;
        
        int ans = 0;
        while(N > 0) {
            int n = N%100; int cur = 1000;
            int cnt = 0;
            
            while(n >= 0) {
                cur = min(cur, cnt+n/10+n%10);
                cnt++; n -= 25;
            }
            
            ans += cur; N /= 100;
        }
        
        cout << ans << '\n';
    }

    return 0;
}