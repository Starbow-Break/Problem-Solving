#include <iostream>
#include <cstring>
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
    
    int N; cin >> N; int ans = 0;
    for(int a = 3; a <= N; a += 3) {
        for(int b = 3; b <= N; b += 3) {
            ans += (a+b < N);
        }
    }
    
    cout << ans;

    return 0;
}