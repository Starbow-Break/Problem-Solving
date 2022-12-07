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
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int A[15];

bool check(int state) {
    int cnt = 0;
    
    for(int j = 0; j < 15; j++) {
        cnt += ((1<<j) & state);
    }
    
    return (cnt >= 2);
}

int solve(int N, int L, int R, int X) {
    int ret = 0;
    
    for(int state = 1; state < (1<<N); state++) {
        if(check(state)) {
            int sum = 0; int minV = 100000000; int maxV = 0;
            for(int j = 0; j < N; j++) {
                if((1<<j) & state) {
                    sum += A[j];
                    minV = min(minV, A[j]); maxV = max(maxV, A[j]);
                }
            }
            
            if(L <= sum && sum <= R && maxV-minV >= X) ret++;
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, L, R, X; cin >> N >> L >> R >> X;
    for(int i = 0; i < N; i++) { cin >> A[i]; }
    
    cout << solve(N, L, R, X);

    return 0;
}