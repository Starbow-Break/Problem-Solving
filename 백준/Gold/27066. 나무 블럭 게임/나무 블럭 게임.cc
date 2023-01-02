#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
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
    int arr[N+1];
    for(int i = 1; i <= N; i++) { cin >> arr[i]; }
    
    sort(arr+1, arr+N+1);
    
    if(N == 1) { cout << arr[1]; }
    else if(N == 2) { cout << (double)(arr[1]+arr[2])/2; }
    else {
        double ans = 0;
        for(int j = (N+1)/2; j < N; j++) {
            ans = max(ans, (double)arr[j]);
        }
        
        double t = 0;
        for(int j = 1; j <= N; j++) t += arr[j];
        t /= N;
        
        ans = max(ans, t);
        
        cout << fixed << setprecision(12);
        cout << ans;
    }

    return 0;
}