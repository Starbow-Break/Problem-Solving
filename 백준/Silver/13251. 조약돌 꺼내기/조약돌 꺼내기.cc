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
    
    int cnt[51] = {0, };
    
    int M; cin >> M; int N = 0;
    for(int i = 1; i <= M; i++) {
        cin >> cnt[i]; N += cnt[i];
    }
    
    int K; cin >> K;
    double ans = 0;
    for(int i = 1; i <= M; i++) {
        double temp = 1;
        
        if(K <= cnt[i]) {
            for(int k = 0; k < K; k++) {
                temp *= (double)(cnt[i]-k)/(N-k);
            }
            
            ans += temp;
        }
    }
    
    cout << fixed << setprecision(15) << ans;

    return 0;
}