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
    
    int N, T; cin >> N >> T;
    T %= 2*(2*N-1);
    
    if(T == 0) cout << 2;
    else {
        int ans = 1; int del = 1; T--;
        while(T--) {
            if(ans == 2*N) del = -1;
            if(ans == 1) del = 1;
            
            ans += del;
        }
        
        cout << ans;
    }

    return 0;
}