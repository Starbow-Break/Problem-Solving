#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll A[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    
    int check = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i]; check += A[i]; check %= K;
    }
    
    if(check) cout << "blobsad";
    else {
        ll ans = 0;
        int i = 0; int j = 1;
        while(j < N) {
            while(j < N && A[j]%K == 0) { j++; }
            if(j >= N) break;
            
            if(A[i] < 0) {
                int pushCnt = -A[i];
                ans += 1LL*pushCnt*(j-i);
                A[i] += pushCnt; A[j] -= pushCnt;
                i = j; j = i+1;
                continue;
            }
            
            int popCnt = A[i]%K;
            int pushCnt = (K-popCnt)%K;
            
            if(popCnt < pushCnt) {
                ans += 1LL*popCnt*(j-i);
                A[i] -= popCnt;
                A[j] += popCnt;
            }
            else {
                ans += 1LL*pushCnt*(j-i);
                A[i] += pushCnt;
                A[j] -= pushCnt;
            }
            
            i = j; j = i+1;
        }
        
        cout << ans;
    }
    
    return 0;
}