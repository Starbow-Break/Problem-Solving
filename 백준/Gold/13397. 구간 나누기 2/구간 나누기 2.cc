#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 10007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, M;
int A[5000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) { cin >> A[i]; }
    
    int l = 0; int r = 9999;
    while(l <= r) {
        int mid = (l+r)>>1;
        int cnt = 1;
        
        int minV = A[0]; int maxV = A[0];
        for(int i = 1; i < N; i++) {
            minV = min(minV, A[i]); maxV = max(maxV, A[i]);
            
            if(maxV-minV > mid) {
                cnt++;
                minV = A[i]; maxV = A[i];
            }
        }
        
        if(cnt > M) l = mid+1;
        else r = mid-1;
    }
    
    cout << l;

    return 0;
}