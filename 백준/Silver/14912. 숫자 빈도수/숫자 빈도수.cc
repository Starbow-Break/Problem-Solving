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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, d; cin >> N >> d;
    
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int x = i;
        while(x > 0) {
            if(x%10 == d) ans++;
            x /= 10;
        }
    }
    
    cout << ans;
    
    return 0;
}