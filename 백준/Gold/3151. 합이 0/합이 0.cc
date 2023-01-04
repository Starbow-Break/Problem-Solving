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
    
    vector<int> arr;
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        arr.push_back(v);
    }
    sort(arr.begin(), arr.end());
    
    ll ans = 0;
    for(int i = N-1; i >= 2; i--) {
        int l = 0; int r = i-1;
        
        ll cur = 0;
        while(l < r) {
            if(arr[l]+arr[r] > -arr[i]) r--;
            else if(arr[l]+arr[r] < -arr[i]) l++;
            else {
                int a = 0; int b = 0;
                int L = arr[l]; int R = arr[r];
                
                if(L == R) {
                    cur += 1LL*(r-l+1)*(r-l)/2;
                    break;
                }
                else {
                    while(arr[l] == L) { a++; l++; }
                    while(arr[r] == R) { b++; r--; }
                    cur += 1LL*a*b;
                }
            }
        }
        
        ans += cur;
    }
    
    cout << ans;

    return 0;
}