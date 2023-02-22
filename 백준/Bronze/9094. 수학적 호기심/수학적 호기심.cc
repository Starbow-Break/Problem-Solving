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
        int cnt = 0;
        int n, m; cin >> n >> m;
        for(int a = 1; a < n; a++) {
            for(int b = a+1; b < n; b++) {
                cnt += (a*a+b*b+m)%(a*b) == 0;
            }
        }
        
        cout << cnt << '\n';
    }

    return 0;
}