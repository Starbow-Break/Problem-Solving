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
    
    int S[1001]; S[0] = 0;
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        for(int i = 1; i <= N; i++) {
            cin >> S[i]; S[i] += S[i-1];
        }
        
        int ans = S[1];
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j < i; j++) {
                ans = max(ans, S[i]-S[j]);
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}