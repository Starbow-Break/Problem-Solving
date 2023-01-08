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
    
    int N; cin >> N;
    
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int A = i;
        while(A > 0) {
            if(A%10 == 3 || A%10 == 6 || A%10 == 9) ans++;
            A /= 10;
        }
    }
    
    cout << ans;

    return 0;
}