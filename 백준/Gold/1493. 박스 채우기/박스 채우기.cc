#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll boxVolume; ll _fill = 0;
ll cnt[20] = {0, };
ll posCnt[20] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int l, w, h; cin >> l >> w >> h;
    boxVolume = 1LL*l*w*h;
    
    int n; cin >> n;
    while(n--) {
        int a, b; cin >> a >> b;
        cnt[a] += b;
    }
    
    for(int i = 0; i < 20; i++) {
        posCnt[i] = 1LL*(l/(1<<i))*(w/(1<<i))*(h/(1<<i));
    }
    
    ll ans = 0;
    for(int i = 19; i >= 0; i--) {
        ll oneV = 1LL*(1<<i)*(1<<i)*(1<<i);
        
        ll A = cnt[i]; ll B = posCnt[i]-_fill/oneV;
        _fill += oneV*min(A, B); ans += min(A, B);
    }
    
    cout << ((boxVolume == _fill) ? ans : -1);

    return 0;
}