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
    
    int arr[6]; bool check;
    while(1) {
        check = false;
        
        for(int i = 0; i < 6; i++) {
            cin >> arr[i]; check = check || (arr[i] != 0);
        }
        
        if(!check) break;
        
        sort(arr, arr+6);
        
        cout << (double)(arr[1]+arr[2]+arr[3]+arr[4])/4 << '\n';
    }
    
    return 0;
}