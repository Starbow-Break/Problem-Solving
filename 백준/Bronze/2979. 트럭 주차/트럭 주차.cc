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
    
    int cnt[100] = {0, };
    int cost[4] = {0, }; for(int i = 1; i <= 3; i++) { cin >> cost[i]; cost[i] *= i; }
    
    for(int i = 0; i < 3; i++) {
        int s, f; cin >> s >> f;
        for(int j = s; j < f; j++) cnt[j]++;
    }
    
    int ans = 0;
    for(int i = 0; i < 100; i++) {
        ans += cost[cnt[i]];
    }
    
    cout << ans;

    return 0;
}