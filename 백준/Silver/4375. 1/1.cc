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
    
    int mod;
    while(cin >> mod) {
        int a = 1; int ans = 1;
        while(a%mod) {
            ans++;
            a *= 10; a++; a %= mod;
        }
        
        cout << ans << '\n';
    }

    return 0;
}
