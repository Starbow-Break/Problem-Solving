#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N; ll M;
int prime[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) { cin >> prime[i]; }
    
    ll ans = 0;
    for(int state = 1; state < (1<<N); state++) {
        int cnt = 0; ll prod = 1;
        for(int i = 0; i < N; i++) {
            if(state & (1<<i)) {
                cnt++; prod *= prime[i];
            }
        }
        
        if(cnt%2) ans += M/prod;
        else ans -= M/prod;
    }
    
    cout << ans;

    return 0;
}