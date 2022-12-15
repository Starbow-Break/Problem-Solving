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
    
    int N; cin >> N;
    ll ans = 0;
    
    ans++;
    for(int i = 2; i <= min(N, 100000); i++) {
        ans += 1LL*i*((N-1)/(i-1)-(N-1)/i);
    }
    
    for(int i = 1; i <= N; i++) {
        if((N-1)/i < 100000) break;
        ans += (N-1)/i+1;
    }
    
    cout << ans;

    return 0;
}