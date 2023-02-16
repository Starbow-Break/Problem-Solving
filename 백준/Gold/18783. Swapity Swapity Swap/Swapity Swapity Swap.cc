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

int N, M, K;
int arr[30][MAX_N+1], ans[MAX_N+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) { arr[0][i] = i; ans[i] = i; }
    
    while(M--) {
        int L, R; cin >> L >> R;
        reverse(arr[0]+L, arr[0]+R+1);
    }
    
    for(int i = 1; i < 30; i++) {
        for(int j = 1; j <= N; j++) {
            arr[i][j] = arr[i-1][arr[i-1][j]];
        }
    }
    
    int idx = 0;
    while(K > 0) {
        if(K%2) {
            for(int i = 1; i <= N; i++) {
                ans[i] = arr[idx][ans[i]];
            }
        }
        
        K /= 2; idx++;
    }
    
    for(int i = 1; i <= N; i++) { cout << ans[i] << '\n'; }

    return 0;
}