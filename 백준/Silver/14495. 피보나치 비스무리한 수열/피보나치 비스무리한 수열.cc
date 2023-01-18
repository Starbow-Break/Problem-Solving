#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

ll f[117];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    
    f[1] = f[2] = f[3] = 1;
    for(int i = 4; i <= n; i++) {
        f[i] = f[i-1]+f[i-3];
    }
    
    cout << f[n];
    
    return 0;
}