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

string arr[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int cur = 1;
            for(int k = arr[i].length()-1; k >= 0; k--) {
                if(arr[i][k] != arr[j][k]) break;
                cur++;
            }
            
            ans = max(ans, cur);
        }
    }
    
    cout << ans;

    return 0;
}