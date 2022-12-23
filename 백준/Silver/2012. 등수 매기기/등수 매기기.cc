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
    
    int N; cin >> N;
    int arr[N+1];
    
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    sort(arr+1, arr+N+1);
    
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += abs(arr[i]-i);
    }
    
    cout << ans;
    
    return 0;
}