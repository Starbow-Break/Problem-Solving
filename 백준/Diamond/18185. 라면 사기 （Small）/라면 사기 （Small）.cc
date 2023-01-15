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

int N; int A[10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) { cin >> A[i]; }
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == 0) continue;
        
        if(i+2 < N && A[i+1] > 0 && A[i+2] > 0) {
            if(A[i+1] > A[i+2]) {
                int v = min(A[i], A[i+1]-A[i+2]);
                ans += 5*v; A[i] -= v; A[i+1] -= v;
                
                v = min(A[i], A[i+1]);
                ans += 7*v; A[i] -= v; A[i+1] -= v; A[i+2] -= v;
            }
            else {
                int v = min(A[i], A[i+1]);
                ans += 7*v; A[i] -= v; A[i+1] -= v; A[i+2] -= v;
            }
        }
        else if(i+1 < N) {
            int v = min(A[i], A[i+1]);
            ans += 5*v; A[i] -= v; A[i+1] -= v;
        }
        
        if(A[i] > 0) { ans += 3*A[i]; A[i] = 0;}
    }
    
    cout << ans;

    return 0;
}