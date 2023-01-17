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
    int sour[10], bitter[10];
    
    for(int i = 0; i < N; i++) { cin >> sour[i] >> bitter[i]; }
    
    int ans = 2e9;
    for(int state = 1; state < (1<<N); state++) {
        int s = 1; int b = 0;
        for(int j = 0; j < N; j++) {
            if(state & (1<<j)) {
                s *= sour[j]; b += bitter[j];
            }
        }
        
        ans = min(ans, abs(s-b));
    }
    
    cout << ans;

    return 0;
}