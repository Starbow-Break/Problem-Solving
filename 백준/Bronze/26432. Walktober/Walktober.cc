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

int arr[1001][32];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        int M, N, P; cin >> M >> N >> P;
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) cin >> arr[i][j];
        }
        
        int ans = 0;
        for(int i = 1; i <= N; i++) {
            int del = 0;
            for(int j = 1; j <= M; j++) {
                del = max(del, arr[j][i]-arr[P][i]);
            }
            
            ans += del;
        }
        
        cout << "Case #" << t << ": " << ans << '\n';
    }
    
    return 0;
}