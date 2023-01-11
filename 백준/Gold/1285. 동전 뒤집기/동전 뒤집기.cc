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

char arr[20][21];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) { cin >> arr[i]; }
    
    int ans = N*N;
    for(int state = 0; state < (1<<N); state++) {
        int cur = 0;
        for(int c = 0; c < N; c++) {
            int curT = 0;
            for(int r = 0; r < N; r++) {
                if(((state & (1<<r)) != 0)^(arr[r][c] == 'T')) curT++;
            }
            
            cur += min(N-curT, curT);
        }
        
        ans = min(ans, cur);
    }
    
    cout << ans;

    return 0;
}