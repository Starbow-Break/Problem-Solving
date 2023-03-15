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
    
    int T; cin >> T;
    while(T--) {
        int arr[5], brr[4];
        int w[5] = {8, 8, 4, 1, 9};
        int ww[4] = {1, 30, 25, 10};
        for(int i = 0; i < 5; i++) cin >> arr[i];
        for(int i = 0; i < 4; i++) cin >> brr[i];
        
        int x = 1'000'000'000;
        for(int i = 0; i < 5; i++) x = min(x, 16*arr[i]/w[i]);
        
        int y = 0;
        for(int i = 0; i < 4; i++) y += brr[i]/ww[i];
        
        cout << min(x, y) << '\n';
    }

    return 0;
}