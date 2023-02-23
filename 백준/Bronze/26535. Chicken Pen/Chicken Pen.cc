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
    int k;
    for(k = 0; k <= 1000000; k++) {
        if(k*k >= N) break;
    }
    
    for(int i = 0; i <= k+1; i++) {
        for(int j = 0; j <= k+1; j++) {
            if(i == 0 || i == k+1 || j == 0 || j == k+1) cout << 'x';
            else cout << '.';
        }
        cout << '\n';
    }
    
    return 0;
}