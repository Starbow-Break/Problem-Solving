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

int K[10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N; K[0] = 0;
    for(int i = 1; i <= N; i++) { cin >> K[i]; K[i] += K[i-1]; }
    
    ll ans = 0;
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j++) {
            if(K[j]-K[i-1] < 0)
                ans += (K[i-1]-K[j])/K[N]+((K[i-1]-K[j])%K[N] != 0);
            if(K[N]-(K[j]-K[i-1]) < 0)
                ans += ((K[j]-K[i-1])-K[N])/K[N]+(((K[j]-K[i-1])-K[N])%K[N] != 0);
        }
    }
    
    cout << ans;

    return 0;
}