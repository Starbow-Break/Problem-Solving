#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    
    int ans = 0;
    
    while(n >= 10) {
        int cur = 1;
        
        int a = n;
        while(a > 0) {
            cur *= (a%10);
            a /= 10;
        }
        
        n = cur; ans++;
    }
    
    cout << ans;
    
    return 0;
}