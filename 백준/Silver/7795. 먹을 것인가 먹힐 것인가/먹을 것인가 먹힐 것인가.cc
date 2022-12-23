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

int A[20000], B[20000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        
        for(int i = 0; i < N; i++) { cin >> A[i]; }
        for(int i = 0; i < M; i++) { cin >> B[i]; }
        
        sort(A, A+N); sort(B, B+M);
        
        int j = M-1; ll ans = 0;
        for(int i = N-1; i >= 0; i--) {
            while(j >= 0 && A[i] <= B[j]) { j--; }
            ans += (j+1);
        }
        
        cout << ans << '\n';
    }

    return 0;
}