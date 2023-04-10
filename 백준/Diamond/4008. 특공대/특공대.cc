#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
#define MAX_N 1'000'000
#define INF 1'000'000'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int n, a, b, c; 
int s[MAX_N+1]; ll dp[MAX_N+1];
pll arr[MAX_N+1];

ll f(int x) {
    return 1LL*a*x*x+1LL*b*x+c;
}

pll getLine(int i) {
    return {-2LL*a*s[i], dp[i]+1LL*a*s[i]*s[i]-1LL*b*s[i]};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0] = 0; s[0] = 0;
    
    cin >> n >> a >> b >> c;
    for(int i = 1; i <= n; i++) {
        int v; cin >> v;
        s[i] = s[i-1]+v;
    }
    
    int back = -1; int pt = -1;
    for(int i = 1; i <= n; i++) {
        pll curf = getLine(i-1);
        while(back != -1) {
            pll t = arr[back];
            pll tf = getLine(t.first);
            
            ll x = (curf.second-tf.second)/(tf.first-curf.first)
                +((curf.second-tf.second)%(tf.first-curf.first) != 0);
                
            if(t.second < x) {
                back++; arr[back] = {i-1, x};
                break;
            }
            else {
                back--;
                if(back < pt) pt--;
            }
        }
        
        if(back == -1) {
            back++; arr[back] = {i-1, -INF};
        }
        
        while(pt < back) {
            if(s[i] >= arr[pt+1].second) pt++;
            else break;
        }
        
        pll l = getLine(arr[pt].first);
        dp[i] = l.first*s[i]+l.second+f(s[i]);
    }
    
    cout << dp[n];
    
    return 0;
}