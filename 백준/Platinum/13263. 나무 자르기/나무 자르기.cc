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
#define MAX_N 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll dp[MAX_N+1] = {0, };
ll A[MAX_N+1], B[MAX_N+1];
pll func[MAX_N+1];
pll arr[MAX_N+1]; int i = 0; int j = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++) cin >> B[i];
    
    func[1] = {B[1], dp[1]}; arr[0] = {0, 1};
    
    for(int k = 2; k <= N; k++) {
        int a = i, b = j;
        while(a <= b) {
            int mid = (a+b)>>1;
            if(arr[mid].first <= A[k]) a = mid+1;
            else b = mid-1;
        }
        
        dp[k] = func[arr[b].second].first*A[k]+func[arr[b].second].second;
        
        a = i; b = j;
        while(a <= b) {
            int mid = (a+b)>>1;
            
            ll x = (dp[k]-func[arr[mid].second].second)/(func[arr[mid].second].first-B[k])
                +((dp[k]-func[arr[mid].second].second)%(func[arr[mid].second].first-B[k]) > 0);
            
            if(x > arr[mid].first) a = mid+1;
            else b = mid-1;
        }
        
        j = b+1;
        ll x = (dp[k]-func[arr[b].second].second)/(func[arr[b].second].first-B[k])
            +((dp[k]-func[arr[b].second].second)%(func[arr[b].second].first-B[k]) > 0);
        func[k] = {B[k], dp[k]}, arr[j] = {x, k};
    }

    cout << dp[N];

    return 0;
}