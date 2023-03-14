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
    
    string s; cin >> s;
    
    int arr[3];
    arr[0] = (s[0]-'0')*10+(s[1]-'0');
    arr[1] = (s[3]-'0')*10+(s[4]-'0');
    arr[2] = (s[6]-'0')*10+(s[7]-'0');
    
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j) continue;
            for(int k = 0; k < 3; k++) {
                if(i == k || j == k) continue;
                if(1 <= arr[i] && arr[i] <= 12 && 0 <= arr[j] && arr[j] <= 59
                    && 0 <= arr[k] && arr[k] <= 59) ans++;
            }
        }
    }

    cout << ans;

    return 0;
}