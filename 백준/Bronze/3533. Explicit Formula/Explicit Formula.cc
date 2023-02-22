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

map<string, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    bool arr[10];
    for(int i = 0; i < 10; i++) cin >> arr[i];
    
    bool ans = false;
    for(int i = 0; i < 10; i++) {
        for(int j = i+1; j < 10; j++) {
            if(arr[i] || arr[j]) ans = !ans;
        }
    }
    
    for(int i = 0; i < 10; i++) {
        for(int j = i+1; j < 10; j++) {
            for(int k = j+1; k < 10; k++) {
                if(arr[i] || arr[j] || arr[k]) ans = !ans;
            }
        }
    }
    
    cout << ans;

    return 0;
}